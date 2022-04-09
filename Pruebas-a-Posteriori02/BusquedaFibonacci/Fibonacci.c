#include <stdio.h>
#include <stdlib.h>

void llenarArreglo(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);
int busquedaFibonacci(int *arreglo, int x, int n);
int min(int x, int y);

int encontrado = 0;
int main(int argc, char *argv[])
{

	int n;
	int i;
	int *arreglo;
	n = atoi(argv[1]);
	arreglo = malloc(n * sizeof(int));
	llenarArreglo(arreglo, n);

	encontrado = busquedaFibonacci(arreglo, 8, n);
}

int busquedaFibonacci(int *arreglo, int x, int n)
{
	int fibMNum2 = 0;
	int fibMNum1 = 1;
	int fibM = fibMNum2 + fibMNum1;
	while (fibM < n)
	{
		fibMNum2 = fibMNum1;
		fibMNum1 = fibM;
		fibM = fibMNum2 + fibMNum1;
	}
	int inicio = -1;
	while (fibM > 1)
	{
		int i = (inicio + fibMNum2 <= n - 1) ? inicio + fibMNum2 : n - 1;
		if (arreglo[i] < x)
		{
			fibM = fibMNum1;
			fibMNum1 = fibMNum2;
			fibMNum2 = fibM - fibMNum1;
			inicio = i;
		}
		else if (arreglo[i] > x)
		{
			fibM = fibMNum2;
			fibMNum1 = fibMNum1 - fibMNum2;
			fibMNum2 = fibM - fibMNum1;
		}
		else
			return i;
	}
	if (fibMNum1 && arreglo[inicio + 1] == x)
	{
		return inicio + 1;
	}
	return -1;
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
