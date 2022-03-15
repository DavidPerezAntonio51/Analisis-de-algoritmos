#!/bin/bash
gcc main.c tiempo.c arbol.c -o main
./main 10 > salida.txt < numeros10millones.txt