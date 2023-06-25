# Compiler
CC := g++
# Compiler flags
CFLAGS := -std=c++17

# Source files
SOURCES := src/main.cpp src/model/DirectoryNode.cpp src/controller/DirectoryGraph.cpp
# Object files
OBJECTS := $(SOURCES:.cpp=.o)
# Executable name
EXECUTABLE := ./main

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Rule to build object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Target to run the program
run: $(EXECUTABLE)
	$(EXECUTABLE)

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
