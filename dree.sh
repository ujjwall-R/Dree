script_dir="$(dirname "$0")"
make run -C "$script_dir" ARGS="$(pwd) $1 $2 $3"
