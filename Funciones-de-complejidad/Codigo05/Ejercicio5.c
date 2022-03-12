#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("n= %d\t",n);
    int asignacion = 0;
    int aritmetica = 0;
    int condicionales = 0;
    int var = 0;
    
    asignacion+=2;//i,j
    ++aritmetica;
    var+=3;//i,j,k
    var = var + 2*n;//arreglos de tamaño n
    for(int i = n-1, j = 0; i>=0; i--,j++){
        ++condicionales;//i>=0
        aritmetica+=2;//i,j
        asignacion+=2;//i,j
        //s2[j]=s[i];
        ++asignacion;//S2=s
        ++asignacion;//k=0
        for(int k=0; k<n; k++, ++aritmetica, ++asignacion){
            ++condicionales;//k<n
            //s[i]=s2[i];
            ++asignacion;//s=s2
        }
        ++condicionales;//falso de k<n
    }
    ++condicionales;//falso de i>=0
    
    int total = condicionales + aritmetica + asignacion;
    printf("Total instrucciones: %d Total variables: %d\n",total, var);
}