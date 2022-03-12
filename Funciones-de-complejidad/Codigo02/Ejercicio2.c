#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("n= %d\t",n);
    int asignacion = 0;
    int aritmetica = 0;
    int condicionales = 0;
    int var = 0;

    ++asignacion;//polinomio
    ++var;//polinomio
    int polinomio = 0;
    ++asignacion;// i = 0
    ++var;//i
    ++var;//z
    var+=n;//Arreglo A de tamaño n
    for(int i = 0; i<=n; i++, ++aritmetica, ++asignacion){
        ++condicionales;//i<=n verdadero
        //polinomio =  polinomio*z + A[n-i];
        ++aritmetica;//A[n-1]
        ++aritmetica;//polinomio*z
        ++aritmetica;//polinomio*z+a[n-1]
        ++asignacion;//polinomio = polinomio*
    }
    ++condicionales;//i<=n falso
    int total = condicionales + aritmetica + asignacion;
    printf("Total instrucciones: %d Total variables: %d\n",total, var);
}