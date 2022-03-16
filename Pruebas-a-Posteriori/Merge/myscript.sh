#!/bin/bash
gcc main.c tiempo.c -o main
./main 15 > salida.txt < numeros10millones.txt