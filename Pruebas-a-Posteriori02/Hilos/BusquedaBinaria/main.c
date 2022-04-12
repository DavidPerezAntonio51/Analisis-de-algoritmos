#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"

void llenarArreglos(int *arreglo, int n_b);
int busquedaBinaria(void *id);

int NumThreads = 7; // Número de threads
int numero_a_buscar;
int n;
int salto;
int index = -1;
int *muestra;

int main(int argc, char *argv[])
{
    pthread_t *hilo = malloc(NumThreads * sizeof(pthread_t));
    /*n sera el tamaño del espacio de busqueda*/
    n = atoi(argv[1]);
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
    muestra = malloc(n * sizeof(int));
    llenarArreglos(muestra, n);
    salto = n / (NumThreads + 1);
    int j;
    int i;
    for (i = 0; i < b; i++)
    {
        // mide tiempo inicio
        uswtime(&utime0, &stime0, &wtime0);
        numero_a_buscar = numeros_a_buscar[i];
        for (j = 1; j <= NumThreads; j++)
        {
            if (pthread_create(&hilo[j], NULL, busquedaBinaria, (void *)j) != 0)
            {
                perror("El thread no  pudo crearse");
                exit(-1);
            }
        }
        // mide tiempo inicio
        busquedaBinaria(0);
        for (j = 1; i <= NumThreads; i++)
            pthread_join(hilo[i], NULL);
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

int busquedaBinaria(void *id)
{
    int hilo = (int)id;

    int izquierda = 0 + hilo * salto, derecha = (hilo + 1) * salto - 1;

    while (izquierda <= derecha)
    {
        int indiceMedio = floor((izquierda + derecha) / 2);

        int valorMedio = muestra[indiceMedio];

        if (numero_a_buscar == valorMedio)
        {
            index = indiceMedio;
        }

        if (numero_a_buscar < valorMedio)
        {
            derecha = indiceMedio - 1;
        }
        else
        {
            izquierda = indiceMedio + 1;
        }
    }
}