#!/bin/bash
# A bash script to check if "x" is greater than or equal to 10

# Assign a value to the "x" variable
x=10

# Check if "x" is greater than 10 or equal to 10, and display a message if it is
if [ $x -ge 10 ]; then
    if [ $x -eq 10 ]; then
        echo "x is equal to 10"
    else
        echo "x is greater than 10"
    fi
fi
