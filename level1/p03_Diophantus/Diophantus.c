#include <stdio.h>
int main(void)
{
	int i,j,c;
	int  a[10];
	for(i=0;i<10;i++)
	{
	  scanf("%d",&a[i]);
	}
	for(i=0;i<9;i++)
	for(j=0;j<10-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			c=a[j];
			a[j]=a[j+1];
			a[j+1]=c;
		}
	}
	for(i=0;i<10;i++)
	{
	
	printf("%3d",a[i]);
}
	return 0;
}
