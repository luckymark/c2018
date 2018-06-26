#include <stdio.h>
#include <stdlib.h>
void hanoi(int n, char sour, char mid, char dest)
{
	if (n == 1) {
		printf("%c -> %c\n", sour, dest);
		return;

	}
	hanoi(n - 1, sour, dest, mid);
	printf("%c -> %c\n", sour, dest);
	hanoi(n - 1, mid, sour, dest);
}
int main()
{
	int n;
	scanf_s("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	system("pause");
	return 0;
}