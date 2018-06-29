#include<stdio.h>

int main()

{

	int pow(int);

	int x, a, b, c, d;

	for (x = 100; x<1000; x++) {

		a = x / 100; b = x % 100;

		c = b / 10; d = b % 10;

		if ((pow(a) + pow(c) + pow(d)) == x) printf("%d\n", x);



	}

	return 0;

}

int pow(int i)

{

	int p = i * i*i;

	return p;

}