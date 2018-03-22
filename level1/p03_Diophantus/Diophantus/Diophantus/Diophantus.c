#include<stdio.h>
#include<stdlib.h>
int main()
{
	for(int Text = 1; ;Text++)
	if ((Text * 12) % 7 == 0 && (Text * 2 + Text + (12 * Text) / 7 + 5 + 6 * Text + 4) == 12 * Text)
	{
		printf("¶ª·¬Í¼µÄÄêÁäÎª%d\n", Text * 12); break;
	}
	system("pause");
	return 0;
}