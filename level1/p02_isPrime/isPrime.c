//is_prime
#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int r_scanf=0;
	while (r_scanf!=1) {
		printf("输入要检测的大于一的整数\n");
		scanf("%d",&n);
		if (n<=1) {
			r_scanf=0;
		} else {
			r_scanf=1;
		}
	}
	for (int i=2; i<=(int)sqrt(n); i++) {
		if (n%i==0) {
			printf("不是素数\n");
			return 0;
		}
	}
	printf("是素数\n");
	return 1;
}
