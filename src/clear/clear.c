/* See LICENSE file for copyright and license details. */
#include <stdio.h>

#include "../../include/util.h"

static void
usage(void)
{
	eprintf("usage: %s\n", argv0);
}

int
clear_main(int argc, char *argv[])
{
	argv0 = argv[0], argc--, argv++;

	if (argc)
		usage();

	printf("\x1b[2J\x1b[H");

	return 0;
}
