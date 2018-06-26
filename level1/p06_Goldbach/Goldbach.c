//100以内哥德巴赫猜想验证
#include <stdio.h>
#include <math.h>
int prime[100];
int isPrime(int n) {
	for (int i=3; i<=(int)sqrt(n); i+=2) {
		if (n%i==0) {
			return 0;
		}
	}
	return 1;
}
int gdbh(int n) {
	for (int n1=0; n1<n; n1++) {
		for (int n2=0; n2<n; n2++) {
			if (n==prime[n1]+prime[n2]) {
				printf("%d=%d+%d ",n,prime[n1],prime[n2]);
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	prime[0]=2;
	for (int i=3,j=1; j<100; i+=2,j++) {
		if (isPrime(i))
			prime[j]=i;
	}
	for (int i=4; i<102; i+=2) {
		gdbh(i);
	}
	return 1;
}
