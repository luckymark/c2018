#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int step=0;
int map[9][9]= {
	{3,3,3,3,3,2,2,2,2},   //1����  2��·  3��ǽ  4������  5����Ʒ
	{3,2,2,1,3,2,2,2,2},
	{3,2,4,4,3,2,3,3,3},
	{3,2,4,2,3,2,3,5,3},
	{3,3,3,2,3,3,3,5,3},
	{2,2,3,2,2,2,2,5,3},
	{2,3,2,2,2,3,2,2,3},
	{2,3,2,2,2,3,3,3,3},
	{2,3,3,3,3,3,2,2,2},


};


void MAP() {
	system("cls");
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			switch(map[i][j]) {
				case 1:
					printf("��");
					break;
				case 2:
					printf("  ");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("��");
					break; 
				case 7:
					printf("��");
					break;
				default:
					printf("error");


			}
		}
		printf("\n");
	}
	
}
void rule() { 
	//1����  2��·  3��ǽ  4������  5����Ʒ   6�Ǹ�ס��Ʒ������   7��ס��Ʒ���� 
	char ch;
	int m,n;
	int over=0;
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(map[i][j]==1) {
				m=i;
				n=j;
			}
         	if(map[m][n]==6) {                         //change1       5.8    m n
				over++;
			}
		}
	}
	if(over==3) {
		printf("%d\n",step);
		printf("you win\n");

		return;
	}
	ch=getch();
	switch(ch) {
		case 'w':
		case 'W':
			step++;
			if(map[m-1][n]==2) {                           //�ж�����ǰ���Ƿ���· 
				map[m][n]=2;
				map[m-1][n]=1;
			}
			if(map[m-1][n]==5){                    //�ж�������һ���ǲ�����Ʒ�� 
				if(map[m][n]==7){                  //�������Ʒ�����ﱾ������Ʒ�ص�������һ��Ϊ�µ���������Ʒ�ص� 
					map[m-1][n]=7;
					map[m][n]=5;
				}else if(map[m][n]==1){            // ����������һ��Ϊ�µ���������Ʒ�ص���ԭ���ĵط���Ϊ· 
				map[m-1][n]=7;
				map[m][n]=2;
				} 
				
			}
			if(map[m-1][n]==4&&map[m-2][n]!=3&&map[m-2][n]!=4) {             //����һ��Ϊ����������һ����ΪǽҲ��Ϊ���� 
				if(map[m-2][n]!=5) {                                         //�����²���Ϊ��Ʒ������һ����Ϊ������²���Ϊ���ӣ�ԭ���ĵط���Ϊ· 
					map[m-1][n]=1;
					map[m-2][n]=4;
					map[m][n]=2;
				 
				} else if(map[m-2][n]==5) {                              // �����²�Ϊ��Ʒ�� �����²���Ϊװ��Ʒ�����ӣ���һ����Ϊ���ԭ����λ�ñ�Ϊ· 
				
					map[m-2][n]=6;                                     	//1����  2��·  3��ǽ  4������  5����Ʒ   6�Ǹ�ס��Ʒ������    7��ס��Ʒ����
					map[m][n]=2;
					map[m-1][n]=1;
					
				} else if(map[m-1][n]==6) {                           // ����һ��Ϊ װ��Ʒ�����ӣ� 
					if(map[m-2][n]==5&&map[m][n]==1){                 //�����²�Ϊ��Ʒ��ԭλ��Ϊ����  ����һ��Ϊ��������Ʒ�ص������²�Ϊװ��Ʒ�����ӣ�ԭλ�ñ�Ϊ· 
					
					map[m-1][n]=7;
					map[m-2][n]=6;
					map[m][n]=2;
					
					} 
					else if(map[m-2][n]==5&&map[m][n]==7){           //�����²�Ϊ��Ʒ��ԭλ��Ϊ����Ʒ�ص����ˣ�����һ����Ϊ��������Ʒ�ص������²�Ϊװ��Ʒ�����ӣ�ԭλ�ñ�Ϊ��Ʒ 
					map[m-1][n]=7;
					map[m-2][n]=6;
					map[m][n]=5;
						
					}
				}
			}
			if(map[m-1][n]==3) {               //����һ��Ϊ���� ����һ��Ϊ���ӣ�ԭλ��Ϊ���� 
				map[m-1][n]=3;
				map[m][n]=1;
			}
			break;
		case 's':
		case 'S':
			step++;
			if(map[m+1][n]==2) {
				map[m][n]=2;
				map[m+1][n]=1;
			}
			if(map[m+1][n]==5){
				if(map[m][n]==7){
					map[m+1][n]=7;
					map[m][n]=5;
				}else if(map[m][n]==1){
				map[m+1][n]=7;
				map[m][n]=2;
				} 
				
			}
			if(map[m+1][n]==4&&map[m+2][n]!=3&&map[m+2][n]!=4) {
				if(map[m+2][n]!=5) {
					map[m+1][n]=1;
					map[m+2][n]=4;
					map[m][n]=2;
				
				} else if(map[m+2][n]==5) {
				
					map[m+2][n]=6;                                     	//1����  2��·  3��ǽ  4������  5����Ʒ   6�Ǹ�ס��Ʒ������    7��ס��Ʒ����
					map[m][n]=2;
					map[m+1][n]=1;
					over++;
				} else if(map[m+1][n]==6) {
					if(map[m+2][n]==5&&map[m][n]==1){
					
					map[m+1][n]=7;
					map[m+2][n]=6;
					map[m][n]=2;
					
					} 
					else if(map[m+2][n]==5&&map[m][n]==7){
					map[m+1][n]=7;
					map[m+2][n]=6;
					map[m][n]=5;
						
					}
				}
			}
			if(map[m+1][n]==3) {
				map[m+1][n]=3;
				map[m][n]=1;
			}
			break;
		case 'a':
		case 'A':
			step++;
			if(map[m][n-1]==2) {
				map[m][n]=2;
				map[m][n-1]=1;
			}
			if(map[m][n-1]==5){
				if(map[m][n]==7){
					map[m][n-1]=7;
					map[m][n]=5;
				}else if(map[m][n]==1){
				map[m][n-1]=7;
				map[m][n]=2;
				} 
				
			}
			if(map[m][n-1]==4&&map[m][n-2]!=3&&map[m][n-2]!=4) {
				if(map[m][n-2]!=5) {
					map[m][n-1]=1;
					map[m][n-2]=4;
					map[m][n]=2;
				
				} else if(map[m][n-2]==5) {
				
					map[m][n-2]=6;                                     	//1����  2��·  3��ǽ  4������  5����Ʒ   6�Ǹ�ס��Ʒ������    7��ס��Ʒ����
					map[m][n]=2;
					map[m][n-1]=1;
					over++;
				} else if(map[m][n-1]==6) {
					if(map[m][n-2]==5&&map[m][n]==1){
					
					map[m][n-1]=7;
					map[m][n-2]=6;
					map[m][n]=2;
					
					} 
					else if(map[m][n-2]==5&&map[m][n]==7){
					map[m][n-1]=7;
					map[m][n-2]=6;
					map[m][n]=5;
						
					}
				}
			}
			if(map[m][n-1]==3) {
				map[m][n-1]=3;
				map[m][n]=1;
			}
			break;
		case 'd':
		case 'D':
			step++;
			if(map[m][n+1]==2) {
				map[m][n]=2;
				map[m][n+1]=1;
			}
			if(map[m][n+1]==5){
				if(map[m][n]==7){
					map[m][n+1]=7;
					map[m][n]=5;
				}else if(map[m][n]==1){
				map[m][n+1]=7;
				map[m][n]=2;
				} 
				
			}
			if(map[m][n+1]==4&&map[m][n-2]!=3&&map[m][n+2]!=4) {
				if(map[m][n+2]!=5) {
					map[m][n+1]=1;
					map[m][n+2]=4;
					map[m][n]=2;
				
				} else if(map[m][n+2]==5) {
				
					map[m][n+2]=6;                                     	//1����  2��·  3��ǽ  4������  5����Ʒ   6�Ǹ�ס��Ʒ������    7��ס��Ʒ����
					map[m][n]=2;
					map[m][n+1]=1;
					over++;
				} else if(map[m][n+1]==6) {
					if(map[m][n+2]==5&&map[m][n]==1){
					
					map[m][n+1]=7;
					map[m][n+2]=6;
					map[m][n]=2;
					
					} 
					else if(map[m+2][n]==5&&map[m][n]==7){
					map[m][n+1]=7;
					map[m][n+2]=6;
					map[m][n]=5;
						
					}
				}
			}
			if(map[m][n+1]==3) {
				map[m][n+1]=3;
				map[m][n]=1;
			}
			break;
	
	}


}

int main() {
	while(1) {
		MAP();
		rule();
	}
	return 0;
}
