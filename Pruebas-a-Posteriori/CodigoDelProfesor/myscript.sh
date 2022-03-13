#!/bin/bash
gcc main.c  tiempo.c -o main
./main 50 
./main 50000 > sal.txt
./main 51000 >> sal.txt

