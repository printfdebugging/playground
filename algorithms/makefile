SRCDIR	 = source
INCDIR	 = include
BUILDDIR = build

CC		=  ccache gcc
CFLAGS	= -g -O0 -std=c11 -Wall -Wextra -static -I$(INCDIR) 
LFLAGS	= 

SOURCES		= $(shell find $(SRCDIR) -name '*.c')
EXECUTABLES = $(patsubst $(SRCDIR)%.c,$(BUILDDIR)%,$(SOURCES))

$(BUILDDIR)/% : $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: run
run: $(EXECUTABLES)

.PHONY: clean
clean :
	rm -rf $(BUILDDIR)
