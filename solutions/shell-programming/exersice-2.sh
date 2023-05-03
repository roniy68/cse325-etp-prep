#!/bin/bash
# A bash script to add two numbers

# Check if the number of arguments is correct
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <number1> <number2>"
  exit 1
fi

# Parse the arguments
num1=$1
num2=$2

# Add the numbers
sum=$(expr $num1 + $num2)

# Display the result
echo "The sum of $num1 and $num2 is: $sum"
