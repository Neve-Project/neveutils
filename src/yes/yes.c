#include <stdio.h>

#include "../../include/util.h"

static void usage(void) { eprintf("usage: %s [string]\n", argv0); }

int yes_main(int argc, char *argv[]) {
  const char *s;

  ARGBEGIN {
  default:
    usage();
  }
  ARGEND

  s = argc ? argv[0] : "y";
  for (;;)
    puts(s);
}
