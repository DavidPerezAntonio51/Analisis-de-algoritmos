#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]) {
	printf("***********************************************************************************\n");
	int n = atoi(argv[1]);
	int total = 0;
	printf("n = %d\n", n);
	for(int i =1; i<4*n; i*=2){
		for(int j = i; j<5*n; j+=3){
			//printf("Algoritmos\n");
			++total;
		}
	}
	printf("Total: %d\n",total);
}