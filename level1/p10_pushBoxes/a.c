#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#define N 100
int n,m,x,y,step,sum,sumrecord,bz,xrecord,yrecord;
char map[N][N],map1[N][N];
int b[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void sleep1(int x){
	while (x--)
		for (int i=1;i<=1e8;i++);
}
int check(int x){
	return x=='.'||x=='P'||x=='E'||x=='B'||x=='#';
}
void loadmap(char filename[]){
	memset(map,0,sizeof(map));
	FILE*file=fopen(filename,"r");
	n=0,m=0;
	while (!feof(file)){
		fscanf(file,"%s",map[++n]+1);
	}
	while (!check(map[n][1]))n--;
	m=strlen(map[n]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			map1[i][j]=map[i][j];
	fclose(file);
}
void draw(int sig){
	printf("\033c");
	printf("Welcome to pushBoxes!Here you will challenge 10 levels!\n");
	printf("You can press direction keys to move,q to quit the game or r to restart the level.\n");
	printf(".:space #:Wall P:people E:box's destination B:box S:box on a destination.\n");
	printf("level %d:\n",sig);
	if (sum==1)
		printf("You have cost %d steps and There is still %d box to move.\n",step,sum);
	else
		printf("You have cost %d steps and There are still %d boxes to move.\n",step,sum);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}
void swap(char*x,char*y){
	int z=*y;
	*y=*x,*x=z;
}
void upscores(int sig,int step){
	FILE *file;
	if (sig==1)
		file=fopen("score.out","w");
	else
		file=fopen("score.out","a");
	fprintf(file,"%d\n",step);
	fclose(file);
}
void drawscoreboard(){	
	printf("\033c");
	FILE *file;
	file=fopen("score.out","r");
	int d[100],n=0;
	memset(d,0,sizeof(d));
	while (!feof(file)){
		fscanf(file,"%d",&d[++n]);
	}
	while (n&&!d[n])n--;
	if (n==10)printf("You have passed all the levels!Congratulations!");
	else
		printf("You haven't passed all the levels.");
	printf("Here are your scores on each level:\n");
	if (n==0)printf("None!\n");
	for (int i=1;i<=n;i++)
		printf("In level %d,you cost %d steps.\n",i,d[i]);
}
void clear(){
	FILE *file=fopen("score.out","w");
	fclose(file);
}
int main(){
	clear();
	char filename[100];
	memset(filename,0,sizeof(filename));
	FILE *file1=fopen("filename.in","r");
	while (!feof(file1)){
		for (int sig=1;sig<=10;sig++){	
			memset(filename,0,sizeof(filename));
			fscanf(file1,"%s",filename);
			if (filename[0]!='m')break;
			loadmap(filename);
			sum=0;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=m;j++)
					if (map[i][j]=='P')
						xrecord=x=i,y=yrecord=j;
					else
					if (map[i][j]=='B')
						sum++;
			sumrecord=sum;
			step=0;
			bz=0;
			char ch;
			int tty = open("/dev/tty", O_RDONLY);
	 	   	struct termios newt, oldt;
	   	 	tcgetattr(tty, &oldt);
			newt = oldt;
			newt.c_lflag &= ~( ICANON | ECHO );
			tcsetattr(tty, TCSANOW, &newt);
			draw(sig);
			while (1){
				if (!sum){
		        	tcsetattr(tty, TCSANOW, &oldt);
		        	upscores(sig,step);
		        	printf("You win!And you have cost %d steps.\n",step);
		        	for (int i=5;i>=1;i--){
		        		printf("\033c");
		        		printf("You win!And you have cost %d steps.\n",step);
		        		printf("Wait %d s for next level's loading",i);
		        		for (int j=1;j+i<=5;j++)printf(".");
		        		printf("\n");
		        		sleep1(1);
					}
					break;
				}
				read(tty, &ch, 1);
		    	if (ch == 'q') {
		        	tcsetattr(tty, TCSANOW, &oldt);
		        	drawscoreboard();
		        	fclose(file1);
		      	 	return 0;
		    	} else 
		    	if (ch == 'r'){
		    		bz=step=0,x=xrecord,y=yrecord;
		    		sum=sumrecord;
		    		for (int i=1;i<=n;i++)
		    			for (int j=1;j<=m;j++)
		    				map[i][j]=map1[i][j];
		    		draw(sig);
		    		continue;
		    	}else{
		    		int tag=-1;
		    		if (ch==65)tag=0;
		    		else
		    		if (ch==66)tag=1;
		    		else
		    		if (ch==68)tag=2;
		    		else
		    		if (ch==67)tag=3;
		    		if (tag!=-1){
		    			int xx=x+b[tag][0],yy=y+b[tag][1];
		    			if (xx<1||yy<1||xx>n||yy>m)continue;
		    			if (map[xx][yy]=='#')continue;
		    			if (map[xx][yy]=='.'){
		    				map[xx][yy]='P';
		    				map[x][y]='.';
		    				if (bz)map[x][y]='E';
		    				x=xx,y=yy;
		    				step++;
		    				bz=0;
							draw(sig);
		    				continue;
		    			}else
		    			if (map[xx][yy]=='E'){
		    				map[xx][yy]='P';
		    				map[x][y]='.';
		    				if (bz)map[x][y]='E';
		    				x=xx,y=yy;
		    				step++;
		    				bz=1;
	 						draw(sig);
	 						continue;       				
		    			}else
		    			if (map[xx][yy]=='B'||map[xx][yy]=='S'){
		    				int xxx=xx+b[tag][0],yyy=yy+b[tag][1];
		    				if (xxx<1||yyy<1||xxx>n||yyy>m)continue;
		    				if (map[xxx][yyy]=='#'||map[xxx][yyy]=='B'||map[xxx][yyy]=='S')continue;
		    				if (map[xxx][yyy]=='.'){
		    					map[xxx][yyy]='B';
		    					map[x][y]='.';
		    					if (bz)map[x][y]='E';
		    					if (map[xx][yy]=='S')bz=1,sum++;
		    					else
		    						bz=0;
		    					map[xx][yy]='P';
		    					x=xx,y=yy;
		    					step++;	
	 							draw(sig);
	 							continue; 
		    				} else 
		    				if (map[xxx][yyy]=='E'){
		    					map[xxx][yyy]='S';
		    					sum--;
		    					map[x][y]='.';
		    					if (bz)map[x][y]='E';
		    					if (map[xx][yy]=='S')sum++,bz=1;
		    					else
		    						bz=0;
		    					map[xx][yy]='P';
		    					x=xx,y=yy;
		    					step++;
		    					draw(sig);
		    					continue;
		    				}
		    			}
		    		}
				}
			}
		}
	}
	fclose(file1);
	return 0;
}
