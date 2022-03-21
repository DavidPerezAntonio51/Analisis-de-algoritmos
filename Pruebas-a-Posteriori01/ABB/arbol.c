#include <stdlib.h>
#include <stdio.h>

struct Nodo
{
    int valor;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Nodo *nuevoNodo(int dato)
{
    struct Nodo *nodo = malloc(sizeof(struct Nodo));
    nodo->valor = dato;
    nodo->izquierdo = nodo->derecho = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato)
{
    if (dato > nodo->valor)
    {
        if (nodo->derecho == NULL)
        {
            nodo->derecho = nuevoNodo(dato);
        }
        else
        {
            insertar(nodo->derecho, dato);
        }
    }
    else
    {
        if (nodo->izquierdo == NULL)
        {
            nodo->izquierdo = nuevoNodo(dato);
        }
        else
        {
            insertar(nodo->izquierdo, dato);
        }
    }
}

void inorden (struct Nodo* nodo, int *A, int *i){
    if(nodo!=NULL){
        inorden(nodo->izquierdo, A, i);
        A[*i] = nodo->valor; *i=*i+1;
        inorden(nodo->derecho, A, i);
    }
}