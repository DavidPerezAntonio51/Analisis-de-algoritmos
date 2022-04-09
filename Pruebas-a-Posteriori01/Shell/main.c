
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include <math.h>

void llenarArreglo(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);

int main(int argc, char *argv[])
{
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n;
	int i;
	int k;
	int *arreglo;
	int b;
	int temp;

	printf("-------------------------------------------\n");
	n = atoi(argv[1]);

	// Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n * sizeof(int));

	// mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);

	uswtime(&utime0, &stime0, &wtime0);

	k = trunc(n / 2);
	while (k >= 1)
	{
		do
		{
			b = 0;
			for (int i = k; i <= n - 1; i++)
			{
				if (arreglo[i - k] > arreglo[i])
				{
					temp = arreglo[i];
					arreglo[i] = arreglo[i - k];
					arreglo[i - k] = temp;
					b++;
				}
			}

		} while (b != 0);
		k = trunc(k / 2);
	}

	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	// Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	// mandamos a llamar la funcion para imprimir solo para verificar que este el arreglo ordenado
	/*imprimirArreglo(arreglo, n);*/
}

void llenarArreglo(int *arreglo, int n)
{

	int i = 0; // Variable para ciclo

	// Llenamos el arreglo gracias al for que va de 0 hasta antes de la n indicada por parametros al ejecutar
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arreglo[i]);
	}
}

void imprimirArreglo(int *arreglo, int n)
{
	int i = 0; // variable para ciclo

	// for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for (i = 0; i < n; i++)
		printf("%d: %d\n", i + 1, arreglo[i]);
}
