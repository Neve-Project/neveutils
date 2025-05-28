HEAD(1) - General Commands Manual

# NAME

**head** - display initial lines of files

# SYNOPSIS

**head**
\[**-n**&nbsp;*num*&nbsp;|&nbsp;**-**&zwnj;*num*]
\[*file&nbsp;...*]

# DESCRIPTION

**head**
writes
*num*
lines of each
*file*
to stdout.
If no
*file*
is given
**head**
reads from stdin.

# OPTIONS

**-n** *num* | **-**&zwnj;*num*

> Display initial
> *num*
> |
> **N**
> lines.
> Default is 10.

# SEE ALSO

tail(1)

# STANDARDS

The
**head**
utility is compliant with the
specification.

The
\[**-**num]
syntax is an extension to that specification.

neveutils - May 28, 2025
