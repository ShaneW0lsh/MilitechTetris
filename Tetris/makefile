TARGET = SnakeGame
SRCDIR = src
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

CC = g++
CFLAGS = -std=c++17 -Wall
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRC := $(wildcard $(SRCDIR)/*.cpp)
# Object files
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(SFML_LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
