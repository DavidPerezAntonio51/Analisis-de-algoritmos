#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("n= %d\t",n);
    int asignacion = 0;
    int aritmetica = 0;
    int condicionales = 0;
    int var = 0;
    var = var + 3;//i,j,temp
    var = var + n + 1;//
    asignacion++;//Asignacion i=1
    for(int i = 1; i<n; i++, ++aritmetica, ++asignacion) {
        ++condicionales;//Condicional for linea 12
        ++asignacion;//asignacion de j=n
        for(int j = n; j>1; j/=2, ++aritmetica,++asignacion) {
            ++condicionales;//Condicional for linea 15
            //temp = A[j];
            ++asignacion;
            //A[j] = A[j+1];
            ++aritmetica;
            ++asignacion;
            //A[j+1] = temp;
            ++asignacion;
            ++aritmetica;
        }
        ++condicionales;//condicional falsa de for L15
        
    }
    ++condicionales;//condicional falsa de for L12
    int total = condicionales + aritmetica + asignacion;
    printf("Total instrucciones: %d Total variables: %d\n",total, var);
}