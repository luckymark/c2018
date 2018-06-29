#include<stdio.h>
int main()
{
	int hanoi(int);
	int a, steps;
	printf("plese input the number of gold disks: \n");
	scanf("%d", &a);
	steps = hanoi(a);
	printf("the sum of steps is:\n %d", steps);
	return 0;
}
int hanoi(int x)
{
	int Step;
	if (x == 1) Step = 1;
	else Step = 2 * hanoi(x - 1) + 1;
	return Step;
}