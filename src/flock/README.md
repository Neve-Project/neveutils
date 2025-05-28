FLOCK(1) - General Commands Manual

# NAME

**flock** - tool to manage locks on files

# SYNOPSIS

**flock**
\[**-nosux**]
*file*
*cmd*&nbsp;\[arg&nbsp;...]

# DESCRIPTION

**flock**
is used to manage advisory locks on open files.
It is commonly used to prevent long running cron jobs from running in
parallel.
If
*file*
does not exist, it will be created.

# OPTIONS

**-n**

> Set non-blocking mode on the lock.
> Fail immediately if the lock cannot be acquired.

**-o**

> Close the file descriptor before exec to avoid having the exec'ed
> program holding on to the lock.

**-s**

> Acquire a shared lock.

**-u**

> Release the lock.

**-x**

> Acquire an exclusive lock.
> This is the default.

neveutils - May 28, 2025
