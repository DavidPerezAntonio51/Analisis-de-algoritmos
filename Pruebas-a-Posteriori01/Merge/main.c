#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

void llenarArreglo(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);
void mergeSort(int *arreglo, int p, int r);
void merge(int *arreglo, int p, int q, int r);

int main(int argc, char *argv[])
{

	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n;
	int *arreglo;
	int aux;
	printf("-------------------------------------------\n");
	n = atoi(argv[1]);

	arreglo = malloc(n * sizeof(int));

	llenarArreglo(arreglo, n);

	uswtime(&utime0, &stime0, &wtime0);

	mergeSort(arreglo, 0, n - 1);

	uswtime(&utime1, &stime1, &wtime1);
	// Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * ((utime1 - utime0) + (stime1 - stime0)) / (wtime1 - wtime0));
	printf("\n");

	// Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	/*imprimirArreglo(arreglo, n);*/
}

void llenarArreglo(int *arreglo, int n)
{

	int i = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arreglo[i]);
	}
}

void imprimirArreglo(int *arreglo, int n)
{
	int i = 0, k = 0; // variable para ciclo

	for (i = 0; i < n; i++)
		printf("%d: %d\n", ++k, arreglo[i]);
}

void mergeSort(int *A, int p, int r)
{

	if (p < r)
	{
		int q = ((p + r)) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

void merge(int *A, int p, int q, int r)
{
	int k;
	int l = r - p + 1;
	int i = p;
	int j = q + 1;
	int *C;

	C = malloc(l * sizeof(int));

	for (k = 0; k < l; k++)
	{
		if (i <= q && j <= r)
		{
			if (A[i] < A[j])
			{
				C[k] = A[i];
				i++;
			}
			else
			{
				C[k] = A[j];
				j++;
			}
		}
		else if (i <= q)
		{
			C[k] = A[i];
			i++;
		}
		else
		{
			C[k] = A[j];
			j++;
		}
	}

	for (k = 0; k < l; k++)
		A[p + k] = C[k];
}
