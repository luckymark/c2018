#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {

	int a, i, m;
	scanf("%d", &a);
	m = sqrt((double)a);
	for (i = 2; i <= m; i++)
		if (a%m == 0)
			break;
		else if (i <= m)
			printf("No!this is not a prime.");
		else
			printf("Yes,it is a prime.");



	system("pause");
	return 0;

}

