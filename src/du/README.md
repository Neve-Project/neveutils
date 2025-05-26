DU(1) - General Commands Manual

# NAME

**du** - display disk usage statistics

# SYNOPSIS

**du**
\[**-a**&nbsp;|&nbsp;**-s**]
\[**-d**&nbsp;*depth*]
\[**-h**]
\[**-k**]
\[**-H**&nbsp;|&nbsp;**-L**&nbsp;|&nbsp;**-P**]
\[**-x**]
\[*file&nbsp;...*]

# DESCRIPTION

**du**
displays the file system block usage for each
*file*
argument and for each directory in the file hierarchy rooted in directory
argument.
If no
*file*
is specified, the block usage of the hierarchy rooted in the current directory
is displayed.

# OPTIONS

**-a**

> Display an entry for each file in the file hierarchy.

**-s**

> Display only the grand total for the specified files.

**-d** *depth*

> Maximum directory depth to print files and directories.

**-h**

> Enable human-readable output.

**-k**

> By default all sizes are reported in 512-byte block counts.
> The
> **-k**
> option causes the numbers to be reported in kilobyte counts.

**-H**

> Only dereference symbolic links that are passed as command line arguments when
> recursively traversing directories.

**-L**

> Always dereference symbolic links while recursively traversing directories.

**-P**

> Don't dereference symbolic links.
> This is the default.

**-x**

> Do not traverse file systems mount points.

# STANDARDS

The
**du**
utility is compliant with the
specification.

The
\[**-dhP**]
flags are an extension to that specification.

neveutils - May 26, 2025
