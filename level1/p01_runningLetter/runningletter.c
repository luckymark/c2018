# include <stdio.h>
# include <stdlib.h>
# include <Windows.h>

# define WAITTIME 40
# define LENGTH 75

void print_space(int cnt);
int main(void)
{
	int cnt;
	int a, b, c;
	for(cnt = 0;; cnt++)
	{
		a = cnt % LENGTH;
		b = (cnt / LENGTH) % 2;
		c = abs(LENGTH * b - a);
		print_space(c);
		printf("R");
		Sleep(WAITTIME);
		system("cls");
	}
}
void print_space(int cnt)
{
	int temp;
	for(temp = 0; temp < cnt; temp++)
	{
		printf(" ");
	}
}
