#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/random.h>

int producto2Mayores(int A[], int n, int *asignaciones, int *comparaciones);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int i_lectura;
    int asignaciones=0;
    int comparaciones=0;
    int A[n];
    srand(time(NULL));
    // Generacion de los 2500 o 5000 numeros random
    for (i_lectura = 0; i_lectura < n; i_lectura++)
    {
        A[i_lectura] = rand();
    }
    producto2Mayores(A, n, &asignaciones, &comparaciones);
    printf("%d\n",asignaciones+comparaciones);
}
// Se indexa de 0 a 2499 o 0 a 4999, es lo mismo que 1 a 2500 o 1 a 5000
int producto2Mayores(int A[], int n, int *asignaciones, int *comparaciones)
{
    int mayor1;
    int mayor2;
    int i;
    ++*comparaciones;
    if (A[0] > A[1])
    {
        mayor1 = A[0];++*asignaciones;
        mayor2 = A[1];++*asignaciones;
    }
    else
    {
        mayor1 = A[1];++*asignaciones;
        mayor2 = A[0];++*asignaciones;
    }
    i = 2;
    while (i < n)
    {
        if (A[i] > mayor1)
        {
            ++*comparaciones;
            mayor2 = mayor1;
            ++*asignaciones;
            mayor1 = A[i];
            ++*asignaciones;
        }
        else if (A[i] > mayor2)
        {
            *comparaciones+=2;
            mayor2 = A[i];
            ++*asignaciones;
        }else{
            //se ejecutara en caso de que no se entre en ninguno de los casos anteriores
            *comparaciones+=2;
        }
        i++;
    }
    return mayor1*mayor2;
}