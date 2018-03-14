#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%(x))
#define N 1000
int n,m,step,noise;
char map[N*2][N*2];
int d[N*2][2];
void connect(int x,int y,int xx,int yy){
	while (x!=xx||y!=yy){
		map[x][y]='.';
		if (random(2)){
			if (x<xx)x++;
			else
			if (x>xx)x--;
		}else{
			if (y<yy)y++;
			else
			if (y>yy)y--;
		}
	}
}
int main(){
	srand((int)time(0));
	printf("Input n and m:");
	scanf("%d %d",&n,&m);
	step=random(n)+2;
	for (int i=1;i<=step;i++){
		d[i][0]=random(n)+1;
		d[i][1]=random(m)+1;
	}
	while (d[1][0]==d[step][0]&&d[1][1]==d[step][1]){
		d[1][0]=random(n)+1;
		d[1][1]=random(m)+1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			map[i][j]='#';
	for (int i=1;i<step;i++)
		connect(d[i][0],d[i][1],d[i+1][0],d[i+1][1]);
	noise=random(n);
	for (int i=1;i<=noise;i++)
		map[random(n)+1][random(m)+1]='.';
	map[d[1][0]][d[1][1]]='P';
	map[d[step][0]][d[step][1]]='E';
	freopen("map.in","w",stdout);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
	return 0;
}
