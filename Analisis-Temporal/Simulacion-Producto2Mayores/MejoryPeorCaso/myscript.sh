#!/bin/bash
gcc main.c -o main
./main 2500 > salida.txt < PeorCaso1-2500.txt
./main 5000 >> salida.txt < PeorCaso1-5000.txt
./main 2500 >> salida.txt < PeorCaso2-2500.txt
./main 5000 >> salida.txt < PeorCaso2-5000.txt