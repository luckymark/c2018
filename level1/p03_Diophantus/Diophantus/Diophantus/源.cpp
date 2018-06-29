#include<stdio.h>

int main()

{

	float x;

	for (x = 1; x<100; x++) {

		if ((x / 6 + x / 12 + x / 7 + 5 + 4) == x / 2) break;

	}

	printf("%d", int(x));

	return 0;

}