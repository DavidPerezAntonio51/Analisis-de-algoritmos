#include <stdlib.h>
#include <stdio.h>
#include "tiempo.h"
/*Declaramos la estructura que se usara*/
struct ABB
{
    int dato;
    struct ABB *hoja_izquierda;
    struct ABB *hoja_derecha;
};
void liberarMemoriaArbol(struct ABB *nodo);
void llenarArreglos(struct ABB *arbol, int n_b);
int busquedaEnArbol(void *id);
struct ABB *insertar_dato(struct ABB *nodo, int dato);
struct ABB *nuevo_nodo(int dato);

int NumThreads = 7; // Número de threads
int numero_a_buscar;
int n;
struct ABB *arbol1 = NULL;
struct ABB *arbol2 = NULL;
struct ABB *arbol3 = NULL;
struct ABB *arbol4 = NULL;
struct ABB *arbol5 = NULL;
struct ABB *arbol6 = NULL;
struct ABB *arbol7 = NULL;
struct ABB *arbol8 = NULL;
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

    llenarArreglos(arbol1, n / (NumThreads + 1));
    llenarArreglos(arbol2, n / (NumThreads + 1));
    llenarArreglos(arbol3, n / (NumThreads + 1));
    llenarArreglos(arbol4, n / (NumThreads + 1));
    llenarArreglos(arbol5, n / (NumThreads + 1));
    llenarArreglos(arbol6, n / (NumThreads + 1));
    llenarArreglos(arbol7, n / (NumThreads + 1));
    llenarArreglos(arbol8, n / (NumThreads + 1));

    int i;
    int j;
    for (i = 0; i < b; i++)
    {
        // mide tiempo inicio
        uswtime(&utime0, &stime0, &wtime0);
        numero_a_buscar = numeros_a_buscar[i];
        for (j = 1; j <= NumThreads; j++)
        {
            if (pthread_create(&hilo[j], NULL, busquedaEnArbol, (void *)j) != 0)
            {
                perror("El thread no  pudo crearse");
                exit(-1);
            }
        }
        busquedaEnArbol(0);
        // mide tiempo inicio
        for (j = 1; i <= NumThreads; i++)
            pthread_join(hilo[i], NULL);
        // mide tiempo fin
        uswtime(&utime1, &stime1, &wtime1);
        // acumula valores fin-inicio de tiempo real;
        tiempo_total = tiempo_total + (wtime1 - wtime0);
    }
    /*Divide entre los valores buscados y muestra Tiempo Real*/
    printf("%.10e;\n", tiempo_total / b);

    liberarMemoriaArbol(arbol1);
    liberarMemoriaArbol(arbol2);
    liberarMemoriaArbol(arbol3);
    liberarMemoriaArbol(arbol4);
    liberarMemoriaArbol(arbol5);
    liberarMemoriaArbol(arbol6);
    liberarMemoriaArbol(arbol7);
    liberarMemoriaArbol(arbol8);
}

void llenarArreglos(struct ABB *arbol, int n_b)
{
    int i;
    int temp;
    for (i = 0; i < n_b; i++)
    {
        scanf("%d", &temp);
        if (i == 0)
        {

            arbol = insertar_dato(arbol, temp);
        }
        insertar_dato(arbol, temp);
    }
}

int busquedaEnArbol(void *id)
{
    struct ABB *nodo = NULL;
    switch ((int)id)
    {
    case 1:
        nodo = arbol1;
        break;
    case 2:
        nodo = arbol2;
        break;
    case 3:
        nodo = arbol3;
        break;
    case 4:
        nodo = arbol4;
        break;
    case 5:
        nodo = arbol5;
        break;
    case 6:
        nodo = arbol6;
        break;
    case 7:
        nodo = arbol7;
        break;
    case 8:
        nodo = arbol8;
        break;
    }
    while (nodo != NULL)
    {
        if (nodo->dato == numero_a_buscar)
        {
            return nodo->dato;
        }
        else if (nodo->dato > numero_a_buscar)
        {
            nodo = nodo->hoja_izquierda;
        }
        else if (nodo->dato < numero_a_buscar)
        {
            nodo = nodo->hoja_derecha;
        }
    }
    return -1;
}

struct ABB *nuevo_nodo(int dato)
{
    struct ABB *nodo = malloc(sizeof(struct ABB));
    nodo->dato = dato;
    nodo->hoja_izquierda = nodo->hoja_derecha = NULL;
    return nodo;
}

struct ABB *insertar_dato(struct ABB *nodo, int dato)
{
    if (nodo == NULL)
    {
        return nuevo_nodo(dato);
    }
    if (dato < nodo->dato)
    {
        nodo->hoja_izquierda = insertar_dato(nodo->hoja_izquierda, dato);
    }
    else if (dato > nodo->dato)
    {
        nodo->hoja_derecha = insertar_dato(nodo->hoja_derecha, dato);
    }
    return nodo;
}

void liberarMemoriaArbol(struct ABB *nodo)
{
    if (nodo != NULL)
    {
        liberarMemoriaArbol(nodo->hoja_derecha);
        liberarMemoriaArbol(nodo->hoja_izquierda);
        free(nodo);
        nodo = NULL;
    }
}