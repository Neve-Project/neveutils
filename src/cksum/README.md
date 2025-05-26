CKSUM(1) - General Commands Manual

# NAME

**cksum** - compute file checksum

# SYNOPSIS

**cksum**
\[*file&nbsp;...*]

# DESCRIPTION

**cksum**
calculates a cyclic redundancy check (CRC) of
*file*
according to
ISO 8802-3: 1989
and writes it, the file size in bytes and path to stdout.

If no
*file*
is given,
**cksum**
reads from stdin.

# STANDARDS

The
**cksum**
utility is compliant with the
specification.

neveutils - May 26, 2025
