#!/bin/bash
gcc main.c tiempo.c -o main
./main 100 > salida.txt < numeros10millones.txt