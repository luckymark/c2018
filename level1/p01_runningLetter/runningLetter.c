#include <stdio.h>
#include <windows.h>

#define WINDOW_WIDTH 76

void move(int dir)
{
	int i,j;
	for(i=1;i<=WINDOW_WIDTH;i++)
	{
		Sleep(1);
		system("cls");
		if(dir==1)
		{
			for(j=1;j<=i;j++)
			{
				printf(" ");
			} 
			printf("test");
		}
		if(dir==-1)
		{
			for(j=WINDOW_WIDTH-i;j>=1;j--)
			{
				printf(" ");
			} 
			printf("test");
		}
		
	}
}
int main()
{
	printf("test"); 
	for(;;)
	{
	  	move(1);
		move(-1); 
	}
	return 0;
}


