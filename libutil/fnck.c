/* See LICENSE file for copyright and license details. */
#include <sys/stat.h>

#include "../include/util.h"

void fnck(const char *a, const char *b,
          int (*fn)(const char *, const char *, int), int depth) {
  struct stat sta, stb;

  if (!stat(a, &sta) && !stat(b, &stb) && sta.st_dev == stb.st_dev &&
      sta.st_ino == stb.st_ino) {
    weprintf("%s -> %s: same file\n", a, b);
    return;
  }

  if (fn(a, b, depth) < 0)
    eprintf("%s -> %s:", a, b);
}
