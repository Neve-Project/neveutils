CHROOT(1) - General Commands Manual

# NAME

**chroot** - run a command or shell with a different root directory

# SYNOPSIS

**chroot**
*dir*
\[*cmd*&nbsp;\[*arg&nbsp;...*]]

# DESCRIPTION

**chroot**
runs
*cmd*
after changing the root directory to
*dir*
with the
chroot(2)
system call and after changing the working directory to the new root.
If
*cmd*
is not specified, an interactive shell is started in the new root.

# SEE ALSO

chdir(2),
chroot(2)

neveutils - May 26, 2025
