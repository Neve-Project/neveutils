CP(1) - General Commands Manual

# NAME

**cp** - copy files and directories

# SYNOPSIS

**cp**
\[**-afipv**]
\[**-R**
\[**-H**&nbsp;|&nbsp;**-L**&nbsp;|&nbsp;**-P**]]
*source&nbsp;...*
*dest*

# DESCRIPTION

**cp**
copies
*source*
to
*dest*.
If more than one
*source*
is given
*dest*
has to be a directory.

# OPTIONS

**-a**

> Preserve block devices, character devices, sockets and FIFOs.
> Implies
> **-p**,
> **-P**
> and
> **-R**.

**-f**

> If an existing
> *dest*
> cannot be opened, remove it and try again.

**-i**

> Interactive prompt before overwrite.

**-p**

> Preserve mode, timestamp and permissions.

**-v**

> Write "'source' -&gt; 'dest'" for each
> *source*
> to stdout.

**-H**

> Dereference
> *source*
> if it is a symbolic link.

**-L**

> Dereference all symbolic links.
> This is the default without
> **-R**.

**-P**

> Preserve symbolic links.
> This is the default with
> **-R**.

**-R**

> Traverse directories recursively.
> If this flag is not specified, directories are not copied.

# SEE ALSO

mv(1)

# STANDARDS

POSIX.1-2013.

The
\[**-av**]
flags are an extension to that specification.

neveutils - May 26, 2025
