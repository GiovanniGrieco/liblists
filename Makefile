UNAME	= $(shell uname)

CFLAGS	= -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow \
	  -fno-strict-aliasing -Wno-missing-field-initializers
INCLUDE	= -Isllist_examples/:.

BINARIES= example_edit example_gen3del1 example_insert example_invert \
	  example_printList example_search example_xchg

# Platform-dependant configuration
ifeq ($(UNAME), Linux)
TARGET	= liblists.so
ifeq ($(CC),)
CC	= clang
endif
ifeq ($(LIBC),)
LIBC	= clang
endif
LIBCFLG = $(CFLAGS) -fPIC
LIBBFLG	= -shared -Wl,-soname,liblists.so
LINKLIB = -L. -llists
else ifeq ($(UNAME), Darwin)
TARGET	= liblists.dylib
CC	= clang
LIBC	= libtool
LIBCFLG = $(CFLAGS)
LIBBFLG	= -dynamic -lSystem -macosx_version_min 10.11
LINKLIB = -L. -lSystem -llists
else
# Windows
TARGET	= liblists.dll
CC	= gcc
LIBC	= gcc
LIBCFLG = $(CFLAGS) -DBUILDING_EXAMPLE_DLL
LIBBFLG	= -shared -Wl,--out-implib,liblists.a
LINKLIB = -L. -llists
endif

all: $(TARGET) $(BINARIES) $(_BINWIN)
	mkdir -p build/ objects/
	mv $(TARGET) $(BINARIES) ./build
	mv *.o sllist_examples/*.o ./objects

# Library
$(TARGET): sllist.o
	$(LIBC) -o $@ $< $(LIBBFLG)

sllist.o: sllist.c
	$(CC) -c -o $@ $^ $(LIBCFLG)

# Examples for Single Linked Lists
example_%: sllist_examples/example_%.o sllist_examples/common.o
	$(CC) -o $@ $^ $(CFLAGS) $(LINKLIB)

# Examples objects
sllist_examples/%.o: sllist_examples/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE)

.PHONY: clean
clean:
	rm -rf build/ objects/

.PHONY: install
install:
ifeq ($(UNAME), Linux)
	cp build/liblists.so /usr/lib/
endif

.PHONY: uninstall
uninstall:
ifeq ($(UNAME), Linux)
	rm /usr/lib/liblists.so
endif