/*	$OpenBSD: strtonum.c,v 1.7 2013/04/17 18:40:58 tedu Exp $	*/

/*
 * Copyright (c) 2004 Ted Unangst and Todd Miller
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#include "../include/util.h"

#define INVALID 1
#define TOOSMALL 2
#define TOOLARGE 3

long long strtonum(const char *numstr, long long minval, long long maxval,
                   const char **errstrp) {
  long long ll = 0;
  int error = 0;
  char *ep;
  struct errval {
    const char *errstr;
    int err;
  } ev[4] = {
      {NULL, 0},
      {"invalid", EINVAL},
      {"too small", ERANGE},
      {"too large", ERANGE},
  };

  ev[0].err = errno;
  errno = 0;
  if (minval > maxval) {
    error = INVALID;
  } else {
    ll = strtoll(numstr, &ep, 10);
    if (numstr == ep || *ep != '\0')
      error = INVALID;
    else if ((ll == LLONG_MIN && errno == ERANGE) || ll < minval)
      error = TOOSMALL;
    else if ((ll == LLONG_MAX && errno == ERANGE) || ll > maxval)
      error = TOOLARGE;
  }
  if (errstrp != NULL)
    *errstrp = ev[error].errstr;
  errno = ev[error].err;
  if (error)
    ll = 0;

  return (ll);
}

long long enstrtonum(int status, const char *numstr, long long minval,
                     long long maxval) {
  const char *errstr;
  long long ll;

  ll = strtonum(numstr, minval, maxval, &errstr);
  if (errstr)
    enprintf(status, "strtonum %s: %s\n", numstr, errstr);
  return ll;
}

long long estrtonum(const char *numstr, long long minval, long long maxval) {
  return enstrtonum(1, numstr, minval, maxval);
}
