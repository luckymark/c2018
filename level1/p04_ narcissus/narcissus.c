//narcissus
#include <stdio.h>

int main ()
{
	printf("三位数的水仙花数有\n");
	int n1,n2,n3;
	int i;
	for (i=100;i<1000;i++) {
		n1=(int)i/10/10;
		n2=(int)i/10-n1*10;
		n3=i-100*n1-10*n2;
		if (i==n1*n1*n1+n2*n2*n2+n3*n3*n3) {
			printf("%d\n",i);
		}
	}
	return 1;
}
