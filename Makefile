# Compiler
CC := g++
# Compiler flags
CFLAGS := -std=c++17 -MMD -MP
# Libraries
LIBS := -lncurses

# Source directory
SRCDIR := src
# Object directory
OBJDIR := obj
# Executable name
EXECUTABLE := compile/main

# Find all source files recursively
SOURCES := $(shell find $(SRCDIR) -name "*.cpp")
# Object files derived from source files
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
# Directories to create object files in
DIRECTORIES := $(sort $(dir $(OBJECTS)))

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(DIRECTORIES)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the directories for object files
$(DIRECTORIES):
	mkdir -p $@

# Include the dependency files
-include $(OBJECTS:.o=.d)

# Target to run the program
run: $(EXECUTABLE)
	$(EXECUTABLE) $(ARGS)

# Clean target
clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)
