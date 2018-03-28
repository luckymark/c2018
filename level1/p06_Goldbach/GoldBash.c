#include<stdio.h>
#include<math.h>
char judge(int a);
int Prime(int b);
int m,n;
int main(void)
{
	int number,i;
	for(i=2;i<101;i+=2)
		{
			judge(i);
			printf("%d+%d=%d\n",m,n,i);
		}
	return 0;
}
char judge(int a)
{
	for(m=1;m<a/2+1;m++)
	{
		n=a-m;
		if(Prime(m)&&Prime(n))
		return;
	}
	return;
}
int Prime(int b)
{
	int i;
	for(i=2;i<sqrt(b);i++)
		if(b%i==0)
		{
			return 0;
		}
		else if((i+1)*(i+1)>b)
		{
			return 1;
		}

}
