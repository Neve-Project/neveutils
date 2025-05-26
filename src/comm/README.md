COMM(1) - General Commands Manual

# NAME

**comm** - select or reject lines common to two files

# SYNOPSIS

**comm**
\[**-123**]
*file1*
*file2*

# DESCRIPTION

**comm**
reads
*file1*
and
*file2,*
which should both be sorted lexically, and writes three text columns
to stdout:

1

> Lines only in
> *file1*.

2

> Lines only in
> *file2*.

3

> Common lines.

# OPTIONS

**-1** | **-2** | **-3**

> Suppress column 1 | 2 | 3

# SEE ALSO

cmp(1),
sort(1),
uniq(1)

# STANDARDS

The
**comm**
utility is compliant with the
specification.

neveutils - May 26, 2025
