# Dree [V0.0]

One single package for visualization, debugging, and exploration of folder hierarchies.

Say no to bulky file managers with Dree.

## Disclaimer

**Important:** This project is a work in progress and is not intended for production use at this time. It is undergoing active development, and changes, improvements, and bug fixes are being made frequently.

# Installation[Linux]

To run the Directory Tree Visualizer project, follow these steps:

1. Ensure you have C++17 compiler and development environment set up on your linux or mac system
2. Clone the project repository to your local machine.

```shell
git clone https://github.com/ujjwall-R/Dree
cd Dree
if [ ! -d "compile" ]; then mkdir compile; fi && make clean
```

Add path to `dree.sh` in `~/.bashrc` as:

```
alias dree='path/to/project/dree.sh'
```

## Run [example]

Run `dree` followed by number of nested levels you want to visualise:
```
dree 3
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
