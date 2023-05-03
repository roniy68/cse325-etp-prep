#!/bin/bash
# A bash script to count the number of lines, words, and characters in one or more files

# Check if the number of arguments is correct
if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <file1> [<file2> ... <fileN>]"
  exit 1
fi

# Loop through each file argument
for file in "$@"; do

  # Check if the file exists
  if [ ! -f "$file" ]; then
    echo "Error: $file is not a file"
    continue
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
done
