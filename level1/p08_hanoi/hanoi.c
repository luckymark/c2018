/*
解决思想
1.将A上面的n-1个通过B挪到C上
2.将A上的另一个盘移到B上
3.重复步骤即可实现
4.采用递归实现
*/
# include <stdio.h>

void move(int steps, char A, char B, char C);
int main(void)
{
	int steps;
	printf("请输入要移动的块数：");
	scanf("%d", &steps);
	move(steps, 'A', 'B', 'C');
}
void move(int steps, char A, char B, char C)
{
	if(steps == 1)
	{
		printf("%c --> %c\n", A, C);//当steps只有一个的时候直接从a移动到b上 
	} else
	{
		move(steps - 1, A, C, B);//第n-1个要从a通过b移动到c
		printf("%c --> %c\n", A, C);
		move(steps - 1, B, A, C);//n-1个移动自后c变成了初始，c通过a移动到c 
	}
}
