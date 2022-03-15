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
    int j;
    int aux;
    int i_lectura;

    printf("-------------------------------------------\n");
    // Lectura de los n numeros
    uswtime(&utime0, &stime0, &wtime0); // Inicia el conteo del tiempo
    for (i_lectura = 0; i_lectura < n; i_lectura++)
    {
        scanf("%d", &A[i_lectura]);
    }
    // Ejecucion de ordenamiento por Inserccion
    for (i = 0; i <= n - 1; i++)
    {
        j = i;
        aux = A[i];
        while (j > 0 && aux < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = aux;
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