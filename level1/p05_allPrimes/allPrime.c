//allPrimes
#include <stdio.h>
#include <math.h>
#include <time.h>
int isPrime(int n) {
	for (int i=3; i<=(int)sqrt(n); i+=2) {
		if (n%i==0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	double start,finish;
	start=clock();
	printf("  2 ");
	for (int i=3,j=1; i<1000; i+=2) {
		if (isPrime(i)) {
			printf("%3d ",i);
			j++;
			if (j%10==0) {
				printf("\n");
			}
		}
	}
	finish=clock();
	printf("\nÓÃÊ±%.3f seconds\n",(finish-start)/CLOCKS_PER_SEC);
	return 1;
}
