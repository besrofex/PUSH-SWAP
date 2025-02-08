#!/bin/bash

max=0

while true
do
ARG=$(seq 1 5 | sort -R)
num=$(./push_swap $ARG | wc -l)
echo "   $num    $max"
./push_swap $ARG | ./checker_Mac $ARG
if [ "$num" -gt "$max" ]; then
    max=$num
fi
sleep 0.1
done
