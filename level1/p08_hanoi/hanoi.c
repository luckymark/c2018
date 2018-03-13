#include <stdio.h>
#include <conio.h>
#include <windows.h>
int tashu=4;
int movenum=0;
void printta(int);
void printallta(int (*ta)[2]);
void printjt(int);
void verticalmove(char,int,int[],int[][2]);
int start(void);
int judge(int[][2]);
int main(void){
	int ta[7][2]={{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0}};
	int zhu[]={0,-1,-1,-1};
	int jiantou=0;
	char a='e';
	tashu=start();
	system("cls");
	printf("                 已移动%d次\n",movenum); 
	printallta(ta);
	printjt(jiantou);
	
	while(a!='q'){
		system("color 07");
		a=getch();
		if(a=='a'&&jiantou>0){
			if(zhu[3]!=-1){ 
			ta[zhu[3]][1]--;
			}
			jiantou--;
		}
		else if(a=='d'&&jiantou<2){
			if(zhu[3]!=-1){
				ta[zhu[3]][1]++;
				
			}
			jiantou++;
		}
		else verticalmove(a,jiantou,zhu,ta);
		system("cls");
		printf("                 已移动%d次\n",movenum); 
		printallta(ta);
		printjt(jiantou);
		if(zhu[3]==-1&&judge(ta)){
			movenum=0;
			jiantou=0;
			zhu[0]=0;
			zhu[1]=zhu[2]=-1;
			system("cls");
			printf("                 已移动%d次\n",movenum); 
			printallta(ta);
			printjt(jiantou);
		}
	}
	return 0;	
}
void printallta(int (*ta)[2]){
	int i,j,k;
	int flag=0;
	
	for(i=0;i<3;i++){
		for(j=0;j<tashu;j++){
			if(ta[j][0]==-1&&ta[j][1]==i){
				printta(j+1);
				flag=1;
				break;
			}
				
		}
		if(flag==0)
			printf("                  ");
		flag=0;
			
	}
	printf("\n\n\n");
	for(j=0;j<tashu;j++){
		for(i=0;i<3;i++){
			for(k=0;k<tashu;k++){
				if(ta[k][0]==j&&ta[k][1]==i){
				
					printta(k+1);
					flag=1;
				}		
			}
			if(flag==0)
				printf("          |       ");
			flag=0;
		}
		printf("\n");
	}
	for(i=0;i<3;i++){
		printf("   =======|=======");
	}
	printf("\n\n\n");
	
}
void printta(int j){
	int k;
	for(k=0;k<(10-j);k++)
		printf(" ");
	for(k=0;k<(2*j+1);k++)
		printf("A");
	for(k=0;k<(7-j);k++)
		printf(" ");
}
void printjt(int jiantou){
	if(jiantou==0){
		printf("          *       \n");
		printf("         ***      \n");
		printf("        *****     \n");
		printf("         |*|      \n");
		printf("         |*|      \n");
		printf("         |*|      \n");
	}
	else if(jiantou==1){
		printf("                            *       \n");
		printf("                           ***      \n");
		printf("                          *****     \n");
		printf("                           |*|      \n");
		printf("                           |*|      \n");
		printf("                           |*|      \n");	
	}
	else if(jiantou==2){
		printf("                                              *       \n");
		printf("                                             ***      \n");
		printf("                                            *****     \n");
		printf("                                             |*|      \n");
		printf("                                             |*|      \n");
		printf("                                             |*|      \n");	
	}	
	
}
void verticalmove(char a,int jiantou,int* zhu,int (*ta)[2]){
	int i;
	
	if(a=='w'&&zhu[3]==-1){
		ta[zhu[jiantou]][0]=-1;
		zhu[3]=zhu[jiantou];
		zhu[jiantou]=-1;
		for(i=zhu[3]+1;i<tashu;i++){
			if(ta[i][1]==jiantou){
				zhu[jiantou]=i;
				break;
			}
			
		}
		
	}
	else if(a=='s'&&zhu[3]!=-1){
		if(zhu[3]<zhu[jiantou]){
			ta[zhu[3]][0]=ta[zhu[jiantou]][0]-1;
			zhu[jiantou]=zhu[3];
			zhu[3]=-1;
			movenum++;
		}
		else if(zhu[jiantou]==-1){
			ta[zhu[3]][0]=tashu-1;
			zhu[jiantou]=zhu[3];
			zhu[3]=-1;
			movenum++;
		}
		
	}
}
int start(void){
	int number;
	printf("\n\n\n\n\n                         请输入塔的层数(1~7)\n"); 
	while(1){
		scanf("%d",&number);
		if(number<8&&number>0)
			return number;
	}
}
int judge(int (*ta)[2]){
	int i;
	int j=1; 
	for(i=0;i<tashu;i++){
		if(ta[i][1]!=2)
		   return 0;
	}
	for(i=0;i<tashu;i++)
		j=j*2;
	j--;
	system("cls");
	system("color 06");
	printf("\n\n\n\n                                你赢了！");
	printf("共计%d步，理论最佳%d步",movenum,j);
	for(i=0;i<tashu;i++){
		ta[i][1]=0;
	}
	tashu=start();
	return 1;
}

