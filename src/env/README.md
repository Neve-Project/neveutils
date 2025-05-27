ENV(1) - General Commands Manual

# NAME

**env** - modify the environment, then print it or run a command

# SYNOPSIS

**env**
\[**-i**]
\[**-u**&nbsp;*var*]&nbsp;...
\[*var*=*value*]&nbsp;...
\[*cmd*&nbsp;\[arg&nbsp;...]]

# DESCRIPTION

**env**
unsets each
*var*,
then adds or sets each
(*var*, *value*)
tuple in the environment.

If
*cmd*
is given, it is executed in this new environment;
otherwise, the modified environment is printed to stdout.

# OPTIONS

**-i**

> Completely ignore the existing environment and execute
> *cmd*
> only with each
> (*var*, *value*)
> tuple specified.

**-u** *var*

> Unset
> *var*
> in the environment.

# SEE ALSO

printenv(1),
putenv(3),
environ(7)

# STANDARDS

The
**env**
utility is compliant with the
specification.

The
\[**-u**]
flag is an extension to that specification.

neveutils - May 25, 2025
