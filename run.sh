#!/bin/bash

# Find the file that was modified last
file=$(find . -name "*.c" -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -f2- -d" ")

# Get the directory and filename without extension
dir=$(dirname "$file")
filename=$(basename "$file" .c)

echo "Compiling $file"

# Compile the file and create object in the same directory
gcc -o "$dir/$filename" "$file" -lglut -lGLU -lGL

# Run the output
echo "Running $dir/$filename"

cd "$dir" && "./$filename"
