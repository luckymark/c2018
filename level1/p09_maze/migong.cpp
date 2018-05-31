#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int map[10][10]= {
    {3,1,3,3,3,3,3,3,3,3},   //1是人  2是路  3是墙  4是出口
	{3,2,2,2,3,2,2,2,3,3},
	{3,3,3,2,3,2,3,2,3,3},
	{3,2,2,2,3,2,3,2,3,3},
	{3,2,3,3,3,2,3,2,3,3},
	{3,2,2,2,2,2,3,2,3,3},
	{3,2,3,3,3,3,3,2,2,4},
	{3,2,3,2,3,2,2,2,3,3},
	{3,2,2,2,3,2,3,3,3,3},
	{3,3,3,3,3,3,3,3,3,3},

};


void MAP() {
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			switch(map[i][j]) {
				case 1:
					printf("♂");
					break;
				case 2:
					printf("  ");
					break;
				case 3:
					printf("■");
					break;
				case 4:
					printf("★");
					break;


			}
		}
		printf("\n");
	}
}
void rule() {
	//1是人  2是路  3是墙  4是出口
	char ch;
	int m,n;
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			if(map[i][j]==1) {
				m=i;
				n=j;
			}
		}
	}
	ch=getch();
	switch(ch) {
		case 'w':
		case 'W':
			if(map[m-1][n]==2) {
				map[m][n]=2;
				map[m-1][n]=1;
			} else if(map[m-1][n]=4) {
				map[m][n]=2;
				map[m-1][n]=1;
				printf("you win!\n");
				system("pause");
			}
			break;
		case 's':
		case 'S':
			if(map[m+1][n]==2) {
				map[m][n]=2;
				map[m+1][n]=1;
			} else if(map[m+1][n]==4) {
				map[m][n]=2;
				map[m+1][n]=1;
				printf("you win\n");
				system("pause");
			}
			break;
		case 'a':
		case 'A':
			if(map[m][n-1]==2) {
				map[m][n]=2;
				map[m][n-1]=1;
			} else if(map[m][n-1]==4) {             //1是人  2是路  3是墙  4是出口
				map[m][n]=2;
				map[m][n-1]=1;
				printf("you win!\n");
				system("pause");
				return;
			}
			break;

		case 'd':
		case 'D':
			if(map[m][n+1]==2) {
				map[m][n]=2;
				map[m][n+1]=1;
			} else if(map[m][n+1]==4) {
				map[m][n]=2;
				map[m][n+1]=1;
				printf("you win\n");
				system("pause");
				return;
			}

			break;

	}

}

int main() {
	while(1) {
		system("cls");
		MAP();
		rule();
	}
	return 0;
}
