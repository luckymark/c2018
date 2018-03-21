#include<stdio.h>

#include<math.h>

int main()

{

	int n, i, p = 0;

	scanf("%d", &n);

	for (i = 2; i <= sqrt(n); i++) {

		if (n%i == 0) {

			p = 1;

			break;
		}

	}

	if (p) printf("not is Prime");

	else printf("isPrime");

	return 0;

}