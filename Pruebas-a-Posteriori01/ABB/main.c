#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

struct Arbol
{
	int dato;
	struct Arbol *izquierda;
	struct Arbol *derecha;
};

void llenarArreglo(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);
struct Arbol *insertar(struct Arbol *nodo, int n);
void guardarRecorridoInOrden(struct Arbol *nodo, int *arreglo);

int aux = 0; // variable auxiliar

int main(int argc, char *argv[])
{
	printf("------------------------------------------------------------\n");
	double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables tiempo
	int n;												   // n para tama�o memoria dinamica
	int i, j;											   // indices fors
	int *arreglo;										   // apuntadro para crear memoria dinamica//
	struct Arbol *arbol = NULL;							   // variable que apunta a la estructura Arbol
	n = atoi(argv[1]);

	// Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n * sizeof(int));
	// mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);
	// lo imprimimos para verificar que se lleno correctamente
	// imprimirArreglo(arreglo, n);

	// rendimiento//
	uswtime(&utime0, &stime0, &wtime0);

	for (i = 0; i < n; i++)
	{
		arbol = insertar(arbol, arreglo[i]);
	}

	guardarRecorridoInOrden(arbol, arreglo);

	// Tiempo ejecucion//
	uswtime(&utime1, &stime1, &wtime1);

	// Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	// Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	// mandamos a llamar la funcion para imprimir solo para verificar que este el arreglo ordenado
	// imprimirArreglo(arreglo, n);
	// Terminar programa normalmente
}

void llenarArreglo(int *arreglo, int n)
{

	int i = 0; // variable para ciclo

	// llenamos el arreglo gracias al for que va de 0 hasta la n indicada por parametros al ejecutar
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arreglo[i]);
	}
}

void imprimirArreglo(int *arreglo, int n)
{
	int i = 0, k = 0; // variable para ciclo

	// for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for (i = 0; i < n; i++)
		printf("%d: %d\n", ++k, arreglo[i]);
}

struct Arbol *insertar(struct Arbol *nodo, int n)
{
	if (nodo == NULL)
	{ // caso base: nodo raíz
		struct Arbol *nuevo = NULL;
		nuevo = (struct Arbol *)malloc(sizeof(struct Arbol)); // solicita memoria
		nuevo->dato = n;									  // asigna el dato
		nuevo->izquierda = NULL;							  // inicializa los nodos izq y der
		nuevo->derecha = NULL;
		return nuevo;
	}

	if (n < nodo->dato)
	{ // si n es menor, se guarda en el nodo izquierdo
		nodo->izquierda = insertar(nodo->izquierda, n);
	}
	else
	{ // si es mayor, se guarda en el nodo derecho
		nodo->derecha = insertar(nodo->derecha, n);
	}

	return nodo;
}

void guardarRecorridoInOrden(struct Arbol *nodo, int *arreglo)
{
	if (nodo != NULL)
	{
		guardarRecorridoInOrden(nodo->izquierda, arreglo);
		arreglo[aux++] = nodo->dato;
		guardarRecorridoInOrden(nodo->derecha, arreglo);
	}
}
