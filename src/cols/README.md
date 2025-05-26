COLS(1) - General Commands Manual

# NAME

**cols** - columnize output

# SYNOPSIS

**cols**
\[**-c**&nbsp;*num*]
\[*file&nbsp;...*]

# DESCRIPTION

**cols**
reads each
*file*
in sequence and writes them to stdout, in as many vertical
columns as will fit in
*num*
character columns.
If no
*file*
is given,
**cols**
reads from stdin.

By default
**cols**
tries to figure out the width of the output device.
If that fails, it defaults to 65 chars.

# OPTIONS

**-c** *num*

> Set maximum number of character columns to
> *num*,
> unless input lines exceed this limit.

# ENVIRONMENT

COLUMNS

> The width of the output device.

# HISTORY

**cols**
is similar to
mc(1)
in Plan 9. It was renamed to
**cols**
to avoid the name collision with the popular file manager
Midnight Commander.

# CAVEATS

This implementation of
**cols**
assumes that each UTF-8 code point occupies one character cell,
and thus mishandles TAB characters (among others).

**cols**
currently mangles files which contain embedded NULs.

neveutils - May 26, 2025
