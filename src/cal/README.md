CAL(1) - General Commands Manual

# NAME

**cal** - show calendar

# SYNOPSIS

**cal**
\[**-1**&nbsp;|&nbsp;**-3**&nbsp;|&nbsp;**-y**&nbsp;|&nbsp;**-n**&nbsp;*num*]
\[**-s**&nbsp;|&nbsp;**-m**&nbsp;|&nbsp;**-f**&nbsp;*num*]
\[**-c**&nbsp;*num*]
\[\[*month*]&nbsp;*year*]

# DESCRIPTION

**cal**
writes a calendar of
*month*
and
*year*
or the current month to stdout.
If
*year*
is given without
*month*,
**cal**
writes a 3-column calendar of the whole
year to stdout.
The date formatting is according to
localtime(3).

The Julian calendar is used until Sep 2, 1752.
The Gregorian calendar is used starting the next day on Sep 14, 1752.

# OPTIONS

**-1**

> Print current month.
> This is the default.

**-3**

> Print previous, current and next month.

**-c** *num*

> Print
> *num*
> calendars in a row.
> The default is 3.

**-f** *num*

> Set
> *num*
> (0 is Sunday, 6 is Saturday) as first day of week.

**-m**

> Set Monday as first day of week.

**-n** *num*

> Output
> *num*
> months starting from and including the current month.

**-s**

> Set Sunday as first day of week.

**-y**

> Print the entire
> *year*
> or current year.

# SEE ALSO

localtime(3)

# STANDARDS

The
**cal**
utility is compliant with the
specification.

The flags
\[**-13cfmnsy**]
are an extension to that specification.

sbase - October 8, 2015
