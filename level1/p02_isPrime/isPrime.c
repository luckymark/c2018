//is_prime
#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int r_scanf=0;
	while (r_scanf!=1) {
		printf("����Ҫ���Ĵ���һ������\n");
		scanf("%d",&n);
		if (n<=1) {
			r_scanf=0;
		} else {
			r_scanf=1;
		}
	}
	for (int i=2; i<=(int)sqrt(n); i++) {
		if (n%i==0) {
			printf("��������\n");
			return 0;
		}
	}
	printf("������\n");
	return 1;
}
