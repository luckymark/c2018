#include <stdio.h>
#include<time.h>/*和时间有关*/

int Prime(int value);

int main()
{
	int i;
	time_t start, end;
	start = clock();

	{for (i = 2; i <= 1000; i++)
		if (Prime(i))  /*调用判断素数函数*/
			printf("%d\n", i); }
	end =clock();
	
	printf("所耗费总时间为：%f\n", (double)end-start);
	system("pause");
	return 0;
}



int Prime(int value)
{
	int i;
	for (i = 2; i < value; i++)
		if (value % i == 0)
			return 0;
	
	return 1;
}