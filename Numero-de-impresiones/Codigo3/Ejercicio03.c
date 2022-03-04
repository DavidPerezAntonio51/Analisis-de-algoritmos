#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]) {
	printf("***********************************************************************************\n");
	int n = atoi(argv[1]);
	int total = 0;
	printf("n = %d\n", n);
	for(int i = 0;  i<n*5; i+=2){
		for(int j=0; j<n*2; j++){
			for(int k=j; k<n; k++){
				//printf("Algoritmos");
				++total;
			}
		}
	}
	printf("Total: %d \n",total);
}