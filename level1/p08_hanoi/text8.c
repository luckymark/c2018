#include<stdio.h>
void hano(int n,char p1, char p2, char p3) {
	if (n == 1) {
		printf("\t%c-->%c", p1, p3);
	}
	else
	{
		hano(n - 1, p1, p3, p2);
		printf("\t%c-->%c\n", p1, p3);
		hano(n - 1, p2, p1, p3);
	}
}
int main() {
	int n;
	printf("ÊäÈëÒÆ¶¯¿éÊı:");
	scanf("%d", &n);
	hano(n, 'p1', 'p2','p3');
	return 0;
}