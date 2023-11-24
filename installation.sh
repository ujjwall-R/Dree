#!/bin/bash
git clone https://github.com/ujjwall-R/Dree
cd Dree
if [ ! -d "compile" ]; then mkdir compile; fi && make clean
path=$(pwd)
path+=/dree.sh
echo "alias dree=$path" >> ~/.bashrc
