#include <stdio.h>
#include<stdlib.h>
void main()
{
	int i;
	for (i = 1;i<300; i++)
	{
		if (i*1.0 / 6 + i*1.0 / 12 + i*1.0/ 7+ 5 + 4 == i*1.0/ 2)
		{
			printf("¶ª·¬Í¼µÄÄêÁäÊÇ%d¡£", i);
			break;
		}
	}
	system("pause");
	return 0;
}