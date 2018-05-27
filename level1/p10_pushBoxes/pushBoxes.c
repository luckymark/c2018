#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
	
int main(){
	void chooselevel(int *plevel);
	void showscore();
	void getrowcolaim(FILE *fin,int *prow,int *pcol,int *paim);
	void creatmap(FILE *fin,int *p,int row,int col);
	void output(int *p,int x,int y,int n,int COL);							//�������� 
	int getmove(int *p,char ch,int *px,int *py,int ROW,int COL);
	void print(int *p,int ROW,int COL);
	void findplayer(int *p,int *px,int *py,int ROW,int COL);
	void goto_xy(int,int);
	int gameover(int *p,int ROW,int COL,int AIM);
	void savescores(FILE *fout,int steps);
	
	int x = 0,y = 0;														//������� 
	int *px = &x,*py = &y;
	
	char m;
	
	int row, col, aim;
	int *prow = &row, *pcol = &col, *paim = &aim;
	
	FILE *fin,*fout;
	
	int level;
	int *plevel = &level;
	
	chooselevel(plevel);													//����ѡ�غ��� 
	while (1){
		switch (level){
			case 0:{												//���ú����鿴��¼
				showscore();
				system("pause");
				system("cls");
				chooselevel(plevel);
			}
			case 1:{														//�򿪶�Ӧ�ؿ��ļ� 
				if ((fin = fopen("map1.dat","r+")) == NULL) {
					printf("Can't open this map!\n");
					exit(0);
				}
				if ((fout = fopen("score1.dat","a+")) == NULL) {
					printf("Can't read the scores!\n");
					exit(0);
				}
				break;
			}
			case 2:{
				if ((fin = fopen("map2.dat","r+")) == NULL) {
					printf("Can't open this map!\n");
					exit(0);
				}
				if ((fout = fopen("score2.dat","a+")) == NULL) {
					printf("Can't read the scores!\n");
					exit(0);
				}
				break;
			}
			default:;
		}
		if (level != 0){
			break;
		}
	}
	
	
	getrowcolaim(fin,prow,pcol,paim);									//��ȡ��ͼ����,������������ 
	
	const int ROW = row, COL = col, AIM = aim;							//������Ӧ�Ĵ�С���� �� �����ͼ���� 
	int map[ROW][COL];
	int *p = &map[0][0];
	creatmap(fin,&map[0][0],ROW,COL);
	
	
	print(&map[0][0],ROW,COL);      									//�����ͼ 
	findplayer(&map[0][0],px,py,ROW,COL);								//��λ��ҳ�ʼ���� 
	goto_xy(0,ROW+9);
	
	int steps = 0;														//�˱�����¼��Ҳ��� 
	
	m = getch();
	while (1){
		
		if (m == 'q') {													//���� q �˳���Ϸ 
			printf("Game Over!\n");
			system("pause");
			exit(0);
		}
		
		int temp = getmove(p,m,px,py,ROW,COL);							//���ÿ����������һ����������+1
		if (temp == 1){
			steps++;
		}
		goto_xy(0,ROW+9);
		printf("���߲���:%d\n",steps);	
		
		if (gameover(&map[0][0],ROW,COL,AIM) == 0){						//����ȫ������Ŀ�ĵ�,��Ϸ���� 
			break;
		}
		
		m = getch();
	}
	printf("Congratulations!\n");										//��β���� 
	savescores(fout,steps);												//����ɼ� 
	fclose(fin);														//�ر��ļ� 
	fclose(fout);
	system("pause");
	return 0;
}

void chooselevel(int *plevel) {											//ѡ�غ��� 
	printf("������С��Ϸ\n");
	printf("���� 0 �鿴��¼  1,2... ѡ��\n");
	
	scanf("%d",plevel);
	system("cls");
	
}

void showscore(){														//�Ӷ�Ӧ�ļ��ڶ����¼ 
	printf("����������鿴��¼�Ĺؿ�:\n");
	int n;
	scanf("%d",&n);
	FILE *fscore;
	switch(n){
		case 1:{
			if ((fscore = fopen("score1.dat","r")) == NULL) {
				printf("Can't read your score!\n");
				exit(0);
			}
			break;
		}
		case 2:{
			if ((fscore = fopen("score2.dat","r")) == NULL) {
				printf("Can't read your score!\n");
				exit(0);
			}
			break;
		}
		default:;
	}
	rewind(fscore);
	
	while(!feof(fscore)){
		putchar(getc(fscore));
	}
	putchar(10);		//���һ���ո� 
}

void getrowcolaim(FILE *fin,int *prow,int *pcol,int *paim){				//���ļ��ж����ͼ����,������������ 
	int row,col,aim;
	fscanf(fin,"%d,%d,%d,",&row,&col,&aim);
	*prow = row; *pcol = col; *paim = aim;
}

void creatmap(FILE *fin,int *p,int row,int col){						//���ļ��ж����ͼ���� 
	
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			fscanf(fin,"%d,",(p+(i*col)+j));
		}
	}
}

void print(int *p,int ROW,int COL){												//�����ͼ���� 
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			printf(" ");
			printf("%c",*p);
		}
		printf("\n");
	}
		
	printf("\n������С��Ϸ\nͼ��:\n");
	printf("%c --�յ�, %c --ǽ��, %c --δ��Ŀ�ĵ�����, %c --Ŀ�ĵ�, %c --���, %c --�ѵ�Ŀ�ĵ�����\n",32,35,88,79,64,85);
	printf("����w, a, s, d�ƶ�����\n");
	printf("w -- ����, a -- ����, s -- ����, d -- ����\n");
	printf("���� q �˳���Ϸ\n");
}

void goto_xy(int x,int y){									//��λ���λ�õ�ָ������
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void findplayer(int *p,int *px,int *py,int ROW,int COL){					//��λ��ҳ�ʼ���� 
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			if (*p == 64){
				*px = i; 
				*py = j;
				return;
			}
		}
	}
}


int isBox(int *p,int x,int y,int COL){						//�ж�λ��(x,y)�Ƿ�Ϊ���� 
	if (*(p+(x*COL)+y) == 88){
		return 10;
	}
	else if (*(p+(x*COL)+y) == 85){
		return 11;
	}
	else return 0;
}

int isStop(int *p,int x,int y,int COL){						//�ж���һ���Ƿ���ƶ���λ��(x,y)
	if (*(p+(x*COL)+y) == 32 || *(p+(x*COL)+y) == 79){
		return 0;
	}
	else return 1;
}

int isDesti(int *p,int x,int y,int COL){						//�ж�λ��(x,y)�Ƿ�ΪĿ�ĵ� 
	if (*(p+(x*COL)+y) == 79){
		return 1;
	}
	else return 0;
}

void judge(int *p,int *pr,char ch,int x,int y,int COL){		//�жϺ������ж���Ҽ����ƶ��ķ��� ������� 
	int x0 = x, y0 = y;										//�����жϽ�����ص�move������result������ 
	switch(ch){
		case 'w':{
			x-=1;
			*pr = isBox(p,x,y,COL);				//�ж����ǰ���Ƿ�Ϊ���� 
			if(*pr == 10){					//��һ���жϣ���������ʲô���� 
				x-=1;						//�����δ��Ŀ�ĵص����ӣ�x-1��������ĺ�����һ���ж� 
			}
			else if(*pr == 11){
				x-=1;
				*(pr+4) = 1;				//������ѵ�Ŀ�ĵص����ӣ����ؽ����result���飬��¼������״̬Ϊ �ѵ�Ŀ�ĵ� 
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;		//�жϼ����ƶ���λ���Ƿ���ƶ� 
			*pr = isDesti(p,x,y,COL);pr++;		//�жϼ����ƶ���λ���Ƿ�ΪĿ�ĵ� 
			
			if (*(p+(x0*COL)+y0) == 641){	//�ж���ҵ�ǰ�Ƿ�վ��Ŀ�ĵ��� 
				*pr = 1;
			}
			break;
		}
		case 'a':{
			y-=1;
			*pr = isBox(p,x,y,COL);
			if(*pr == 10){
				y-=1;
			}
			else if(*pr == 11){
				y-=1;
				*(pr+4) = 1;
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;
			*pr = isDesti(p,x,y,COL);pr++;
			
			if (*(p+(x0*COL)+y0) == 641){
				*pr = 1;
			}
			break;
		}
		case 's':{
			x+=1;
			*pr = isBox(p,x,y,COL);
			if(*pr == 10){
				x+=1;
			}
			else if(*pr == 11){
				x+=1;
				*(pr+4) = 1;
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;
			*pr = isDesti(p,x,y,COL);pr++;
			
			if (*(p+(x0*COL)+y0) == 641){
				*pr = 1;
			}
			break;
		}
		case 'd':{
			y+=1;
			*pr = isBox(p,x,y,COL);
			if(*pr == 10){
				y+=1;
			}
			else if(*pr == 11){
				y+=1;
				*(pr+4) = 1;
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;
			*pr = isDesti(p,x,y,COL);pr++;
			
			if (*(p+(x0*COL)+y0) == 641){
				*pr = 1;
			}
			break;
		}
		default:;
	}
}

void output(int *p,int x,int y,int n,int COL){			//������������ݴ���������в�ͬ����� 
	switch(n){
		case 1:{							//��λ��(x,y)��� �յ� 
			*(p+(x*COL)+y) = 32;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 2:{							//��λ��(x,y)��� ��� 
			*(p+(x*COL)+y) = 64;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 3:{							//��λ��(x,y)��� վ��Ŀ�ĵ��ϵ���� 
			*(p+(x*COL)+y) = 641;
			goto_xy(2*y+1,x);
			printf("%c",64);
			break;
		}
		case 4:{							//��λ��(x,y)��� δ��Ŀ�ĵص����� 
			*(p+(x*COL)+y) = 88;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 5:{							//��λ��(x,y)��� �ѵ�Ŀ�ĵص����� 
			*(p+(x*COL)+y) = 85;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 6:{							//��λ��(x,y)��� Ŀ�ĵ� 
			*(p+(x*COL)+y) = 79;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
	}
}

void move(int *p,int *pr,int x,int y,int x1,int y1,int x2,int y2,int COL){
	//�ƶ�����,����result��������ݣ�����output��������Ӷ�ʵ������ƶ��������� 
		if (*pr == 0){								// 
			if(*(pr+2) == 0){						//result�������ݴ���ĺ���:��Ҽ����ƶ���λ�� ����� 
				if (*(pr+3) == 0){					//result[0]: �Ƿ�Ϊ���ӣ�0 --���ǣ�1 --�� 
					output(p,x,y,1,COL);			//result[1]: �Ƿ�Ϊ�ϰ��0 --���ǣ�1 --�� 
					output(p,x1,y1,2,COL);			//result[2]: �Ƿ�ΪĿ�ĵأ�0 --���ǣ�1 -- �� 
				}									//result[3]: ��ҵ�ǰλ���Ƿ�ΪĿ�ĵأ� 0 --���ǣ�1 --�� 
				else {								//result[4]: ���ӵ�ǰλ���Ƿ�ΪĿ�ĵأ� 0 --���ǣ�1 --�� 
					output(p,x,y,6,COL);
					output(p,x1,y1,2,COL);
				}
			}
			else {
				if (*(pr+3) == 0){
					output(p,x,y,1,COL);
					output(p,x1,y1,3,COL);
				}
				else {
					output(p,x,y,6,COL);
					output(p,x1,y1,3,COL);
				}
			}
		}
		else {
			if(*(pr+2) == 0){
				if (*(pr+3) == 0){
					if (*(pr+4) == 0){
						output(p,x,y,1,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,4,COL);
					}
					else {
						output(p,x,y,1,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,4,COL);
					}
				}
				else {
					if (*(pr+4) == 0){
						output(p,x,y,6,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,4,COL);
					}
					else {
						output(p,x,y,6,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,4,COL);
					}
				}
			}
			else {
				if (*(pr+3) == 0){
					if (*(pr+4) == 0){
						output(p,x,y,1,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,5,COL);
					}
					else {
						output(p,x,y,1,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,5,COL);
					}
				}
				else {
					if (*(pr+4) == 0){
						output(p,x,y,6,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,5,COL);
					}
					else {
						output(p,x,y,6,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,5,COL);
					}
				}
			}
		}
}

int getmove(int *p,char ch,int *px,int *py,int ROW,int COL){		//��������ƶ����򣬲�����move���������ƶ� 
	int x = *px, y = *py;
	int result[5] = {0,0,0,0,0};
	int *pr = &result[0];
	
	judge(p,pr,ch,x,y,COL);
	
	switch(ch){
		case 'w':{
			if ((x-1) != 0 && result[1] == 0){
				move(p,pr,x,y,x-1,y,x-2,y,COL);
				*px = x-1;
			}
			break;
		}
		case 'a':{
			if ((y-1) != 0 && result[1] == 0){
				move(p,pr,x,y,x,y-1,x,y-2,COL);
				*py = y-1;
			}
			break;
		}
		case 's':{
			if ((x+1) != (ROW-1) && result[1] == 0){
				move(p,pr,x,y,x+1,y,x+2,y,COL);
				*px = x+1;
			}
			break;
		}
		case 'd':{
			if ((y+1) != (COL-1) && result[1] == 0){
				move(p,pr,x,y,x,y+1,x,y+2,COL);
				*py = y+1;
			}
			break;
		}
		default :{
			return 0;
		}
	}
	if (((result[0]/10) == 1) && (result[1] == 0)) {
		return 1;
	}
	return 0;
} 


int gameover(int *p,int ROW,int COL,int AIM){									//�ж������Ƿ�ȫ������Ŀ�ĵ� 
	int count=0;
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			if (*p == 85){
				count++;
			}
		}
	}
	if (count == AIM){
		return 0;
	}
	else {
		return 1;
	}
}

void savescores(FILE *fout,int steps){											//������ҳɼ� 
	char name[20];
	int i = 0;
	printf("\n���������մ���(�� # ����):");
	name[0] = getchar();
	
	while (name[i] != '#'){
		fprintf(fout,"%c",name[i]);
		i++;
		name[i] = getchar();
		
	}
	fprintf(fout," : ");
	fprintf(fout,"%d ,\n",steps);
	printf("��ĳɼ��ѱ���!\n");
}

