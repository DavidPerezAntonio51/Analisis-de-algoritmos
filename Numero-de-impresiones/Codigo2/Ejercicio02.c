#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]) {
	printf("***********************************************************************************\n");
	int n = atoi(argv[1]);
	int total = 0;
	int totalfor = 0;
	int totalif = 0;
	printf("n = %d\n", n);
	for (int j = n; j > 1; j/=2){
		//printf("For total: %d \n",++totalfor);
		if(j<(n/2)){
			//printf("if total: %d \n",++totalif);
			for(int i = 0; i < n; i+=2){
				//printf("Algoritmos%d\n", ++total);
				++total;
			}
		}
	}
	printf("Total: %d \n",total);
}