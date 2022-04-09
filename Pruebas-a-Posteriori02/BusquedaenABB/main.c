#include <stdlib.h>
#include <stdio.h>
/*Declaramos la estructura que se usara*/
struct ABB {
    int dato;
    struct ABB *hoja_izquierda;
    struct ABB *hoja_derecha;
};
int main(int argc, char *argv[]){
    /*n sera el tamaño del espacio de busqueda*/
    int n = atoi(argv[1]);
    /*b sera la cantidad de elemtos a buscar en la muestra*/
    int b = atoi(argv[2]);
    /*Variable que acumula los tiempos obtenidos en segundos*/
    double tiempo_total=0;
    int *numeros_a_buscar;
}

int busquedaEnArbol(struct ABB* nodo, int numero_a_buscar){
    while(nodo!=NULL){
        if(nodo->dato == numero_a_buscar){
            return nodo->dato;
        }else if(nodo->dato>numero_a_buscar){
            nodo = nodo->hoja_izquierda;
        }else if(nodo->dato<numero_a_buscar){
            nodo = nodo->hoja_derecha;
        }
    }
    return -1;
}

struct ABB* nuevo_nodo(int dato){
    struct ABB* nodo = (struct ABB*)malloc(sizeof(struct ABB));
    nodo->dato=dato;
    nodo->hoja_izquierda=nodo->hoja_derecha=NULL;
    return nodo;
}

struct ABB* insertar_dato(struct ABB *nodo, int dato){
    if(nodo == NULL){
        return nuevo_nodo(dato);
    }
    if(dato<nodo->dato){
        nodo->hoja_izquierda = insertar_dato(nodo->hoja_izquierda,dato);
    }else if(dato>nodo->dato){
        nodo->hoja_derecha = insertar_dato(nodo->hoja_derecha,dato);
    }
    return nodo;
}

void liberarMemoriaArbol(struct ABB *nodo){
    if(nodo!=NULL){
        liberarMemoriaArbol(nodo->hoja_derecha);
        liberarMemoriaArbol(nodo->hoja_izquierda);
        free(nodo);
        nodo=NULL;
    }
}