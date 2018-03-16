#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	long long i;
	long long number;
	scanf_s("%lld", &number);
	if (number <= 2) {
		printf("Please enter an integer greater than 2");
	}
	else {
		for (i = 2; i <= sqrt(number); ++i) {
			if (number %i == 0) {
				printf("This is not a prime number");
				break;
			}
		}
		if (i > sqrt(number)) {
			printf("This is a prime number");
		}
	}
	system("pause");
}