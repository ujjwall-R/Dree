script_dir="$(dirname "$0")"
make run -s -C "$script_dir" ARGS="$(pwd) $1 $2 $3"
