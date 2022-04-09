#!/bin/bash
gcc main.c tiempo.c -o main
./main 100 > salida.txt < numeros10millones.txt
./main 1000 >> salida.txt < numeros10millones.txt
./main 5000 >> salida.txt < numeros10millones.txt
./main 10000 >> salida.txt < numeros10millones.txt
./main 50000 >> salida.txt < numeros10millones.txt
./main 100000 >> salida.txt < numeros10millones.txt
./main 200000 >> salida.txt < numeros10millones.txt
./main 400000 >> salida.txt < numeros10millones.txt
./main 600000 >> salida.txt < numeros10millones.txt
./main 800000 >> salida.txt < numeros10millones.txt
./main 1000000 >> salida.txt < numeros10millones.txt
./main 2000000 >> salida.txt < numeros10millones.txt
./main 3000000 >> salida.txt < numeros10millones.txt
./main 4000000 >> salida.txt < numeros10millones.txt
./main 5000000 >> salida.txt < numeros10millones.txt
./main 6000000 >> salida.txt < numeros10millones.txt
./main 7000000 >> salida.txt < numeros10millones.txt
./main 8000000 >> salida.txt < numeros10millones.txt
./main 9000000 >> salida.txt < numeros10millones.txt
./main 10000000 >> salida.txt < numeros10millones.txt
