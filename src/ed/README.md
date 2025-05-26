ED(1) - General Commands Manual

# NAME

**ed** - text editor

# SYNOPSIS

**ed**
\[**-s**]
\[**-p**&nbsp;*string*]
\[*file*]

# DESCRIPTION

**ed**
is the standard text editor.
It performs line-oriented operations on a buffer; The buffer's contents are
manipulated in command mode and text is written to the buffer in input mode.
Command mode is the default.
To exit input mode enter a dot ('.') on a line of its own.

If
**ed**
is invoked with a file as an argument, it will simulate an edit command and read
the file's contents into a buffer.
Changes to this buffer are local to
**ed**
until a write command is given.

**ed**
uses the basic regular expression syntax and allows any character but space and
newline to be used as a delimiter in regular expressions.

# OPTIONS

**-s**

> Suppress diagnostic messages

**-p** *string*

> Use
> *string*
> as a prompt when in command mode

# EXTENDED DESCRIPTION

## Addresses

Commands operate on addresses.
Addresses are used to refer to lines within the buffer.
Address ranges may have spaces before and after the separator.
Unless otherwise specified, 0 is an invalid address.
The following symbols are valid addresses:

n

> The nth line.

.

> The current line, or "dot".

$

> The last line.

\+

> The next line.

\+n

> The nth next line.

^ or -

> The previous line.

^n or -n

> The nth previous line.

x,y

> The range of lines from x to y.
> The default value of x is 1, and the default value of y is $.

x;y

> As above, except that the current line is set to x.
> Omitting x in this case uses the current line as the default value.

/re/

> The next line matching re.

?re?

> The last line matching re.

'c

> The line marked by c. See k below.

## Commands

**ed**
expects to see one command per line, with the following exception: commands may
be suffixed with either a list, number, or print command.
These suffixed commands are run after the command they're suffixed to has
executed.

The following is the list of commands that
**ed**
knows about.
The parentheses contain the default addresses that a command uses.

(.)a

> Append text after the addressed line.
> The dot is set to the last line entered.
> If no text was entered, the dot is set to the addressed line.
> An address of 0 appends to the start of the buffer.

(.,.)c

> Delete the addressed lines and then accept input to replace them.
> The dot is set to the last line entered.
> If no text was entered, the dot is set to the line before the deleted lines.

(.,.)d

> Delete the addressed lines.
> If there is a line after the deleted range, the dot is set to it.
> Otherwise, the dot is set to the line before the deleted range.

e *file*

> Delete the contents of the buffer and load in
> *file*
> for editing, printing the bytes read to standard output.
> If no filename is given,
> **ed**
> uses the currently remembered filename.
> The remembered filename is set to
> *file*
> for later use.

E *file*

> As above, but without warning if the current buffer has unsaved changes.

f *file*

> Set the currently remembered filename to
> *file*
> , or print the currently remembered filename if
> *file*
> is omitted.

(1,$)g/re/command

> Apply command to lines matching re.
> The dot is set to the matching line before command is executed.
> When each matching line has been operated on, the dot is set to the last line
> operated on.
> If no lines match then the dot remains unchanged.
> The command used may not be g, G, v, or V.

(1,$)G/re/

> Interactively edit the range of line addresses that match re.
> The dot is set to the matching line and printed before a command is input.
> When each matching line has been operated on, the dot is set to the last line
> operated on.
> If no lines match then the dot remains unchanged.
> The command used may not be a, c, i, g, G, v, or V.

h

> Print the reason for the most recent error.

H

> Toggle error explanations.
> If on, the above behaviour is produced on all subsequent errors.

(.)i

> Insert text into the buffer before the addressed line.
> The dot is set to the last line entered.
> If no text was entered, the dot is set to the addressed line

(.,.+1)j

> Join two lines together.
> If only one address is given, nothing happens.
> The dot is set to the newly joined line.

(.)kc

> Mark the line with the lower case character c. The dot is unchanged.

(.,.)l

> Unambiguously print the addressed lines.
> The dot is set to the last line written.

(.,.)m(.)

> Move lines in the buffer to the line address on the right hand side.
> An address of 0 on the right hand side moves to the start of the buffer.
> The dot is set to the last line moved.

(.,.)n

> Print the addressed lines and their numbers.
> The dot is set to the last line printed.

(.,.)p

> Print the addressed lines.
> The dot is set to the last line printed.

P

> Toggle the prompt.
> Defaults to off, but is switched on if the -p flag is used.

q

> Quit
> **ed**
> , warning if there are unsaved changes.

Q

> As above, but without warning if the current buffer has unsaved changes.

($)r *file*

> Read in
> *file*
> and append it to the current buffer, printing the bytes read to standard output.
> The currently remembered filename isn't changed unless it's empty.
> An address of 0 reads the file into the start of the buffer.

(.,.)s/re/replacement/flags

> Substitute re for replacement in lines matching re.
> An & within replacement is replaced with the whole string matched by re.
> Backrefs can be used with the form &#92;n, where n is a positive non-zero integer.
> When % is the only character in replacement, it is substituted for the
> replacement string from the last substitute command.
> If a newline is part of replacement then the matched string is split into two
> lines; this cannot be done as part of a g or v command.
> If flags contains an integer n, then the nth match is replaced.
> If flags contains g, all matches are replaced.
> The dot is set to the last line matched.

(.,.)t(.)

> As m, but copying instead of moving.
> The dot is set to the last line added.

u

> Undo the last change.
> The dot is set to whatever it was before the undone command was performed.

(1.$)v/re/command

> As with g, but operating on lines that don't match re.

(1.$)V/re/

> As with G, but operating on lines that don't match re.

(1,$)w *file*

> Write the addressed lines to
> *file*
> , overwriting its previous contents if the file exists, and print the number of
> bytes written.
> If no filename is given the currently remembered filename will be used instead.
> The dot is unchanged.

(1,$)W *file*

> As above, but instead of overwriting the contents of
> *file*
> the addressed lines are appended to
> *file*
> instead.

(.+1)

> Print the addressed line.
> Sets the dot to that line.

($)=

> Print the line number of the addressed line.
> The dot is unchanged.

&

> Repeat the last command.

! *command*

> Execute
> *command*
> using sh.
> If the first character of
> *command*
> is '!' then it is replaced with the text of the previous command.
> An unescaped % is replaced with the currently remembered filename.
> ! does not process escape characters.
> When
> *command*
> returns a '!' is printed.
> The dot is unchanged.

# SEE ALSO

sed(1),
regexp(3)

# STANDARDS

The
**ed**
utility is compliant with the
specification, except where noted here:
g and v operate on single commands rather than lists delimited with '&#92;'.
e, E, r, w, and W commands cannot accept shell escapes.

neveutils - May 26, 2025
