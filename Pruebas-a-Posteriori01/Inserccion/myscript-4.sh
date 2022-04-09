#!/bin/bash
gcc main.c tiempo.c -o main
i=10000
((i+=950500))
while [ $i -lt 1000000 ]
do
	./main $i >> salida4.txt < numeros10millones.txt
	((i+=49500))
done
