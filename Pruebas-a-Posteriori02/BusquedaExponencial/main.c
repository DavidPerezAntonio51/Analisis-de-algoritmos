#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"

void llenarArreglos(int *arreglo, int n_b);
int buscarExpo(int arr[], int n, int x);

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
        buscarExpo(muestra, n, numeros_a_buscar[i]);
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