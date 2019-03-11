//tower of brahma puzzle
#include <stdio.h>
#define N 10

unsigned long long int m=0;
int hannoi (int,char,char,char);
int main () {
	int n=N;
	char a='A',b='B',c='C';
	hannoi(n,a,b,c);
	printf("\n共需%d次操作\n",m);
	return 0;
}
int hannoi (int n,char begin,char between,char end) {
	if (n==1) {
		m++;
		printf("%c->%c ",begin,end);
		if (m%20==0) {
			printf("\n");
		}
	} else {
		hannoi(n-1,begin,end,between);
		m++;
		printf("%c->%c ",begin,end);
		if (m%20==0) {
			printf("\n");
		}
		hannoi(n-1,between,begin,end);
	}
	return 0;
}
