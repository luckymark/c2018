#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a,b,x,y,r,t,num,stepnum;
int map_ONE[10][10], map_TWO[10][10];
int BOX_ONE_X,BOX_ONE_Y,BOX_TWO_X,BOX_TWO_Y,BOX_THREE_X,BOX_THREE_Y,BOX_FOUR_X,BOX_FOUR_Y,BOX_COUNT;

void plot(int m,int n);//根据当前位置绘制地图
void move();//当前位置移动操作
void judge(int n);//判断是否获胜并是否进入下一关
void map(int n);//选择使用的地图
void search(int n);//找寻当前人和箱子的位置并赋值

int main(int argc, char *argv[]) {
	int i,j;
	num = 1;
	r = 0;
	BOX_COUNT = 1;
	stepnum = 0;
	
	printf("Game start\n");
	printf("w is up, a is left, s is down, d is right, q is end\n");
	
	while(num <= 2){
		map(num);
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				map_TWO[i][j] = map_ONE[i][j];
			}
		}
		search(num);
		plot(stepnum,num);
		while(r != 1){
			move();
			plot(stepnum,num);
			search(num);
			if(r == 0){
				judge(stepnum);
			}
		}
	}
	return 0;
}

void plot(int m,int n){//根据当前位置绘制地图
	int i,j;
	system("cls");
	printf("Game start\n");
	printf("w is up, a is left, s is down, d is right, q is end, r is again\n");
	printf("Round %d\n", n);
	printf("Record: %d\n", m);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if(map_TWO[i][j] == 1){
				printf("■");
			}
			else if(map_TWO[i][j] == 0){
				printf("  ");
			}
			else if(map_TWO[i][j] == 9){
				printf("⊙");
			}
			else if(map_TWO[i][j] == 3){
				printf("★");
			}
			else if(map_TWO[i][j] == 5){
				printf("□");
			}
		}
		printf("\n");
	}
}

void move(){//当前位置移动操作 
	t = getch();
	switch (t){
		case 'w':{
			if(map_TWO[x-1][y] == 0 || map_TWO[x-1][y] == 9){
				x--;
				map_TWO[x][y] = 3;
				if(map_ONE[x+1][y] == 9){
					map_TWO[x+1][y] = 9;
				}else{
					map_TWO[x+1][y] = 0;
				}
				stepnum++;
			}
			else if(map_TWO[x-1][y] == 5){
				if(map_TWO[x-2][y] == 0 || map_TWO[x-2][y] == 9){
					x--;
					a = x-1; 
					map_TWO[x][y] = 3;
					map_TWO[a][y] = 5;
					if(map_ONE[x+1][y] == 9){
						map_TWO[x+1][y] = 9;
					}else{
						map_TWO[x+1][y] = 0;
					}
					stepnum++;
				}
			 } 
			break;
		}
		case 'a':{
			if(map_TWO[x][y-1] == 0 || map_TWO[x][y-1] == 9){
				y--;
				map_TWO[x][y] = 3;
				if(map_ONE[x][y+1] == 9){
					map_TWO[x][y+1] = 9;
				}else{
					map_TWO[x][y+1] = 0;
				}
				stepnum++;
			}
			else if(map_TWO[x][y-1] == 5){
				if(map_TWO[x][y-2] == 0 || map_TWO[x][y-2] == 9){
					y--;
					b = y-1;
					map_TWO[x][y] = 3;
					map_TWO[x][b] = 5;
					if(map_ONE[x][y+1] == 9){
						map_TWO[x][y+1] = 9;
					}else{
						map_TWO[x][y+1] = 0;
					}
					stepnum++;
				}
			}
			break;
		}
		case 's':{
			if(map_TWO[x+1][y] == 0 || map_TWO[x+1][y] == 9){
				x++;
				map_TWO[x][y] = 3;
				if(map_ONE[x-1][y] == 9){
					map_TWO[x-1][y] = 9;
				}else{
					map_TWO[x-1][y] = 0;
				}
				stepnum++;
			}
			else if(map_TWO[x+1][y] == 5){
				if(map_TWO[x+2][y] == 0 || map_TWO[x+2][y] == 9){
					x++;
					a = x+1;
					map_TWO[x][y] = 3;
					map_TWO[a][y] = 5;
					if(map_ONE[x-1][y] == 9){
						map_TWO[x-1][y] = 9;
					}else{
						map_TWO[x-1][y] = 0;
					}
					stepnum++;
				}
			} 
			break;
		}
		case 'd':{
			if(map_TWO[x][y+1] == 0 || map_TWO[x][y+1] == 9){
				y++;
				map_TWO[x][y] = 3;
				if(map_ONE[x][y-1] == 9){
					map_TWO[x][y-1] = 9;
				}else{
					map_TWO[x][y-1] = 0;
				}
				stepnum++;
			}
			else if(map_TWO[x][y+1] == 5){
				if(map_TWO[x][y+2] == 0 || map_TWO[x][y+2] == 9){
					y++;
					b = y+1;
					map_TWO[x][y] = 3;
					map_TWO[x][b] = 5;
					if(map_ONE[x][y-1] == 9){
						map_TWO[x][y-1] = 9;
					}else{
						map_TWO[x][y-1] = 0;
					}
					stepnum++;
				}
			} 
			break;
		}
		case 'q':{
            printf("Do you want to end the game?(y is yes)\n");  
            t = getch();
            if(t == 'y'){
           		exit(0);
			}
			break;
                }
        case 'r':{
        	printf("Again?(y is yes)\n");
        	t = getch();
        	if(t == 'y'){
        		r = 1;
			}
			break;
		}
        default:{
                puts("You touch a wrong key.\n");  
                break;  
            }  
	}
}

void judge(int n){//判断是否获胜并是否进入下一关
	int k = 0;
	int t;
	FILE *fp;
	fp = fopen("record.txt", "w+");
	fprintf(fp,"Record: %d\n", n);
	fclose(fp);
	if(map_ONE[BOX_ONE_X][BOX_ONE_Y] == 9 && map_ONE[BOX_TWO_X][BOX_TWO_Y] == 9 && map_ONE[BOX_THREE_X][BOX_THREE_Y] == 9 && map_ONE[BOX_FOUR_X][BOX_FOUR_Y] == 9){
		printf("You win!\n");
		printf("Next pass?(y is Yes and n is No)\n");
		while(k == 0){
			t = getch();
			if(t == 'y'){
				num++;
				k = 1;
			}
			else if(t == 'n'){
				num = 10;
				k = 1;
			}
			else{
				printf("You touch a wrong key.\n");
			}
			r = 1;
		}
	}
	else{
		r = 0;
	 } 
}

void map(int n){//选择使用的地图 
	int i,j;
	FILE *fp;
	
	r = 0;
	
	if(n == 1){
		fp = fopen("one.txt", "r");
		for(i = 0; i < 8; i++){
			for(j = 0;  j < 8; j++){
				fscanf(fp,"%d",&map_ONE[i][j]); 
			}
		}
		fclose(fp);
	}
	if(n == 2){
		fp = fopen("two.txt", "r");
		for(i = 0; i < 7; i++){
			for(j = 0;  j < 10; j++){
				fscanf(fp,"%d",&map_ONE[i][j]); 
			}
		}
		fclose(fp);
	}
}
void search(int n){//找寻当前人和箱子的位置并赋值
	int i,j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if(map_TWO[i][j] == 3){
				x = i;
				y = j;
			}
			else if(map_TWO[i][j] == 5){
				switch (BOX_COUNT){
					case 1:{
							BOX_ONE_X = i;
							BOX_ONE_Y = j;
							BOX_COUNT++;
							break;
						}
					case 2:{
							BOX_TWO_X = i;
							BOX_TWO_Y = j;
							BOX_COUNT++;
							break;
						}
					case 3:{
							BOX_THREE_X = i;
							BOX_THREE_Y = j;
							BOX_COUNT++;
							break;
						}
					case 4:{
							BOX_FOUR_X = i;
							BOX_FOUR_Y = j;
							BOX_COUNT = 1;
							break;
						}
					default:
						break;
				}
			}
		}
	}
}
