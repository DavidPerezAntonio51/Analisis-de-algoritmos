#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscarB(int arr[], int l, int izquierda, int x);
int buscarExpo(int arr[], int n, int x);
void rellenarArreglo(int *arreglo, int n);
void imprArreglo(int *arreglo, int n);
int minimos(int x, int y);

int main(int argc, char *argv[])
{

	int n;
	int i;
	int *arreglo;
	n = atoi(argv[1]);

	arreglo = malloc(n * sizeof(int));
	rellenarArreglo(arreglo, n);

	int resultado = buscarExpo(arreglo, n, 7);
}
void rellenarArreglo(int *arreglo, int n)
{

	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arreglo[i]);
	}
}

int buscarExpo(int arr[], int n, int x)
{
	if (arr[0] == x)
	{
		return 0;
	}

	int i = 1;
	while (i < n && arr[i] <= x)
	{
		i = i * 2;
	}
	int izquierda;
	int derecha = i / 2;
	if (i > n - 1)
	{
		izquierda = n - 1;
	}
	else
	{
		izquierda = i;
	}
	// inicia una busqueda binaria sobre el rango dado
	while (izquierda <= derecha)
	{
		int indiceMedio = floor((izquierda + derecha) / 2);

		int valorMedio = arr[indiceMedio];

		if (x == valorMedio)
		{
			return indiceMedio;
		}

		if (x < valorMedio)
		{
			derecha = indiceMedio - 1;
		}
		else
		{
			izquierda = indiceMedio + 1;
		}
	}
	return -1;
}