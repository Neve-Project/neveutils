EXPR(1) - General Commands Manual

# NAME

**expr** - evaluate expression

# SYNOPSIS

**expr**
*expression*

# DESCRIPTION

**expr**
evaluates
*expression*
and writes the result to stdout.

There are two elemental expressions,
**integer**
and
**string.**
Let
**expr**
be a non-elemental expression and
**expr1**,
**expr2**
arbitrary expressions.
Then
**expr**
has the recursive form
**expr = \[(] expr1 operand expr2 \[)].**

With
**operand**
being in order of increasing precedence:

|

> Evaluate to
> **expr1**
> if it is neither an empty string nor 0; otherwise evaluate to
> **expr2**.

&

> Evaluate to
> **expr1**
> if
> **expr1**
> and
> **expr2**
> are neither empty strings nor 0; otherwise evaluate to 0.

&equals; &gt; &gt;= &lt; &lt;= !=

> If
> **expr1**
> and
> **expr2**
> are integers, evaluate to 1 if the relation is true and 0 if it is false.
> If
> **expr1**
> and
> **expr2**
> are strings, apply the relation to the return value of
> strcmp(3).

\+ -

> If
> **expr1**
> and
> **expr2**
> are integers, evaluate to their sum or subtraction.

\* / %

> If
> **expr1**
> and
> **expr2**
> are integers, evaluate to their multiplication, division or remainder.

:

> Evaluate to the number of characters matched in
> **expr1**
> against
> **expr2**. **expr2**
> is anchored with an implicit '^'.

> You can't directly match the empty string, since zero matched characters
> resolve equally to a failed match.
> To work around this limitation, use "expr X'' : 'X$' instead of "expr ''
> : '$'"

# EXIT STATUS

0

> *expression*
> is neither an empty string nor 0.

1

> *expression*
> is an empty string or 0.

2

> *expression*
> is invalid.

&gt; 2

> An error occurred.

# SEE ALSO

test(1)

# STANDARDS

The
**expr**
utility is compliant with the
specification.

neveutils - May 26, 2025
