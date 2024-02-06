script_dir="$(dirname "$0")"
make run -s -C "$script_dir" ARGS="$(pwd) $1 $2 $3"

navigate_file="$script_dir/.navigate"
if [ -e "$navigate_file" ] && [ -s "$navigate_file" ]; then
    selected_directory=$(<"$navigate_file")
    cd "$selected_directory" || { echo "Error: Unable to change directory"; exit 1; }
else
    echo "Error: .navigate file not found or empty."
    exit 1
fi