EXPAND(1) - General Commands Manual

# NAME

**expand** - expand tabs to spaces

# SYNOPSIS

**expand**
\[**-i**]
\[**-t**&nbsp;*tablist*]
\[*file&nbsp;...*]

# DESCRIPTION

**expand**
converts tabs to spaces in each
*file*
as specified in
*tablist*.
If no file is given,
**expand**
reads from stdin.

Backspace characters are preserved and decrement the column count
for tab calculations.

# OPTIONS

**-i**

> Only expand tabs at the beginning of lines, i.e. expand each
> line until a character different from '&#92;t' and ' ' is reached.

**-t** *tablist*

> Specify tab size or tabstops.
> *tablist*
> is a list of one (in the former case) or multiple (in the latter case)
> strictly positive integers separated by ' ' or ','.

> The default
> *tablist*
> is "8".

# SEE ALSO

fold(1),
unexpand(1)

# STANDARDS

The
**expand**
utility is compliant with the
specification.

The
\[**-i**]
flag is an extension to that specification.

neveutils - May 26, 2025
