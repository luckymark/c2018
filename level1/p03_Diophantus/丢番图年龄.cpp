#include <stdio.h>
#include <stdlib.h>

int main()
{
	double diufantu_age;
	double d_son_age;
	for(diufantu_age=12.0; ;diufantu_age++)
	{
		d_son_age=diufantu_age/2;
		double sum=diufantu_age/6+diufantu_age/12+diufantu_age/7+5.0+4.0+d_son_age;
			if(diufantu_age==sum)
		{
			break;
		}
		
		
	}
	printf("diufantu's age is %-6.f",diufantu_age);
	return 0;
}
