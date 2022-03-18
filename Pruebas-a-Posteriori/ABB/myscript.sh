#!/bin/bash
gcc main.c tiempo.c arbol.c -o main
./main 5000 > salida.txt < numeros10millones.txt
