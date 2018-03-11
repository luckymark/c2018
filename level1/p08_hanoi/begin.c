#include<stdio.h>
#include<stdlib.h>
int a[3][10000];
int n,step;
void prints(int n,char c){
	while (n--)printf("%c",c);
}
void draw(){
	printf("\033c");
	printf("You have cost %d steps.\n",step);
	for (int i=n;i>=1;i--,printf("\n"))
		for (int j=0;j<3;j++){
			if (!a[j][i]){
				prints(n,' ');
				printf("|");
				prints(n,' ');
			}else{
				prints(n-a[j][i],' ');
				prints(a[j][i]*2+1,'#');
				prints(n-a[j][i],' ');
			}
		}
}
int check(){
	return !a[0][0]&&!a[1][0];
}
int main(){
	printf("Set the number of hanoi:");
	scanf("%d",&n);
	a[0][0]=n;
	for (int i=1;i<=n;i++)a[0][i]=n-i+1;
	do{
		draw();
		if (check()){
			break;
		}
		printf("Input your move:");
		int x,y;
		int sig=0;
		do{
			if (sig)
				printf("Illegal operation!Please input a legal move:");
			sig=1;
			scanf("%d %d",&x,&y);
			x--,y--;
		}while (!a[x][0]||(a[x][a[x][0]]>=a[y][a[y][0]]&&a[y][0]));		
		step++;
		a[y][++a[y][0]]=a[x][a[x][0]];
		a[x][a[x][0]]=0;
		a[x][0]--;
	}while (1);
	printf("You win!And you cost %d steps.",step);
	return 0;
}
