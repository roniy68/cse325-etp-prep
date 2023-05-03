#!/bin/bash
# A bash script to declare two variables, add their values, and display the result

# Declare the first variable "num1" and assign the value 10 to it
num1=10

# Declare the second variable "num2" and assign the value 5 to it
num2=5

# Add the values of the two variables and store the result in a third variable "sum"
sum=$((num1 + num2))

# Display the value of the "sum" variable using the "echo" command
echo "The sum of $num1 and $num2 is $sum"
