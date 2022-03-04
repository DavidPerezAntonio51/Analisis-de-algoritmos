#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]) {
	printf("***********************************************************************************\n");
	int n = atoi(argv[1]);
	int total = 0;
	printf("n = %d\n", n);
	for (int i = 10; i < n*5; i*=2){
		printf("Algoritmos %d\n",++total);
	}
}