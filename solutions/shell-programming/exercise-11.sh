#!/bin/bash
# A bash script to display the names of all files in the current directory and only the names of .txt files

# Display the names of all files in the current directory
echo "All files in current directory:"
for file in *
do
    echo $file
done

# Display only the names of .txt files in the current directory
echo "Text files in current directory:"
for file in *.txt
do
    echo $file
done
