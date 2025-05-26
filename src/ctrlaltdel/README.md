CTRLALTDEL(8) - System Manager's Manual

# NAME

**ctrlaltdel** - toggle Ctrl-Alt-Del behaviour

# SYNOPSIS

**ctrlaltdel**
**-h**&nbsp;|&nbsp;**-s**

# DESCRIPTION

**ctrlaltdel**
toggles the function of Ctrl-Alt-Del based on the two choices given in
*linux/kernel/sys.c*:

hard reset

> reboot the computer immediately without calling
> sync(2).

soft reset

> send SIGINT to
> init(8).

# OPTIONS

**-h**

> Set to hard reset.

**-s**

> Set to soft reset.

# SEE ALSO

sync(2),
init(8)

neveutils - May, 26 2025
