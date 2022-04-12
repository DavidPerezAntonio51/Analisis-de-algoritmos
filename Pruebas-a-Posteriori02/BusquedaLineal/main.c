#include <stdlib.h>
#include <stdio.h>
#include "tiempo.h"

void llenarArreglos(int *arreglo, int n_b);
int busquedaLineal(int *muestra, int numero_a_buscar, int n);

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
        busquedaLineal(muestra, numeros_a_buscar[i], n);
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

int busquedaLineal(int *muestra, int numero_a_buscar, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (muestra[i] == numero_a_buscar)
        {
            return i;
        }
    }
    return -1;
}