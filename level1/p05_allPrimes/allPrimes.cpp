#include <stdio.h>
#include <time.h> 
#include <math.h>

int main()
{
	int i,j;
	int begin,end;
	
	begin = clock();

	for(i = 2; i <= 1000; i++)	
	{
		for(j = 2; j <= sqrt(i); j++)
		{
			if(i % j == 0)
				break;
		}
		if(sqrt(i) < j)
			printf("%d  ", i);
		else
			continue;
	}
	end = clock();
	printf("\n%f ms\n", double(end - begin));
	
	return 0;
 } 
