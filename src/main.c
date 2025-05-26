#include <stdio.h>
#include <string.h>

char *argv0;

extern int basename_main(int, char **);
extern int blkdiscard_main(int, char **);
extern int cal_main(int, char **);
extern int cat_main(int, char **);
extern int chgrp_main(int, char **);
extern int chmod_main(int, char **);
extern int chown_main(int, char **);
extern int chroot_main(int, char **);
extern int chvt_main(int, char **);
extern int cksum_main(int, char **);
extern int clear_main(int, char **);
extern int cmp_main(int, char **);
extern int cols_main(int, char **);
extern int comm_main(int, char **);
extern int cp_main(int, char **);
extern int cron_main(int, char **);
extern int ctrlaltdel_main(int, char **);
extern int cut_main(int, char **);
extern int date_main(int, char **);
extern int dd_main(int, char **);
extern int df_main(int, char **);
extern int dirname_main(int, char **);
extern int dmesg_main(int, char **);
extern int du_main(int, char **);
extern int whoami_main(int, char **);
extern int xinstall_main(int, char **);
extern int yes_main(int, char **);

#ifndef VERSION
#define VERSION "0.1"
#endif

struct {
  const char *name;
  int (*main)(int, char **);
} cmds[] = {
    {"basename", basename_main},
    {"blkdiscard", blkdiscard_main},
    {"cal", cal_main},
    {"cat", cat_main},
    {"chgrp", chgrp_main},
    {"chmod", chmod_main},
    {"chown", chown_main},
    {"chroot", chroot_main},
    {"chvt", chvt_main},
    {"cksum", cksum_main},
    {"clear", clear_main},
    {"cmp", cmp_main},
    {"cols", cols_main},
    {"comm", comm_main},
    {"cp", cp_main},
    {"cron", cron_main},
    {"ctrlaltdel", ctrlaltdel_main},
    {"cut", cut_main},
    {"date", date_main},
    {"dd", dd_main},
    {"df", df_main},
    {"dirname", dirname_main},
    {"dmesg", dmesg_main},
    {"du", du_main},
    {"whoami", whoami_main},
    {"xinstall", xinstall_main},
    {"yes", yes_main},
};

static void usage(void) {
  fprintf(stderr, "neveutils version %s\n", VERSION);
  fprintf(stderr, "usage: COMMAND [args...]\n");
  fprintf(stderr, "Available commands:\n");

  for (size_t i = 0; i < sizeof(cmds) / sizeof(cmds[0]); i++) {
    fprintf(stderr, "  %s\n", cmds[i].name);
  }
}

int main(int argc, char *argv[]) {
  char *prog = strrchr(argv[0], '/');
  prog = prog ? prog + 1 : argv[0];
  argv0 = prog;

  for (size_t i = 0; i < sizeof(cmds) / sizeof(cmds[0]); i++) {
    if (strcmp(prog, cmds[i].name) == 0)
      return cmds[i].main(argc, argv);
  }

  if (strcmp(prog, "neveutils") == 0 || argc == 1) {
    usage();
    return 0;
  }

  fprintf(stderr, "%s: unknown command: %s\n", argv[0], prog);
  usage();
  return 127;
}

