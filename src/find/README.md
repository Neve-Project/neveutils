FIND(1) - General Commands Manual

# NAME

**find** - find files

# SYNOPSIS

**find**
\[**-H**&nbsp;|&nbsp;**-L**]
*path*&nbsp;\[...]
\[*expression*]

# DESCRIPTION

**find**
walks a file hierarchy starting at each
*path*
and applies the
*expression*
to each file encountered.

# OPTIONS

**-H**

> Dereference symbolic links provided as
> *path*.

**-L**

> Dereference all symbolic links encountered.

# EXTENDED DESCRIPTION

*expression*
is a combination of the following primaries and boolean operators.
In the following descriptions the number n can be replaced by +n, n, or
\-n, to mean more than, exactly, or less than n respectively.

## Primaries

**-name** *pattern*

> True if the name of the file matches the given pattern.

**-path** *pattern*

> True if the path to the file matches the given pattern.

**-nouser**

> True if the file belongs to a user for which getpwuid() returns NULL.

**-nogroup**

> True if the file belongs to a group for which getgrgid() returns NULL.

**-xdev**

> True.
> Do not enter directory on a different device.

**-prune**

> True.
> Do not enter directory.

**-perm** *mode*

> True if permissions on the file match mode.
> Mode is a symbolic mode as used in chmod.
> A leading '-' in mode checks that at least all bits in mode are set in
> permissions for file.
> Without the leading '-' the permissions for file must exactly match
> mode.

**-type** *t*

> True if file is of type specified by
> *t*.

> *b*

> > block special

> *c*

> > character special

> *d*

> > directory

> *l*

> > symbolic link

> *p*

> > FIFO

> *f*

> > regular file

> *s*

> > socket

**-links** *n*

> True if file has
> *n*
> links.

**-user** *name*

> True if file belongs to user
> *name*.

**-group** *name*

> True if file belongs to group
> *name*.

**-size** *n\[c]*

> True if file size in 512 byte sectors (rounded up), or bytes (if
> *c*
> is given), is
> *n*.

**-atime** **-n**

> True if file access time is
> *n*
> days.

**-ctime**

> True if file status change time is
> *n*
> days.

**-mtime**

> True if file modified time is
> *n*
> days.

**-exec** *cmd \[arg ...] ;*

> Execute cmd with given arguments, replacing each {} in argument list
> with the current file.
> True if cmd exits with status 0.

**-exec** *cmd \[arg ...] {} +*

> True.
> Add as many files as possible to argument list and execute when the list
> is full or all files have been found.

**-ok** *cmd \[arg ...] ;*

> Prompt the user on each file encountered whether or not to execute cmd
> as with -exec.
> True if the user responds yes and cmd exits with status 0, false
> otherwise.

**-print**

> True.
> Print the path to the current file.

**-newer** *file*

> True if the modification time of the current file is newer than that of
> the provided file.

**-depth**

> True.
> Causes find to evaluate files within in a directory before the directory
> itself.

## Operators

In order of decreasing precedence

*( expression )*

> True if expression is true.

*! expression*

> True if expression if false.

*expression* \[**-a**] *expression*

> True if both expressions are true.
> Second expression is not evaluated if first expression is false.
> **-a**
> is implied if there is no operator between primaries.

*expression* **-o** *expression*

> True if either expression is true.
> Second expression is not evaluated if first expression is true.

If no expression is supplied, -print is used.
If an expression is supplied but none of -print, -exec, or -ok is
supplied, then -a -print is appended to the expressions.

neveutils - May 26, 2025
