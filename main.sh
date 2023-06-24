#!/bin/bash

# Compile the source files
g++ -std=c++17 src/main.cpp src/model/DirectoryNode.cpp src/controller/DirectoryGraph.cpp -o compile/main

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. Running the program..."
  
  # Run the executable
  ./compile/main
else
  echo "Compilation failed."
fi
