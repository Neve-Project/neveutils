CHMOD(1) - General Commands Manual

# NAME

**chmod** - change file modes

# SYNOPSIS

**chmod**
\[**-R**]
*mode*
*file&nbsp;...*

# DESCRIPTION

**chmod**
changes the file mode of each
*file*
to
*mode*.

If
*mode*
is
*octal*
"\[sog]e"

s

> sticky(1) =&gt; s += 1

> setgid(2) =&gt; s += 2

> setuid(4) =&gt; s += 4

o|g|e

> owner | group | everyone

> execute(1) =&gt; o|g|e += 1

> write(2) =&gt; o|g|e += 2

> read(4) =&gt; o|g|e += 4

Leading zeroes may be omitted.

If
*mode*
is
*symbolic*
"\[ugoa]\*\[+-=]\[rwxXst]\*"

u|g|o|a

> owner | group | other (non-group) | everyone

\+|-|=

> add | remove | set

r|w|x|s|t

> read | write | execute | setuid and setgid | sticky

X

> execute, if directory or at least one execute bit is already set

Symbolic links are followed if they are passed as operands, and ignored
if they are encountered during directory traversal.

# OPTIONS

**-R**

> Change modes recursively.

# SEE ALSO

chgrp(1),
umask(1)

# STANDARDS

The
**chmod**
utility is compliant with the
specification.

The
\[**-HLP**]
flags are an extension to that specification.

sbase - December 21, 2019
