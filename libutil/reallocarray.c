/*
 * Copyright (c) 2008 Otto Moerbeek <otto@drijf.net>
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
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#include "../include/util.h"

/*
 * This is sqrt(SIZE_MAX+1), as s1*s2 <= SIZE_MAX
 * if both s1 < MUL_NO_OVERFLOW and s2 < MUL_NO_OVERFLOW
 */
#define MUL_NO_OVERFLOW (1UL << (sizeof(size_t) * 4))

void *reallocarray(void *optr, size_t nmemb, size_t size) {
  if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 &&
      SIZE_MAX / nmemb < size) {
    errno = ENOMEM;
    return NULL;
  }
  return realloc(optr, size * nmemb);
}

void *ereallocarray(void *optr, size_t nmemb, size_t size) {
  return enreallocarray(1, optr, nmemb, size);
}

void *enreallocarray(int status, void *optr, size_t nmemb, size_t size) {
  void *p;

  if (!(p = reallocarray(optr, nmemb, size)))
    enprintf(status, "reallocarray: out of memory\n");

  return p;
}
