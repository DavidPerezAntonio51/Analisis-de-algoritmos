#include <stdlib.h>
#include <stdio.h>

int main(int arg, char *argv[]) {
	printf("***********************************************************************************\n");
	int n = atoi(argv[1]);
	int total = 0;
	printf("n = %d\n", n);
	int i = n;
	while (i>=0) {
		for(int j=n; i<j; i-=2,j/=2){
			printf("Algoritmos");
		}
	}
}