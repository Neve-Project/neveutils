DATE(1) - General Commands Manual

# NAME

**date** - print or set date and time

# SYNOPSIS

**date**
\[**-d**&nbsp;*time*]
\[**-u**]
\[**+**&zwnj;*format*&nbsp;|
*mmddHHMM*\[\[*CC*]*yy*]]

# DESCRIPTION

**date**
prints the date and time according to
locale(7)
or
*format*
using
strftime(3)
or sets the date.

# OPTIONS

**-d** *time*

> Print
> *time*
> given as the number of seconds since the
> Unix epoch 1970-01-01T00:00:00Z.

**-u**

> Print or set UTC time instead of local time.

An operand with a leading plus
(**+**)
sign signals a user-defined format string using
strftime(3)
conversion specifications.

An operand without a leading plus sign is interpreted as a value
for setting the system's current date and time.
The canonical representation for setting the date and time is:

*mm*

> The month of the year, from 01 to 12.

*dd*

> The day of the month, from 01 to 31.

*HH*

> The hour of the day, from 00 to 23.

*MM*

> The minute of the hour, from 00 to 59.

*CC*

> The first two digits of the year (the century).

*yy*

> The second two digits of the year.
> If
> *yy*
> is specified, but
> *CC*
> is not, a value for
> *yy*
> between 69 and 99 results in a
> *CC*
> value of 19.
> Otherwise, a
> *CC*
> value of 20 is used.

The century and year are optional.
The default is the current year.

# STANDARDS

The
**date**
utility is compliant with the
specification.

The
\[**-d**]
flag is an extension to that specification.

neveutils - May 26, 2025
