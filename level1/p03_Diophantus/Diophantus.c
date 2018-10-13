#include <stdio.h>
#include <stdlib.h>

int main() {
	
	for (int i = 0; i <= 100; ++i) {
		int lt, lq, ld, t1, t2;
		t1 = 5;
		t2 = 4;
		if (i % 6 != 0 || i % 12 != 0 || i % 7 != 0) {
			continue;
		}
		lt = i / 6;
		lq = i / 12;
		ld = i / 7;
		int l1 = lt + lq + ld;
		if (l1+t1+i/2+4==i) {
			printf("%d\n", i - 4);
		}
	}
	system("pause");
}