CHOWN(1) - General Commands Manual

# NAME

**chown** - change file ownership

# SYNOPSIS

**chown**
\[**-h**]
\[**-R**
\[**-H**&nbsp;|&nbsp;**-L**&nbsp;|&nbsp;**-P**]]
*owner*\[:\[*group*]]
\[*file&nbsp;...*]  
**chown**
\[**-h**]
\[**-R**
\[**-H**&nbsp;|&nbsp;**-L**&nbsp;|&nbsp;**-P**]]
:*group*
\[*file&nbsp;...*]

# DESCRIPTION

**chown**
sets the user and/or group id of each
*file*
to the uid of
*owner*
and/or the gid of
*group*
respectively.

# OPTIONS

**-h**

> Preserve
> *file*
> if it is a symbolic link.

**-R**

> Change file ownerships recursively.

**-H**

> Dereference
> *file*
> if it is a symbolic link.

**-L**

> Dereference all symbolic links.

**-P**

> Preserve symbolic links.
> This is the default.

# SEE ALSO

chmod(1),
chown(2),
getgrnam(3),
getpwnam(3)

# STANDARDS

The
**chown**
utility is compliant with the
specification.

neveutils - May 26, 2025
