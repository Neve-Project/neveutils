GETCONF(1) - General Commands Manual

# NAME

**getconf** - get configuration values

# SYNOPSIS

**getconf**
\[**-v**&nbsp;*spec*]
*var*
*\[path]*

# DESCRIPTION

**getconf**
writes the value of the variable
*var*
to stdout.

If
*path*
is given,
*var*
is matched against configuration values from
pathconf(3).
If
*path*
is not given,
*var*
is matched against configuration values from
sysconf(3),
confstr(3)
and limits.h (Minimum and Maximum).

If
*var*
is not defined,
**getconf**
writes "undefined" to stdout.

# OPTIONS

**-v** *spec*

> Ignored.

# EXIT STATUS

0

> *var*
> was matched and its value written successfully.

1

> An error occured or
> *var*
> was invalid.

# STANDARDS

The
**getconf**
utility is compliant with the
specification except from the
\[**-v**]
flag.

neveutils - May 28, 2025
