#include <stdio.h>
#include <math.h>

#define eps 1e-9

double x;
int main()
{
	//x=1/6x+1/12x+1/7x+5+1/2x+4
	for(x=1;x<=200;x++)
	{
		if(fabs(x/6+x/12+x/7+5+x/2+4-x)<eps)
		printf("%d\n",(int)x);
	}

	return 0;
}
