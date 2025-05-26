INSTALL(1) - General Commands Manual

# NAME

**install** - copy files and set attributes

# SYNOPSIS

**install**
\[**-g**&nbsp;*group*]
\[**-o**&nbsp;*owner*]
\[**-m**&nbsp;*mode*]
(**-d**&nbsp;*dir&nbsp;...*
|
\[**-D**]
(**-t**&nbsp;*dest*
*source&nbsp;...*
|
*source&nbsp;...*
*dest*))

# DESCRIPTION

**install**
copies
*source*
to
*dest*.
If more than one
*source*
is given
*dest*
is treated as a directory.
Otherwise
*dest*
is treated as a filename.
**install**
can also change the attributes of the copies.

# OPTIONS

**-d**

> Create the directories
> *dir*.

**-D**

> Create missing parent directories to
> *dest*.
> If
> *dest*
> is to be treated as a directory, it is created too if missing.

**-g** *group*

> Change the installed files' group to
> *group*.
> This may be a group name or a group identifier.

**-m** *mode*

> Change the file modes.
> Both numerical and symbolic values are supported.
> See
> chmod(1)
> for the syntex.
> Default mode 0755.
> If a file has the mode 0644 and is copied with

**-o** *owner*

> Change the installed files' owner to
> *owner*.
> This may be a user name or a user identifier.

**-t** *dest*

> Copy files into the directory
> *dest*.
> **install**,
> the copy's mode will be 0755 unless
> **-m**
> is used to select another mode.
> When the symbolic notation is used, the base mode is 0000.

# SEE ALSO

chmod(1),
chown(1),
cp(1),
mkdir(1)

# STANDARDS

The
**install**
utility is not standardized.
This implementation is a subset of the GNU implementation and a subset
with extensions to the FreeBSD implementation.

sbase - December 3, 2016
