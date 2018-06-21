#include<stdio.h>
int main(void)
{
	double age=20;
	for(age=20;age!=age/6+age/12+age/7+5+age/2+4;age++)
		printf("%f\n",age);
	printf("The age is %.0f",age);
	return 0;
}
