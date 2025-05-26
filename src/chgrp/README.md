CHGRP(1) - General Commands Manual

# NAME

**chgrp** - change file group ownership

# SYNOPSIS

**chgrp**
\[**-h**]
\[**-R**
\[**-H**&nbsp;|&nbsp;**-L**&nbsp;|&nbsp;**-P**]]
*group*
*file&nbsp;...*

# DESCRIPTION

**chgrp**
sets the group id of each
*file*
to the gid of
*group*.

# OPTIONS

**-h**

> Preserve
> *file*
> if it is a symbolic link.

**-R**

> Change file group ownerships recursively.

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
chown(1),
chmod(2),
chown(2),
getgrnam(3)

# STANDARDS

The
**chgrp**
utility is compliant with the
specification.

sbase - October 8, 2015
