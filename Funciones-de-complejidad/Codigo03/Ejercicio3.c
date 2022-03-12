#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("n= %d\t",n);
    int asignacion = 0;
    int aritmetica = 0;
    int condicionales = 0;
    int var = 0;
    var+=3;//i,j,k
    var = var + 3*(n*n);//3 arrelos de 2 dimensiones de tamaño n
    ++asignacion;//i=1
    for(int i =1; i<=n; i++, ++aritmetica, ++asignacion){
        ++condicionales;//i<=n
        ++asignacion;//j=1
        for(int j = 1; j <=n; j++,++aritmetica, ++asignacion){
            ++condicionales;//j<=n
            ++asignacion;//C=0
            //C[i][j]=0;
            ++asignacion;//k=1
            for(int k = 1; k<=n; k++,++aritmetica, ++asignacion){
                ++condicionales;//k<=n
                //C[i][j] = C[i][j] + A[i][k]*B[k][j];
                ++aritmetica;
                ++aritmetica;
                ++asignacion;
            }
            ++condicionales;//k<=n falso
        }
        ++condicionales;//j<=n falsas
    }
    ++condicionales;// i<=n falso
    int total = condicionales + aritmetica + asignacion;
    printf("Total instrucciones: %d Total variables: %d\n",total, var);
}