#!/bin/bash

g++ -std=c++17 src/main.cpp src/model/DirectoryNode.cpp src/controller/DirectoryGraph.cpp -o compile/main

if [ $? -eq 0 ]; then
  echo "Compilation successful. Running the program..."
  
  ./compile/main
else
  echo "Compilation failed."
fi
