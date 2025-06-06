/* See LICENSE file for copyright and license details. */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/utf.h"
#include "../../include/util.h"

/* tokens, one-character operators represent themselves */
enum { VAL = CHAR_MAX + 1, GE, LE, NE };

struct val {
  char *str;
  long long num;
};

static void tonum(struct val *v) {
  const char *errstr;
  long long d;

  /* check if val is the result of an earlier calculation */
  if (!v->str)
    return;

  d = strtonum(v->str, LLONG_MIN, LLONG_MAX, &errstr);
  if (errstr)
    enprintf(2, "error: expected integer, got %s\n", v->str);
  v->num = d;
}

static void ezero(struct val *v) {
  if (v->num != 0)
    return;
  enprintf(2, "division by zero\n");
}

static int valcmp(struct val *a, struct val *b) {
  int ret;
  const char *err1, *err2;
  long long d1, d2;

  d1 = strtonum(a->str, LLONG_MIN, LLONG_MAX, &err1);
  d2 = strtonum(b->str, LLONG_MIN, LLONG_MAX, &err2);

  if (!err1 && !err2) {
    ret = (d1 > d2) - (d1 < d2);
  } else {
    ret = strcmp(a->str, b->str);
  }

  return ret;
}

static void match(struct val *vstr, struct val *vregx, struct val *ret) {
  regex_t re;
  regmatch_t matches[2];
  size_t anchlen;
  char *s, *p, *anchreg;
  char *str = vstr->str, *regx = vregx->str;

  /* anchored regex */
  anchlen = strlen(regx) + 1 + 1;
  anchreg = emalloc(anchlen);
  estrlcpy(anchreg, "^", anchlen);
  estrlcat(anchreg, regx, anchlen);
  enregcomp(3, &re, anchreg, 0);
  free(anchreg);

  if (regexec(&re, str, 2, matches, 0)) {
    regfree(&re);
    ret->str = re.re_nsub ? "" : NULL;
    return;
  } else if (re.re_nsub) {
    regfree(&re);

    s = str + matches[1].rm_so;
    p = str + matches[1].rm_eo;
    *p = '\0';
    ret->str = enstrdup(3, s);
    return;
  } else {
    regfree(&re);
    str += matches[0].rm_so;
    ret->num = utfnlen(str, matches[0].rm_eo - matches[0].rm_so);
    return;
  }
}

static void doop(int *ophead, int *opp, struct val *valhead, struct val *valp) {
  struct val ret = {.str = NULL, .num = 0}, *a, *b;
  int op;

  /* an operation "a op b" needs an operator and two values */
  if (opp[-1] == '(')
    enprintf(2, "syntax error: extra (\n");
  if (valp - valhead < 2)
    enprintf(2, "syntax error: missing expression or extra operator\n");

  a = valp - 2;
  b = valp - 1;
  op = opp[-1];

  switch (op) {
  case '|':
    if (a->str && *a->str)
      ret.str = a->str;
    else if (!a->str && a->num)
      ret.num = a->num;
    else if (b->str && *b->str)
      ret.str = b->str;
    else
      ret.num = b->num;
    break;
  case '&':
    if (((a->str && *a->str) || a->num) && ((b->str && *b->str) || b->num)) {
      ret.str = a->str;
      ret.num = a->num;
    }
    break;

  case '=':
    ret.num = (valcmp(a, b) == 0);
    break;
  case '>':
    ret.num = (valcmp(a, b) > 0);
    break;
  case GE:
    ret.num = (valcmp(a, b) >= 0);
    break;
  case '<':
    ret.num = (valcmp(a, b) < 0);
    break;
  case LE:
    ret.num = (valcmp(a, b) <= 0);
    break;
  case NE:
    ret.num = (valcmp(a, b) != 0);
    break;

  case '+':
    tonum(a);
    tonum(b);
    ret.num = a->num + b->num;
    break;
  case '-':
    tonum(a);
    tonum(b);
    ret.num = a->num - b->num;
    break;
  case '*':
    tonum(a);
    tonum(b);
    ret.num = a->num * b->num;
    break;
  case '/':
    tonum(a);
    tonum(b);
    ezero(b);
    ret.num = a->num / b->num;
    break;
  case '%':
    tonum(a);
    tonum(b);
    ezero(b);
    ret.num = a->num % b->num;
    break;

  case ':':
    match(a, b, &ret);
    break;
  }

  valp[-2] = ret;
}

static int lex(char *s, struct val *v) {
  int type = VAL;
  char *ops = "|&=><+-*/%():";

  if (s[0] && strchr(ops, s[0]) && !s[1]) {
    /* one-char operand */
    type = s[0];
  } else if (s[0] && strchr("><!", s[0]) && s[1] == '=' && !s[2]) {
    /* two-char operand */
    type = (s[0] == '>') ? GE : (s[0] == '<') ? LE : NE;
  }

  return type;
}

static int parse(char *expr[], int numexpr) {
  struct val *valhead, *valp, v = {.str = NULL, .num = 0};
  int *ophead, *opp, type, lasttype = 0;
  char prec[] = {
      [0] = 0,   [VAL] = 0, ['('] = 0, [')'] = 0, ['|'] = 1, ['&'] = 2,
      ['='] = 3, ['>'] = 3, [GE] = 3,  ['<'] = 3, [LE] = 3,  [NE] = 3,
      ['+'] = 4, ['-'] = 4, ['*'] = 5, ['/'] = 5, ['%'] = 5, [':'] = 6,
  };

  valp = valhead = enreallocarray(3, NULL, numexpr, sizeof(*valp));
  opp = ophead = enreallocarray(3, NULL, numexpr, sizeof(*opp));
  for (; *expr; expr++) {
    switch ((type = lex(*expr, &v))) {
    case VAL:
      /* treatment of *expr is not known until
       * doop(); treat as a string for now */
      valp->str = *expr;
      valp++;
      break;
    case '(':
      *opp++ = type;
      break;
    case ')':
      if (lasttype == '(')
        enprintf(2, "syntax error: empty ( )\n");
      while (opp > ophead && opp[-1] != '(')
        doop(ophead, opp--, valhead, valp--);
      if (opp == ophead)
        enprintf(2, "syntax error: extra )\n");
      opp--;
      break;
    default: /* operator */
      if (prec[lasttype])
        enprintf(2, "syntax error: extra operator\n");
      while (opp > ophead && prec[opp[-1]] >= prec[type])
        doop(ophead, opp--, valhead, valp--);
      *opp++ = type;
      break;
    }
    lasttype = type;
    v.str = NULL;
    v.num = 0;
  }
  while (opp > ophead)
    doop(ophead, opp--, valhead, valp--);
  if (valp == valhead)
    enprintf(2, "syntax error: missing expression\n");
  if (--valp > valhead)
    enprintf(2, "syntax error: extra expression\n");

  if (valp->str)
    puts(valp->str);
  else
    printf("%lld\n", valp->num);

  return (valp->str && *valp->str) || valp->num;
}

int expr_main(int argc, char *argv[]) {
  int ret;

  argv0 = *argv, argv0 ? (argc--, argv++) : (void *)0;

  ret = !parse(argv, argc);

  if (fshut(stdout, "<stdout>"))
    ret = 3;

  return ret;
}
