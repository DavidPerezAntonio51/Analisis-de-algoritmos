#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /*n sera el tamaño del espacio de busqueda*/
    int n = atoi(argv[1]);
    /*b sera la cantidad de elemtos a buscar en la muestra*/
    int b = atoi(argv[2]);
    /*Variable que acumula los tiempos obtenidos en segundos*/
    double tiempo_total=0;
    int *numeros_a_buscar;
    int *muestra;
    muestra = malloc(n * sizeof(int));
    *numeros_a_buscar = malloc(n * sizeof(int));w
    llenarArreglos(numeros_a_buscar, b);
    llenarArreglos(muestra, n);
    int i;
    for(i = 0; i<b; i++){
        //mide tiempo inicio
        busquedaLineal(muestra,numeros_a_buscar[0],n);
        //mide tiempo fin

        //acumula valores fin-inicio de tiempo real;

    }
    /*Divide entre los valores buscados y muestra Tiempo Real*/
    printf("%.10f s,",tiempo_total/b);

    free(muestra);
    free(numeros_a_buscar);
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
    for(i=0; i<n;i++){
        if(muestra[i]==numero_a_buscar){
            return i;
        }
    }
    return -1;
}