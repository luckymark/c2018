# include <stdio.h>
# include <math.h>

int judge(int n)
{
	int unit,tens,hundreds,m=n;
	hundreds=n/100;
	n-=hundreds*100;
	tens=n/10;
	unit=n-tens*10;
	if ((pow(unit,3)+pow(tens,3)+pow(hundreds,3))==m)
	{
		return 1;
	}
	else return 0;
}

int main()
{
	int i;
	for (i=100;i<1000;i++)
	{
		if(judge(i)==1)
		{
			printf("%-4d",i);
		}
		else continue;
	}
	return 0;
}
