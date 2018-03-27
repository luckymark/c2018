#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);

int main() {
	for (int i = 4; i <= 100; i += 2) {
		for (int j = 2; j <= i; ++j) {
			int p1 = isPrime(j);
			int flag=0;
			for (int k = 2; k <= i; ++k) {
				int p2 = isPrime(k);
				if (p1+p2==i)
				{
					printf("%d=%d+%d\n", i, p1 ,p2);
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}
	system("pause");
}

int isPrime(int n) {
	int i;
	float max = sqrt(n);
	for (i = 2; i <= max; ++i) {
		if (n%i == 0) {
			return 0;
		}
	}
	if (i > max) {
		return n;
	}
}