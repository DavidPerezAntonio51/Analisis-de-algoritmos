#!/bin/bash
gcc main.c tiempo.c -o main
./main 500000 > salida.txt < numeros10millones.txt