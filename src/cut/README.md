CUT(1) - General Commands Manual

# NAME

**cut** - extract columns of data

# SYNOPSIS

**cut**
**-b**&nbsp;*list*
\[**-n**]
\[*file&nbsp;...*]  
**cut**
**-c**&nbsp;*list*
\[*file&nbsp;...*]  
**cut**
**-f**&nbsp;*list*
\[**-d**&nbsp;*delim*]
\[**-s**]
\[*file&nbsp;...*]

# DESCRIPTION

**cut**
out bytes, characters or delimited fields from each line of
*file*
and write to stdout.

If no
*file*
is given or
*file*
is '-',
**cut**
reads from stdin.

*list*
is a comma or space separated list of numbers and ranges starting
from 1.
Ranges have the form 'N-M'. If N or M is missing, beginning or end
of line is assumed.
Numbers and ranges may be repeated, overlapping and in any order.

Selected input is written in the same order it is read
and is written exactly once.

# OPTIONS

**-b** *list* | **-c** *list*

> *list*
> specifies byte | character positions.

**-d** *delim*

> Use
> *delim*
> as field delimiter, which can be an arbitrary string.
> Default is '&#92;t'.

**-f** *list*

> *list*
> specifies field numbers.
> Lines not containing field delimiters are passed through, unless
> **-s**
> is specified.

**-n**

> Do not split multibyte characters.
> A character is written when its last byte is selected.

**-s**

> Suppress lines not containing field delimiters.

# STANDARDS

The
**cut**
utility is compliant with the
specification.

The possibility of separating numbers and ranges with a space and specifying
multibyte delimiters of arbitrary length is an extension to that specification.

neveutils - May 26, 2025
