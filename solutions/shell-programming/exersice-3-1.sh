#!/bin/bash
# A bash script to count the number of files in a directory and all its subdirectories

# Check if the number of arguments is correct
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <directory>"
  exit 1
fi

# Parse the argument
dir=$1

# Check if the directory exists
if [ ! -d "$dir" ]; then
  echo "Error: $dir is not a directory"
  exit 1
fi

# Count the number of files in the directory and all its subdirectories
num_files=$(find "$dir" -type f | wc -l)

# Display the result
echo "The number of files in $dir and its subdirectories is: $num_files"
