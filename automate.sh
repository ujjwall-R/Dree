#!/bin/bash
repo_url="https://github.com/ujjwall-R/Dree.git"
repo_name="Dree"
git clone "$repo_url"
cd "$repo_name"


if [ ! -d "compile" ]; then mkdir compile; fi && make clean


current_directory="${PWD}"
current_directory+=/dree.sh

if [  -n "$ZSH_VERSION" ]; then
   echo "alias dree='$current_directory'" >> ~/.zshrc
   source ~/.zshrc
else
   echo "alias dree='$current_directory'" >> ~/.bashrc
   source ~/.bashrc
fi
