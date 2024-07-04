#!/bin/bash

g++ -std=c++17 src/main.cpp -o compile/main

if [ $? -eq 0 ]; then
  echo "Compilation successful. Running the program..."

  ./compile/main
else
  echo "Compilation failed."
fi