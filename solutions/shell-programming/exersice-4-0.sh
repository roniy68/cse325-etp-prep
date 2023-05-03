#!/bin/bash
# A bash script to count the number of lines, words, and characters in a file

# Check if the number of arguments is correct
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <file>"
  exit 1
fi

# Parse the argument
file=$1

# Check if the file exists
if [ ! -f "$file" ]; then
  echo "Error: $file is not a file"
  exit 1
fi

# Count the number of lines, words, and characters in the file
num_lines=$(wc -l < "$file")
num_words=$(wc -w < "$file")
num_chars=$(wc -m < "$file")

# Display the result
echo "The file $file contains:"
echo "  $num_lines lines"
echo "  $num_words words"
echo "  $num_chars characters"
