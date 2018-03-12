#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c;
	int sum,num;
	
	for(a = 1; a <= 9; a++)
	{
		for(b = 0; b <= 9; b++)
		{
			for(c = 0; c <= 9; c++)
			{
				num = a * 100 + b * 10 + c;
				sum = a * a * a + b * b * b + c * c * c;
				if(num == sum)
					printf("%d\n", num);
			}
		}
	}
	return 0;
 } 
