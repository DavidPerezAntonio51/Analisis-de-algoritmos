#!/bin/bash
gcc main.c tiempo.c -o main
i=1000000
./main $i 20 > salida.txt < numeros10millones.txt
((i+=1000000))
while [ $i -lt 11000000 ]
do
	./main $i 20 >> salida.txt < numeros10millones.txt
	((i+=1000000))
done
