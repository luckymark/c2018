#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main() {
	int begin, end;
	begin = clock();
	int n=0;
	for (int i = 2; i <= 100; ++i) {
		int j;
		for (j = 2; j <= sqrt(i); ++j) {
			if (i%j == 0) {
				break;
			}
		}
		if (j>sqrt(i)) {
			n = n + 1;
		}
	}
	end = clock();
	printf("%d", n);
	printf("”√ ±£∫ %d ms", end - begin);
	system("pause");
}