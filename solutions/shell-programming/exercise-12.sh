#!/bin/bash
# A bash script to display a message based on the value of the "day" variable

# Read a value from the user and assign it to the "day" variable
read -p "Enter a day of the week: " day

# Display a message based on the value of the "day" variable
case $day in
    "Monday")
        echo "It's the start of the week"
        ;;
    "Friday")
        echo "Thank goodness it's Friday!"
        ;;
    *)
        echo "Just another day"
        ;;
esac
