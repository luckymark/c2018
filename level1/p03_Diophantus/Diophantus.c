#include <stdio.h>
int main(void)
{
	float X;
	for(X=1;;X++)
	{
		if(X-X/6-X/12-X/7-5-4==0.5*X)
        {
        	printf("His age is %.f.",X);
            break;
        }
	}
	getchar();
	return 0;
}
