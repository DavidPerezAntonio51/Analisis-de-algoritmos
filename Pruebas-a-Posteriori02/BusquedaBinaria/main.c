#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int *muestra;
    int n, numero_buscado;
    n = atoi(argv[2]);

    // Ejecuta el algoritmo de busqueda
    int indice = busquedaBinaria(muestra, numero_buscado, n);
    free(muestra);
}

int busquedaBinaria(int arr[], int x, int n)
{
    int izquierda = 0, derecha = n - 1;

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