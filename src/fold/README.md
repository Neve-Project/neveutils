FOLD(1) - General Commands Manual

# NAME

**fold** - wrap lines to width

# SYNOPSIS

**fold**
\[**-bs**]
\[**-w**&nbsp;*num*&nbsp;|&nbsp;**-**&zwnj;*num*]
\[*file&nbsp;...*]

# DESCRIPTION

**fold**
reads each
*file*
and prints its lines wrapped such that no line
exceeds a certain width.
If no file is given,
**fold**
reads from stdin.

# OPTIONS

**-b**

> Count bytes rather than characters.

**-s**

> If a line contains spaces, break
> at the last space within width.

**-w** *num* | **-**&zwnj;*num*

> Break at
> *num*
> characters.
> The default is 80.

# STANDARDS

The
**fold**
utility is compliant with the
specification.

The
\[**-**&zwnj;*num*]
syntax is an extension to that specification.

neveutils - May 28, 2025
