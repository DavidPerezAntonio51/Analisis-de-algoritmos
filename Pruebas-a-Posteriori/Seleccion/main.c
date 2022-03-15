#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
#include <stdbool.h>

int main(int argc, char *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int n = atoi(argv[1]);
    int A[n];
    int i;
    int p;
    int k;
    int temp;
    int i_lectura;

    printf("-------------------------------------------\n");
    // Lectura de los n numeros
    uswtime(&utime0, &stime0, &wtime0); // Inicia el conteo del tiempo
    for (i_lectura = 0; i_lectura < n; i_lectura++)
    {
        scanf("%d", &A[i_lectura]);
    }
    // Ejecucion de ordenamiento por Seleccion
    for (k = 0; k <= n - 2; k++)
    {
        p = k;
        for (i = k + 1; i <= n - 1; i++)
        {
            if (A[i] < A[p])
            {
                p = i;
            }
        }
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }

    // Impresion de los numeros --------- Desabilitado para obervar resultados de timepo en su lugar
    for (i_lectura = 0; i_lectura < n; i_lectura++)
    {
        printf("%d\n", A[i_lectura]);
    }

    uswtime(&utime1, &stime1, &wtime1); // Toma el tiempo una vez acabdo el algoritmo

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
}