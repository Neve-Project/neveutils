DD(1) - General Commands Manual

# NAME

**dd** - convert and copy a file

# SYNOPSIS

**dd**
\[*operand*...]

# DESCRIPTION

**dd**
copies its input to its output, possibly after conversion, using
the specified block sizes,

The following operands are available:

**if=**&zwnj;*file*

> Read from the file named by
> *file*
> instead of standard input.

**of=**&zwnj;*file*

> Write to the file named by
> *file*
> instead of standard output.

**ibs=**&zwnj;*expr*

> Set the input block size to
> *expr*
> (defaults to 512).

**obs=**&zwnj;*expr*

> Set the output block size to
> *expr*
> (defaults to 512).

**bs=**&zwnj;*expr*

> Set the input and output block sizes to
> *expr*.
> Additionally, if no conversion other than
> **noerror**,
> **notrunc**,
> or
> **sync**
> is specified, input blocks are copied as single output blocks, even
> when the input block is short.

**skip=**&zwnj;*n*

> Skip
> *n*
> input blocks before starting to copy.

**seek=**&zwnj;*n*

> Skip
> *n*
> output blocks before starting to copy.

**count=**&zwnj;*n*

> Copy at most
> *n*
> input blocks.

**conv=**&zwnj;*value*\[,*value*...]

> Apply the conversions specified by
> *value*.

> **lcase**

> > Map uppercase characters to the corresponding lowercase character
> > using
> > **tolower**().

> **ucase**

> > Map lowercase characters to the corresponding uppercase character
> > using
> > **toupper**().

> **swab**

> > Swap each pair of bytes in the input block.
> > If there is an odd number of bytes in a block, the last one is
> > unmodified.

> **noerror**

> > In case of an error reading from the input, do not fail.
> > Instead, print a diagnostic message and a summary of the current
> > status.

> **notrunc**

> > Do not truncate the output file.

> **sync**

> > In case of a partial input block, pad with null bytes to form a
> > complete block.

# STANDARDS

The
**dd**
utility is compliant with the
IEEE Std 1003.1-2008 (&#8220;POSIX.1&#8221;)
specification, except that it does not implement the
**block**
and
**unblock**
conversions.

neveutils - May 26, 2025
