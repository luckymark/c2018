#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, p, a[30], k = 0, count = 0, b;
	for (n = 1; n <= 100; n++) {
		p = 0;
		for (i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				p = 1;
				break;
			}
		}
		if (p == 0) { a[k] = n; k++; }
	}
	for (n = 1; n <= 50; n++) {
		b = 0;
		for (i = 0; i<k; i++) {
			for (p = 0; p<k; p++) {
				if (a[i] + a[p] == 2 * n) {
					count++; b = 1;
				}
				if (b) break;
			}
			if (b) break;
		}
	}

	if (count == 50) printf("TURE\n");
	else printf("false");
	return 0;
}