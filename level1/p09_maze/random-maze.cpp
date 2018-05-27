#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#define ROW 39														//�Թ����� 
#define COL 39														//�Թ����� 
#define DOWN 46														//��������ƶ�ָ��ʱ����λ�� 

typedef struct _SITE {												//�Զ�����������SITE 

INT X;

INT Y;

} SITE;

int main(){
	void output(int (*p)[COL],int x,int y,char ch);					//�������� 
	void originalmaze(int (*p)[COL]);
	void makemaze(int (*p)[COL], int *px, int *py);
	void replace(int (*p)[COL]);
	int destination(int (*p)[COL]);
	void move(int (*p)[COL],char ch,int *px,int *py);
	void print(int *p);
	void goto_xy(int,int);
	
	int x = 0, y = 0, desti;												//������� 
	int *px = &x, *py = &y;
	int maze[ROW][COL];
	int (*p)[COL] = maze;
	char m;
	
	originalmaze(p);
	makemaze(p,px,py);
	replace(p);
	desti = destination(p);
	
	output(p,x,y,'w');												//�Թ�ʵ�� 

	m = getch();
	while (1){
		move(p,m,px,py);
		if (maze[0][desti] == 64){
			break;
		}
		m = getch();
	}
	printf("Congratulations!\n");
	system("pause");
	return 0;
}

void print(int *p){													//����Թ����� 
	printf("\n");
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			printf(" ");
			printf("%c",*p);
		}
		printf("\n");
	}
		
	printf("�Թ�С��Ϸ\n");
	printf("ͼ����\n");
	printf("%c --ǽ��, %c --����\n",35,64);
	printf("����w, a, s, d�ƶ�����\n");
	printf("w -- ����, a -- ����, s -- ����, d -- ����\n");
	
}

void goto_xy(int x,int y){										//��λ���λ�õ�ָ������
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void originalmaze(int (*p)[COL]){									//��ʼ���Թ����� 
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if ((i%2) == 0){
				*(*(p+i)+j) = 0;
			}
			else{
				if (j != 0 && j != (COL-1)){
					if (*(*(p+i)+(j-1)) == 0){
						*(*(p+i)+j) = 1;
					}
					else {
						*(*(p+i)+j) = 0;
					}
				}
				else{
					*(*(p+i)+j) = 0;
				}
			}
		}
	}
}


//������Թ�����˼·���ͬ�������ĵ� --������ 

//�˺�����������Թ� 
void makemaze(int (*p)[COL], int *px, int *py){						//2x --��ɫx , 3x -- ��ɫx
	int x = ROW-2, y = *py, x0, y0, r1, r2;
	SITE randblue = {0,0};
	
	void mark(int (*p)[COL],int x,int y);							//�������� 
	SITE randchoose(int (*p)[COL],int *px,int *py);
	int judire(int (*p)[COL],int *px,int *py);
	
    srand((unsigned int)time(NULL));
    r1 = (rand()%((COL-1)/2) +1)*2 -1;								//����2-COL ֮������ż�� 
    *(*(p+x)+r1) = 21;												//���ȡһ����ͼ��Ե��1���������Ϊ��ɫ1
    y = r1;
    x0 = x; y0 = y;													//��¼�Թ�������� 
    
    mark(p,x,y);													//�Ѻ�ɫ1�Աߵ�0��ǳ���ɫ0����ʾ"����"
    randblue = randchoose(p,px,py);									//���ѡһ����ɫ0
    while (1){
    	if (randblue.X != 0 && randblue.Y != 0){
	    	*px = randblue.X; *py = randblue.Y;
	    	x = *px; y = *py;
	    	
			int direction = judire(p,px,py);						//���ú����ж���ɫ0���ĸ�������1, ����ֵ:1-��, 2-��, 3-��, 4-�� 
			switch (direction){
				case 1:{
					*(*(p+x)+(y-1)) = 21;
					*(*(p+x)+y) = 20;
					y--; *py = y;
					break;
				}
				case 2:{
					*(*(p+x)+(y+1)) = 21;
					*(*(p+x)+y) = 20;
					y++; *py = y;
					break;
				}
				case 3:{
					*(*(p+(x-1))+y) = 21;
					*(*(p+x)+y) = 20;
					x--; *px = x;
					break;
				}
				case 4:{
					*(*(p+(x+1))+y) = 21;
					*(*(p+x)+y) = 20;
					x++; *px = x;
					break;
				}
				default:;
			}
			mark(p,x,y);
			randblue = randchoose(p,px,py);
    	}
    	else {
    		*(*(p+x0)+y0) = 41;
    		*px = x0+1; *py = y0;								//���������¶�λ���Թ���� 
    		break;
    	}
    }
    
}

void replace(int (*p)[COL]){									//�����ɵ��Թ������ַ������滻��������� 
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (*(*(p+i)+j) == 0){
				*(*(p+i)+j) = 35;
			}
			if (*(*(p+i)+j) == 41){
				*(*(p+(i+1))+j) = 64;
				*(*(p+i)+j) = 32;
			}
			if (*(*(p+i)+j) == 21 || *(*(p+i)+j) == 20){
				*(*(p+i)+j) = 32;
			}
		}
	}
}

int destination(int (*p)[COL]){							//�����Թ����� 
	int r;
	srand((unsigned int)time(NULL));
	r = rand()%(COL-3) +1;
	while (*(*(p+1)+r) != 32){
		r = rand()%(COL-3) +1;
	}
	*(*(p)+r) = 32;
	return r;
}

void mark(int (*p)[COL],int x,int y){						//�Ѻ�ɫ1�Աߵ�0��ǳ���ɫ0����ʾ"����"
	if (*(*(p+x)+y) == 21){
		if ((y-1) != 0 && *(*(p+x)+(y-1)) == 0){
			*(*(p+x)+(y-1)) = 30;
		}
		if ((y+1) != (COL-1) && *(*(p+x)+(y+1)) == 0){
			*(*(p+x)+(y+1)) = 30;
		}
		if ((x-1) != 0 && *(*(p+(x-1))+y) == 0){
			*(*(p+(x-1))+y) = 30;
		}
		if ((x+1) != (ROW-1) && *(*(p+(x+1))+y) == 0){
			*(*(p+(x+1))+y) = 30;
		}
	}
}

SITE randchoose(int (*p)[COL],int *px,int *py){				//���ѡһ����ɫ0
	SITE blue[ROW*COL];
	int k = 0, r;
	for (int i = 1; i < (ROW-1); i++){
		for (int j = 1; j < (COL-1); j++){
			if (*(*(p+i)+j) == 30){
				blue[k] = {i,j};
				k++;
			}
		}
	}
	if (k != 0){
		srand((unsigned int)time(NULL));
		r = rand()%k;
		*px = blue[r].X;
		*py = blue[r].Y;
		return blue[r];
	}
	else {
		 SITE over = {0,0};
		 return over;
	}
}

int judire(int (*p)[COL],int *px,int *py){					//�ж��ĸ�������1; ����ֵ:1-��, 2-��, 3-��, 4-�� 
	int x = *px; int y = *py;
	if (*(*(p+x)+(y+1)) == 21 && *(*(p+x)+(y-1)) == 1){
		return 1;
	}
	else if (*(*(p+x)+(y-1)) == 21 && *(*(p+x)+(y+1)) == 1){
		return 2;
	}
	else if (*(*(p+(x+1))+y) == 21 && *(*(p+(x-1))+y) == 1){
		return 3;
	}
	else if (*(*(p+(x-1))+y) == 21 && *(*(p+(x+1))+y) == 1){
		return 4;
	}
	else {
		*(*(p+x)+y) = 0;
		return 0;
	}
}


void output(int (*p)[COL],int x,int y,char ch){				//ʵ������ƶ� 
	
	if (ch == 'w'){
		*(*(p+x)+y) = 64;
		system("cls");
		print((int *) p);
		goto_xy(0,DOWN);
	}
	else {
		*(*(p+x)+y) = 32;
		system("cls");
		print((int *) p);
		goto_xy(0,DOWN);
	}
}

int isWall(int (*p)[COL],int x,int y){						//�ж�����ƶ�λ���Ƿ�Ϊǽ�� 
	if (*(*(p+x)+y) == 32){
		return 0;
	}
	else return 1;
}

void move(int (*p)[COL],char ch,int *px,int *py){			//ʵ������ƶ� 
	int x = *px, y = *py;
	switch (ch){
		case 'w':
			if (isWall(p,x-1,y) == 0){
				output(p,x,y,'b');
				output(p,x-1,y,'w');
				*px = x-1;
			}
			break;
		case 'a':
			if (isWall(p,x,y-1) == 0){
				output(p,x,y,'b');
				output(p,x,y-1,'w');
				*py = y-1;
			}
			break;
		case 's':
			if (isWall(p,x+1,y) == 0){
				output(p,x,y,'b');
				output(p,x+1,y,'w');
				*px = x+1;
			}
			break;
		case 'd':
			if (isWall(p,x,y+1) == 0){
				output(p,x,y,'b');
				output(p,x,y+1,'w');
				*py = y+1;
			}
			break;
		default:;
	}
}



