#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

void llenarArreglos(int *arreglo, int n_b);
int busquedaFibonacci(int *arreglo, int x, int n);

int encontrado = 0;
int main(int argc, char *argv[])
{
/*n sera el tamaño del espacio de busqueda*/
    int n = atoi(argv[1]);
    /*b sera la cantidad de elemtos a buscar en la muestra*/
    int b = atoi(argv[2]);
    /*Variable que acumula los tiempos obtenidos en segundos*/
    double tiempo_total = 0;
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int numeros_a_buscar[] = {322486,
                              14700764,
                              3128036,
                              6337399,
                              61396,
                              10393545,
                              2147445644,
                              1295390003,
                              450057883,
                              187645041,
                              1980098116,
                              152503,
                              5000,
                              1493283650,
                              214826,
                              1843349527,
                              1360839354,
                              2109248666,
                              2147470852,
                              0};
    int *muestra;
    muestra = malloc(n * sizeof(int));
    llenarArreglos(muestra, n);
    int i;
    for (i = 0; i < b; i++)
    {
        // mide tiempo inicio
        uswtime(&utime0, &stime0, &wtime0);
        busquedaFibonacci(muestra, numeros_a_buscar[i], n);
        // mide tiempo fin
        uswtime(&utime1, &stime1, &wtime1);
        // acumula valores fin-inicio de tiempo real;
        tiempo_total = tiempo_total + (wtime1 - wtime0);
    }
    /*Divide entre los valores buscados y muestra Tiempo Real*/
    printf("%.10e;\n", tiempo_total / b);

    free(muestra);
}

void llenarArreglos(int *arreglo, int n_b)
{
    int i;
    for (i = 0; i < n_b; i++)
    {
        scanf("%d", &arreglo[i]);
    }
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

