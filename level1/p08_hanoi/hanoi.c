#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf_s("%d", &n);
	char column1 = 65;
	char column2 = 66;
	char column3 = 67;
	move(n,column1,column2,column3);
	system("pause");
}

int move(int n,char c1,char c2,char c3) {
	if (n >= 2) {
		n = n - 1;
		move(n, c1, c3, c2);
		putchar(c1); printf("-->"); putchar(c3); printf("\n");
		move(n, c2, c1, c3);
	}
	else {
		putchar(c1); printf("-->"); putchar(c3); printf("\n");
	}
	return 0;
}