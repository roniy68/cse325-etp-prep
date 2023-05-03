#!/bin/bash
# A bash script to print numbers from 1 to 10 and only even numbers from 1 to 10

# Print numbers from 1 to 10
echo "Numbers from 1 to 10:"
for i in {1..10}
do
    echo $i
done

# Print only even numbers from 1 to 10
echo "Even numbers from 1 to 10:"
for i in {1..10}
do
    if (( $i % 2 == 0 ))
    then
        echo $i
    fi
done
