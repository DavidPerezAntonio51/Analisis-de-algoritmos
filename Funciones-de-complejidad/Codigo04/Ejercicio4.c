#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("n= %d\t",n);
    int asignacion = 0;
    int aritmetica = 0;
    int condicionales = 0;
    int var = 0;
    
    int anterior = 1;
    ++asignacion;//anterior
    int actual = 1;
    ++asignacion;//actual
    int aux;
    var+=3;//anterior,actual,aux
    while (n>1)
    {
        ++condicionales;//verdaderos de n>1
        aux = anterior + actual;
        ++aritmetica;
        ++asignacion;
        anterior = actual;
        ++asignacion;
        actual = aux;
        ++asignacion;
        n = n - 1;
        ++aritmetica;
        ++asignacion;
    }
    ++condicionales;//falso de n>1
    
    int total = condicionales + aritmetica + asignacion;
    printf("Total instrucciones: %d Total variables: %d\n",total, var);
}