SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj

CC		=  g++
CFLAGS	= -g -I$(INCDIR) -O0
LFLAGS	= -lsfml-system -lsfml-window -lsfml-graphics -lm
APPEXE	= $(OBJDIR)/exe


SRC_FILES = $(shell find $(SRCDIR) -name '*.cpp')
OBJ_FILES = $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRC_FILES))

$(APPEXE) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -rf $(OBJDIR)

run : $(APPEXE)
	./$(APPEXE)
