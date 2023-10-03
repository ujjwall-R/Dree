# Dree

One single package for visualization, debugging, and exploration of folder hierarchies.

Say no to bulky file managers with Dree.

## Preview

###### Blog : [Link](https://dev.to/ujjwall-r/i-tried-making-a-terminal-based-file-exploration-package-2142)

Dree presents the folders in a tree-like format, with the main folder at the top and its subfolders branching out below it. This makes it easier for you to see how the folders are organized and navigate through them.

One cool thing about Dree is that you can decide how many levels of folders you want to see at a time. For example, if you only want to see the main folder and its immediate subfolders, you can set the depth to 1. If you want to see more levels of folders, you can increase the depth accordingly. This allows you to focus on the specific parts of the folder structure that are most relevant to you.

![image](https://github.com/ujjwall-R/Dree/assets/75781631/d75b5f2d-55f6-4f66-8c15-6dfbc2822780)

In addition to displaying the directory structure, Dree offers a powerful search feature within the directory tree. Users can search for specific files or folders within the entire directory structure. Furthermore, Dree allows users to manually adjust their search space by setting the depth level.

![image](https://github.com/ujjwall-R/Dree/assets/75781631/7424fd22-072f-41f7-8d6c-290a93e3bd4b)

The recommendation feature proves to be particularly helpful when users are unsure about the exact spelling or naming of a file or folder.

![image](https://github.com/ujjwall-R/Dree/assets/75781631/49bc8a09-c626-4cde-8fee-a93b4c06e734)

## Disclaimer

**Important:** This project is undergoing active development, and changes, improvements, and bug fixes are being made frequently.

# Installation

To run the Directory Tree Visualizer project, follow these steps:

1. Ensure you have C++17 compiler and development environment set up on your linux or mac system
2. Clone the project repository to your local machine.

```shell
git clone https://github.com/ujjwall-R/Dree
cd Dree
if [ ! -d "compile" ]; then mkdir compile; fi && make clean
```

Add path to `dree.sh` in `~/.bashrc`. If you use zsh add the path in `~/.zshrc`.

```
# Add the following line at the end of the ~/.bashrc file
alias dree='path/to/project/dree.sh'
```

Restart terminal or run:

```shell
source ~/.bashrc
```

## Usage

### Print Dree (Directory tree)

Run `dree` followed by number of nested levels you want to visualise:

```shell
dree 3
```

### Search file or folder in a directory upto certain depth

```shell
#eg. search a folder in current directory upto 3 depth
dree 3 -f "directory_name"
#eg. search a file in current directory upto 5 depth
dree 5 -f "file_name"
```

# Development

## How to Run [Development]

To run the Directory Tree Visualizer project, follow these steps:

1. Ensure you have C++17 compiler and development environment set up on your linux or mac system
2. Clone the project repository to your local machine.

```shell
cd Dree
```

### Build

```shell
if [ ! -d "compile" ]; then mkdir compile; fi && make clean
```

### Run

```shell
make run
```

### Compile the changes

```shell
make all
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
