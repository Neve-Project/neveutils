# version
VERSION = 0.1

# install path
PREFIX    ?= /usr/local
MANPREFIX += $(PREFIX)/share/man

# tools
CC     ?= cc
AR     ?= ar
RANLIB ?= ranlib

# flags
CFLAGS   += -O2 -static -D_DEFAULT_SOURCE -D_NETBSD_SOURCE -D_BSD_SOURCE \
            -D_XOPEN_SOURCE=700 -D_FILE_OFFSET_BITS=64 \
            -I. -Iinclude -Ilibutil -Ilibutf
LDFLAGS  += -static -Wl,--gc-sections -s -Wl,--strip-all

