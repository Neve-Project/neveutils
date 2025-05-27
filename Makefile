.POSIX:
include config.mk

BOX := neveutils
UTILS := yes whoami xinstall \
				 basename blkdiscard cal cat chgrp chmod chown \
				 chroot chvt cksum clear cmp cols comm cp cron \
				 ctrlaltdel cut date dd df dirname dmesg du echo \
				 ed env expand expr false find

SRC := src/main.c $(foreach cmd,$(UTILS),src/$(cmd)/$(cmd).c)
OBJ := $(SRC:.c=.o)

LIBUTF_SRC  := $(wildcard libutf/*.c)
LIBUTIL_SRC := $(wildcard libutil/*.c)
LIBUTF_OBJ  := $(LIBUTF_SRC:.c=.o)
LIBUTIL_OBJ := $(LIBUTIL_SRC:.c=.o)
LIBUTF      := libutf.a
LIBUTIL     := libutil.a
LIBS        := $(LIBUTF) $(LIBUTIL)

.PHONY: all clean install uninstall

all: $(BOX)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBUTF): $(LIBUTF_OBJ)
	$(AR) rc $@ $^
	$(RANLIB) $@

$(LIBUTIL): $(LIBUTIL_OBJ)
	$(AR) rc $@ $^
	$(RANLIB) $@

$(BOX): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)

install: $(BOX)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(BOX) $(DESTDIR)$(PREFIX)/bin/$(BOX)
	cd $(DESTDIR)$(PREFIX)/bin && \
	for cmd in $(UTILS); do \
		ln -sf $(BOX) $$cmd; \
	done

uninstall:
	cd $(DESTDIR)$(PREFIX)/bin && \
	for cmd in $(UTILS); do \
		rm -f $$cmd; \
	done
	rm -f $(DESTDIR)$(PREFIX)/bin/$(BOX)

clean:
	rm -f $(OBJ) $(LIBUTF_OBJ) $(LIBUTIL_OBJ) $(LIBUTF) $(LIBUTIL) $(BOX)

