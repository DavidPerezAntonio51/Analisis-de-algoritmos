#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
void quickSort(int *arreglo, int p, int r);
int pivot(int *arreglo, int p, int r);
void intercambiar(int *arreglo, int i, int j);

int main (int argc, char* argv[])
{	
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	int n;
	int *arreglo;
	n=atoi(argv[1]);
	//printf("----------------------------------------------------------\n");

	arreglo = malloc(n*sizeof(int)); 
	
	llenarArreglo(arreglo, n);

	uswtime(&utime0, &stime0, &wtime0);
	
	quickSort(arreglo, 0, n-1); //mandamos a llamar a la funcion que iniciara con el ordenamiento

	uswtime(&utime1, &stime1, &wtime1);
	imprimirArreglo(arreglo, n);
	
	// Cálculo del tiempo de ejecución del programa
	/*
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
	*/
}

void llenarArreglo(int* arreglo, int n){
	
	int i = 0;
	for(i=0;i<n;i++){
		scanf("%d", &arreglo[i]);
	}

}

void imprimirArreglo(int* arreglo, int n){
	int i = 0, k=0;

	
	for(i=0;i<n;i++)
		printf("%d\n", arreglo[i]);

}

void quickSort(int *arreglo, int p, int r){
	int j=0; 
	if(p < r){
		j = pivot(arreglo, p, r);
		quickSort(arreglo, p, j);
		quickSort(arreglo, j+1, r); //hacemos uso de la recursividad
	}
}


int pivot(int *arreglo, int p, int r){


	int piv = arreglo[p], i = p, j = r;


	while(1){

		while(arreglo[i] < piv ) i++; 
		while(arreglo[j] > piv) j--; //disminuye el indice de la derecha si es mayor al pivote, es decir, este ordenado

		
		if(i >= j )
			return j;
		else{
			intercambiar(arreglo, i, j); 
			i++; 
			j--; 
		}
	}
}

void intercambiar(int *arreglo, int i, int j){
	int temp = arreglo[j];

	arreglo[j] = arreglo[i];
	arreglo[i] = temp;
}
