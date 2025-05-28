GREP(1) - General Commands Manual

# NAME

**grep** - search files for patterns

# SYNOPSIS

**grep**
\[**-EFHchilnqsvx**]
\[**-e**&nbsp;*pattern*]
\[**-f**&nbsp;*file*]
\[*pattern*]
\[*file&nbsp;...*]

# DESCRIPTION

**grep**
searches the input files for lines that match the
*pattern*,
a regular expression as defined in
regex(7) or
re\_format(7).
By default each matching line is printed to stdout.
If no
*file*
is given
**grep**
reads from stdin.

# OPTIONS

**-E**

> Match using extended regex.

**-F**

> Match using fixed strings.
> Treat each pattern specified as a string instead of a regular
> expression.

**-H**

> Prefix each matching line with its filename in the output.
> This is the default when there is more than one file specified.

**-c**

> Print only a count of matching lines.

**-e** *pattern*

> Specify a pattern used during the search of the input: an input
> line is selected if it matches any of the specified patterns.
> This option is most useful when multiple -e options are used to
> specify multiple patterns, or when a pattern begins with a dash.

**-f** *file*

> Read one or more patterns from the file named by the pathname file.
> Patterns in file shall be terminated by a &lt;newline&gt;.
> A null pattern can be specified by an empty line in pattern\_file.
> Unless the -E or -F option is also specified, each pattern shall be
> treated as a BRE.
> (\`-').

**-h**

> Do not prefix each line with 'filename:' prefix.

**-i**

> Match lines case insensitively.

**-l**

> Print only the names of files with matching lines.

**-n**

> Prefix each matching line with its line number in the input.

**-q**

> Print nothing, only return status.

**-s**

> Suppress the error messages ordinarily written for nonexistent or unreadable
> files.

**-v**

> Select lines which do
> **not**
> match the pattern.

**-w**

> The expression is searched for as a word (as if surrounded by '&#92;&lt;' and '&#92;&gt;').

**-x**

> Consider only input lines that use all characters in the line excluding the
> terminating &lt;newline&gt; to match an entire fixed string or regular expression to
> be matching lines.

# EXIT STATUS

0

> One or more lines were matched.

1

> No lines were matched.

&gt; 1

> An error occurred.

# SEE ALSO

sed(1),
regex(7),
re\_format(7)

# STANDARDS

The
**grep**
utility is compliant with the
specification.

The
\[**-Hhw**]
flags are an extension to that specification.

neveutils - May 28, 2025
