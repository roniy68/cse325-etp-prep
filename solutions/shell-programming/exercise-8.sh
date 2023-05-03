#!/bin/bash
# A bash script to declare a variable "files" and display the contents of each file in the list

# Declare a variable "files" and assign a list of filenames to it
files=("file1.txt" "file2.txt" "file3.txt")

# Loop through each file in the "files" list and display its contents using the "cat" command
for file in "${files[@]}"
do
    echo "Contents of $file:"
    cat "$file"
done

