DMESG(1) - General Commands Manual

# NAME

**dmesg** - print or control the kernel ring buffer

# SYNOPSIS

**dmesg**
\[**-Ccr**]
\[**-n**&nbsp;*level*]

# DESCRIPTION

**dmesg**
examines or controls the kernel ring buffer. By default it reads all the
messages from the kernel ring buffer and prints them to stdout.

# OPTIONS

**-C**

> Clear the ring buffer.

**-c**

> Clear the ring buffer after printing its contents.

**-n** *level*

> Set the console
> *level*.
> The log levels are defined in the file
> *include/linux/kern\_levels.h*.

**-r**

> Print the raw message buffer.

neveutils - May 26, 2025
