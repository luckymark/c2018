#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(void)
{
	clock_t t1, t2;
	t1 = time(NULL);
	int x, i, k;
	float t;
	for (x = 2; x <= 1000; x++)
	{
		for (i = 2; i <= sqrt(x)||i<=3; i++ )
		{
			if (x%i == 0)
			{
				printf("%d\n", x);
				break;
			}
		}
		
	}
	
	t2 = time(NULL);
	t = (float)(t2 - t1);
	printf("time=%f", t);
	system("pause");
	return 0;
}