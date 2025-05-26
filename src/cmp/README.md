CMP(1) - General Commands Manual

# NAME

**cmp** - compare two files

# SYNOPSIS

**cmp**
\[**-l**&nbsp;|&nbsp;**-s**]
*file1&nbsp;file2*

# DESCRIPTION

**cmp**
compares
*file1*
and
*file2*
byte by byte.
If they differ,
**cmp**
writes the first differing byte- and line-number to stdout.

# OPTIONS

**-l**

> Print byte-number and bytes (in octal) for each difference.

**-s**

> Print nothing and only return status.

# EXIT STATUS

0

> *file1*
> and
> *file2*
> are identical.

1

> *file1*
> and
> *file2*
> are different.

&gt; 1

> An error occurred.

# SEE ALSO

comm(1),
diff(1)

# STANDARDS

The
**cmp**
utility is compliant with the
specification.

The "char" in the default result format has been replaced with "byte".

sbase - October 8, 2015
