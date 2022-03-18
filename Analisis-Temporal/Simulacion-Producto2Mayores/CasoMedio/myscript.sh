#!/bin/bash
gcc main.c -o main
i=0
total=0
while [ $i -lt 1000 ]
do
	aux=$(./main 5000)
	total=$((total+aux))
	echo $total
	((i++))
done

echo $((total/1000))
