#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int step=0;
int map[9][9]= {
	{3,3,3,3,3,2,2,2,2},   //1是人  2是路  3是墙  4是箱子  5是物品
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
					printf("♂");
					break;
				case 2:
					printf("  ");
					break;
				case 3:
					printf("■");
					break;
				case 4:
					printf("□");
					break;
				case 5:
					printf("☆");
					break;
				case 6:
					printf("□");
					break; 
				case 7:
					printf("♂");
					break;
				default:
					printf("error");


			}
		}
		printf("\n");
	}
	
}
void rule() { 
	//1是人  2是路  3是墙  4是箱子  5是物品   6是盖住物品的箱子   7盖住物品的人 
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
			if(map[m-1][n]==2) {                           //判断人物前方是否是路 
				map[m][n]=2;
				map[m-1][n]=1;
			}
			if(map[m-1][n]==5){                    //判断人物下一步是不是物品， 
				if(map[m][n]==7){                  //如果是物品且人物本身与物品重叠，则下一步为新的人物与物品重叠 
					map[m-1][n]=7;
					map[m][n]=5;
				}else if(map[m][n]==1){            // 若不是则下一步为新的人物与物品重叠，原来的地方变为路 
				map[m-1][n]=7;
				map[m][n]=2;
				} 
				
			}
			if(map[m-1][n]==4&&map[m-2][n]!=3&&map[m-2][n]!=4) {             //若下一步为箱子且下下一步不为墙也不为箱子 
				if(map[m-2][n]!=5) {                                         //若下下步不为物品，则下一步变为人物，下下步变为箱子，原来的地方变为路 
					map[m-1][n]=1;
					map[m-2][n]=4;
					map[m][n]=2;
				 
				} else if(map[m-2][n]==5) {                              // 若下下步为物品， 则下下步变为装物品的箱子，下一步变为人物，原来的位置变为路 
				
					map[m-2][n]=6;                                     	//1是人  2是路  3是墙  4是箱子  5是物品   6是盖住物品的箱子    7盖住物品的人
					map[m][n]=2;
					map[m-1][n]=1;
					
				} else if(map[m-1][n]==6) {                           // 若下一步为 装物品的箱子， 
					if(map[m-2][n]==5&&map[m][n]==1){                 //若下下步为物品且原位置为人物  则下一步为人物与物品重叠，下下步为装物品的箱子，原位置变为路 
					
					map[m-1][n]=7;
					map[m-2][n]=6;
					map[m][n]=2;
					
					} 
					else if(map[m-2][n]==5&&map[m][n]==7){           //若下下步为物品且原位置为与物品重叠的人，则下一步变为人物与物品重叠，下下步为装物品的箱子，原位置变为物品 
					map[m-1][n]=7;
					map[m-2][n]=6;
					map[m][n]=5;
						
					}
				}
			}
			if(map[m-1][n]==3) {               //若下一步为箱子 则下一步为箱子，原位置为人物 
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
				
					map[m+2][n]=6;                                     	//1是人  2是路  3是墙  4是箱子  5是物品   6是盖住物品的箱子    7盖住物品的人
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
				
					map[m][n-2]=6;                                     	//1是人  2是路  3是墙  4是箱子  5是物品   6是盖住物品的箱子    7盖住物品的人
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
				
					map[m][n+2]=6;                                     	//1是人  2是路  3是墙  4是箱子  5是物品   6是盖住物品的箱子    7盖住物品的人
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
