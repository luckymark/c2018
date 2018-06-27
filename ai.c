#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 
#include <conio.h>
#define WID 100			//搜索广度的上限（大约半个棋盘） 
#define BOTTOM 4		//普通搜索层数
#define KILLB 4
#define BLANK 0			//空位 
#define BLACK 1			//假定黑方为电脑（不一定先手） 
#define WHITE 2			//白方代表玩家（不一定后手） 
#define TOFIVE 1000000 //成五 
#define LIVEFOUR 100000	//活四 
#define	LIVETHREE 49000	//活三、死四 （双活三等同于活四,但活四优先于活三） 
#define LIVETWO 900	//活二、死三（活二前期很重要，分数判高于死三） 
#define LIVEONE 10		//活一 
#define MAX(A,B) (((A)-(B))>>31 ? (B) : (A))  //>>31是取差值的符号位
#define MIN(A,B) (((A)-(B))>>31 ? (A) : (B))
const int INF = 1e9 + 7;//无穷大  
int tbl[15][15];		//棋盘
struct node{			//决策树节点 
	int x,y;
	int point;
	int flg;			//若flg=1则为要剪枝的节点 
}; 
struct axis{			//用于记录悔棋的数对 
	int x,y;
}last[235];
int peak[BOTTOM+1];		//记录dfs每一层的极值  
HANDLE hout; 

void qusort(struct node array[], int maxlen, int begin, int end){  
    int i, j;  
    if(begin < end){  
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！  
        j = end;        // array[end]是数组的最后一位  
        while(i < j){  
            if(array[i].point < array[begin].point){  // 如果比较的数组元素大于基准数，则交换位置。    
                struct node tmp;
				tmp = array[i];
				array[i]=array[j];
				array[j]=tmp; 
                j--;  
            }  
            else{  
                i++;  // 将数组向后移一位，继续与基准数比较。  
            }  
        }  
        if(array[i].point <= array[begin].point){  
            i--;  
        }  
        struct node tmp;
		tmp = array[i];
		array[i]=array[begin];
		array[begin]=tmp;  
        qusort(array, maxlen, begin, i);  
        qusort(array, maxlen, j, end);  
    }  
}
int isin(int a,int b){	//判断是不是超出了棋盘 
	if(a<0||a>14){
		return 0;
	} 
	if(b<0||b>14){
		return 0;
	}
	return 1;
}
int pot(int x){	 //打分 
	if(x==5)	return TOFIVE;
	if(x==4)	return LIVEFOUR;
	if(x==3)	return LIVETHREE;
	if(x==2)	return LIVETWO;
	if(x==1)    return LIVEONE;
	return 0;
}
int ops(int x){  //	对手颜色 
 	if(x==BLACK) return WHITE;
	if(x==WHITE) return BLACK;
}
int whowin(){
	for(int turn=1;turn<=2;turn++){ 
		for(int i=0;i<15;i++){
		
			for(int j=0;j<15;j++){	//水平 
				if(tbl[i][j]==turn){
					int count=1;
					int k=j+1;
					while(isin(i,k)&&tbl[i][k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					j=k; //从k开始继续遍历 
					if(count>=5) return turn;
				}
			} 
			
			for(int j=0;j<15;j++){	//竖直 
				if(tbl[j][i]==turn){
					int count=1;
					int k=j+1;
					while(isin(k,i)&&tbl[k][i]==turn){ //判断连子数目 
						count++;
						k++;
					}
					j=k; //从k开始继续遍历 
					if(count>=5) return turn;
				}
			}
			
			for(int j=0;j<15-i;j++){	//左下三角区域，下斜方向
				 if(tbl[i+j][j]==turn){
					int count=1;
					int k=j+1;
					while(isin(i+k,k)&&tbl[i+k][k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					j=k; //从k开始继续遍历 
					if(count>=5) return turn;
				}
			}
			
			for(int j=1;j<15-i;j++){	//右上三角区域，下斜方向
				 if(tbl[j][i+j]==turn){
					int count=1;
					int k=j+1;
					while(isin(k,i+k)&&tbl[k][i+k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					j=k; //从k开始继续遍历 
					if(count>=5) return turn;
				}
			}
			
			for(int j=0;j<=i;j++){	//左上三角区域，上斜方向
				 if(tbl[i-j][j]==turn){
					int count=1;
					int k=j+1;
					while(isin(i-k,k)&&tbl[i-k][k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					j=k; //从k开始继续遍历 
					if(count>=5) return turn;
				}
			}
			
			for(int j=1;j<15-i;j++){	//右下三角区域，上斜方向
				 if(tbl[15-j][i+j]==turn){
					int count=1;
					int k=j+1;
					while(isin(15-k,i+k)&&tbl[15-k][i+k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					j=k; //从k开始继续遍历 
					if(count>=5) return turn;
				}
			}
		}
	}
	return 0;
}
int judge(){	//判断局势，对象为全局变量tbl 
	int score[2]={};
	for(int turn=1;turn<=2;turn++){	//先默认电脑是黑色 
		for(int i=0;i<15;i++){
		
			for(int j=0;j<15;j++){	//水平打分 
				if(tbl[i][j]==turn){
					int count=1;
					int k=j+1;
					while(isin(i,k)&&tbl[i][k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					if(tbl[i][j-1]==ops(turn)||!isin(i,j-1)){
						count--;
						if(tbl[i][k]==ops(turn)||!isin(i,k)){
							count=0;
						} 
					}
					else if(tbl[i][k]==ops(turn)||!isin(i,k)){
						count--;
					} 
					j=k; //从k开始继续遍历 
					score[turn-1]+=pot(count);
				}
			} 
			
			for(int j=0;j<15;j++){	//竖直打分 
				if(tbl[j][i]==turn){
					int count=1;
					int k=j+1;
					while(isin(k,i)&&tbl[k][i]==turn){ //判断连子数目 
						count++;
						k++;
					}
					if(tbl[j-1][i]==ops(turn)||!isin(j-1,i)){
						count--;
						if(tbl[k][i]==ops(turn)||!isin(k,i)){
							count=0;
						} 
					}
					else if(tbl[k][i]==ops(turn)||!isin(k,i)){
						count--;
					} 
					j=k; //从k开始继续遍历 
					score[turn-1]+=pot(count);
				}
			}
			
			for(int j=0;j<15-i;j++){	//左下三角区域，下斜方向
				 if(tbl[i+j][j]==turn){
					int count=1;
					int k=j+1;
					while(isin(i+k,k)&&tbl[i+k][k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					if(tbl[i+j-1][j-1]==ops(turn)||!isin(i+j-1,j-1)){
						count--;
						if(tbl[i+k][k]==ops(turn)||!isin(i+k,k)){
							count=0;
						} 
					}
					else if(tbl[i+k][k]==ops(turn)||!isin(i+k,k)){
						count--;
					} 
					j=k; //从k开始继续遍历 
					score[turn-1]+=pot(count);
				}
			}
			
			for(int j=1;j<15-i;j++){	//右上三角区域，下斜方向
				 if(tbl[j][i+j]==turn){
					int count=1;
					int k=j+1;
					while(isin(k,i+k)&&tbl[k][i+k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					if(tbl[j-1][i+j-1]==ops(turn)||!isin(j-1,i+j-1)){
						count--;
						if(tbl[k][i+k]==ops(turn)||!isin(k,i+k)){
							count=0;
						} 
					}
					else if(tbl[k][i+k]==ops(turn)||!isin(k,i+k)){
						count--;
					} 
					j=k; //从k开始继续遍历 
					score[turn-1]+=pot(count);
				}
			}
			
			for(int j=0;j<=i;j++){	//左上三角区域，上斜方向
				 if(tbl[i-j][j]==turn){
					int count=1;
					int k=j+1;
					while(isin(i-k,k)&&tbl[i-k][k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					if(tbl[i-j+1][j-1]==ops(turn)||!isin(i-j+1,j-1)){
						count--;
						if(tbl[i-k][k]==ops(turn)||!isin(i-k,k)){
							count=0;
						} 
					}
					else if(tbl[i-k][k]==ops(turn)||!isin(i-k,k)){
						count--;
					} 
					j=k; //从k开始继续遍历 
					score[turn-1]+=pot(count);
				}
			}
			
			for(int j=1;j<15-i;j++){	//右下三角区域，上斜方向
				 if(tbl[15-j][i+j]==turn){
					int count=1;
					int k=j+1;
					while(isin(15-k,i+k)&&tbl[15-k][i+k]==turn){ //判断连子数目 
						count++;
						k++;
					}
					if(tbl[15-j+1][i+j-1]==ops(turn)||!isin(15-j+1,i+j-1)){
						count--;
						if(tbl[15-k][i+k]==ops(turn)||!isin(15-k,i+k)){
							count=0;
						} 
					}
					else if(tbl[15-k][i+k]==ops(turn)||!isin(15-k,i+k)){
						count--;
					} 
					j=k; //从k开始继续遍历 
					score[turn-1]+=pot(count);
				}
			}
		}
	}
	return score[0]-score[1];
}
int evalute(int x,int y,int turn){
	int ANS=0,ob=2,cnt=1; //ANS记录得分，ops记录遇到的对手棋子个数 
	for(int j=1;j<=4;j++){	//水平向右判断 
		if(isin(x+j,y)){
			if(tbl[x+j][y]==turn){
				cnt++;
				if(cnt>=5){
					if(turn == BLACK)
						return TOFIVE;
					if(turn == WHITE)
						return -TOFIVE;
				}
			}
			if(tbl[x+j][y]==ops(turn)){
				ob--;
				cnt--;
				break;
			}
			if(tbl[x+j][y]==BLANK){
				break;	
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}		
	}
	for(int j=-1;j>=-4;j--){	//向左 
		if(isin(x+j,y)){
			if(tbl[x+j][y]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}
			} 
			if(tbl[x+j][y]==ops(turn)){
				cnt--;
				ob--;
				break;
			}
			if(tbl[x+j][y]==BLANK){
				break;
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}
	}
	if(ob<=0||cnt<0) cnt=0;
	if(cnt>5) cnt=5;
	ANS+=pot(cnt);
	
	ob=2;
	cnt=1; 
	for(int j=1;j<=4;j++){	//竖直向上判断 
		if(isin(x,y+j)){
			if(tbl[x][y+j]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}	
			}
			if(tbl[x][y+j]==ops(turn)){
				ob--;
				cnt--;
				break;
			}
			if(tbl[x][y+j]==BLANK){
				break;	
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}		
	}
	for(int j=-1;j>=-4;j--){	//向下 
		if(isin(x,y+j)){
			if(tbl[x][y+j]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}
			} 
			if(tbl[x][y+j]==ops(turn)){
				cnt--;
				ob--;
				break;
			}
			if(tbl[x][y+j]==BLANK){
				break;
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}
	}
	if(ob<=0||cnt<0) cnt=0;
	if(cnt>5) cnt=5;
	ANS+=pot(cnt);

	ob=2;
	cnt=1;
	for(int j=1;j<=4;j++){	
		if(isin(x+j,y-j)){
			if(tbl[x+j][y-j]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}
			}
			if(tbl[x+j][y-j]==ops(turn)){
				ob--;
				cnt--;
				break;
			}
			if(tbl[x+j][y-j]==BLANK){
				break;	
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}		
	}
	for(int j=-1;j>=-4;j--){	 
		if(isin(x+j,y-j)){
			if(tbl[x+j][y-j]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}
			} 
			if(tbl[x+j][y-j]==ops(turn)){
				cnt--;
				ob--;
				break;
			}
			if(tbl[x+j][y-j]==BLANK){
				break;
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}
	}
	if(ob<=0||cnt<0) cnt=0;
	if(cnt>5) cnt=5;
	ANS+=pot(cnt);
	
	ob=2;
	cnt=1;
	for(int j=1;j<=4;j++){	
		if(isin(x+j,y+j)){
			if(tbl[x+j][y+j]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}
			}
			if(tbl[x+j][y+j]==ops(turn)){
				ob--;
				cnt--;
				break;
			}
			if(tbl[x+j][y+j]==BLANK){
				break;	
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}		
	}
	for(int j=-1;j>=-4;j--){	 
		if(isin(x+j,y+j)){
			if(tbl[x+j][y+j]==turn){
				cnt++;
				if(cnt>=5) {
					break;
				}
			} 
			if(tbl[x+j][y+j]==ops(turn)){
				cnt--;
				ob--;
				break;
			}
			if(tbl[x+j][y+j]==BLANK){
				break;
			}
		}
		else{
			cnt--;
			ob--;
			break;
		}
	}
	if(ob<=0||cnt<0) cnt=0;
	if(cnt>5) cnt=5;
	ANS+=pot(cnt);
	
	return ANS;
}
int generator(struct node s[],int turn){	//生成考虑落子的点集，用book记录 
	int pc=0;
	int note[15][15]={};
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(tbl[i][j]!=BLANK){
				for(int k=-2;k<=2;k++){
					if(k==0) continue;
					if(isin(i+k,j)){
						if(tbl[i+k][j]==BLANK&&!note[i+k][j]){
							s[pc].point = evalute(i+k,j,turn);
							s[pc].x=i+k;
							s[pc++].y=j;
							note[i+k][j] = 1;
						} 
					}
					if(isin(i,j+k)){
						if(tbl[i][j+k]==BLANK&&!note[i][j+k]){
							s[pc].point = evalute(i,j+k,turn);
							s[pc].x=i;
							s[pc++].y=j+k;
							note[i][j+k] = 1;
						} 
					}
					if(isin(i+k,j+k)){
						if(tbl[i+k][j+k]==BLANK&&!note[i+k][j+k]){
							s[pc].point = evalute(i+k,j+k,turn);
							s[pc].x=i+k;
							s[pc++].y=j+k;
							note[i+k][j+k] = 1;
						} 
					}
					if(isin(i+k,j-k)){
						if(tbl[i+k][j-k]==BLANK&&!note[i+k][j-k]){
							s[pc].point = evalute(i+k,j-k,turn);
							s[pc].x=i+k;
							s[pc++].y=j-k;
							note[i+k][j-k] = 1;
						} 
					}
				}
			}
		}
	}
	return pc;
}
struct node dfs(int turn,int deep){	//dfs建树 
	struct node now;
	now.flg=0;
	if(deep>BOTTOM){ 
		now.point = judge();
		return now;
	} 
	struct node mark[235];				//大小要开足  
	int range = generator(mark,turn);	//限制子节点在WID以内 
	qusort(mark,range,0,range-1);		//启发式搜索优化
	range = MIN(WID,range); 
	int u,v;
	for(int i=0;i<range;i++){
		u=mark[i].x;
		v=mark[i].y;
		tbl[u][v] = turn;
		if(whowin()==turn){
			if(turn == WHITE){
				tbl[u][v] = BLANK;
				now.point=-TOFIVE;
				return now;
			}
			if(turn==BLACK){
				tbl[u][v] = BLANK;
				if(deep==1){
					now.x=u;
					now.y=v;
				}
				now.point=TOFIVE;
				return now;
			}
		}
		struct node tmp = dfs(ops(turn),deep+1);
		//if(deep==1){
		//	printf("%d %d %d %d\n",tmp.point,tmp.x,tmp.y,tmp.flg);
		//}
		if(tmp.flg==1){		//AB剪枝 
			tbl[u][v]=BLANK;
			if(turn == BLACK){
				now.point = INF; //返回一个不影响父亲的值 
			}
			if(turn == WHITE){
				now.point = -INF;
			}
			return now;
		}
		if(i==0){
			now.x = u;
			now.y = v;
			now.point = tmp.point;
			peak[deep]=tmp.point;
		}
		else if(turn==BLACK){
			if(now.point<tmp.point){		//等于的情况未处理
				peak[deep] = MAX(tmp.point,peak[deep]); 
				if(deep==1){
					now.x = u;
					now.y = v;
				}
				now.point = tmp.point;
			}
		}
		else {
			if(now.point>tmp.point){
				peak[deep] = MIN(tmp.point,peak[deep]); 
				if(deep==1){
					now.x = u;
					now.y = v;
				}
				now.point = tmp.point;
			}
		}
		tbl[u][v] = BLANK; //同节点回溯取消落子操作 
	}
	
	if(deep>turn){	//AB剪枝判断 
		if(turn==BLACK&&peak[deep-2]>now.point){
			now.flg=1; 
		}
		if(turn==WHITE&&peak[deep-2]<now.point){
			now.flg=1;
		}
	}
	return now;
}
void display(){
	system("cls");
	printf("  1 2 3 4 5 6 7 8 9 A B C D E F\n");
	for(int i=0;i<15;i++){
		if(i<9)
			printf("%d ",i+1);
		else
			printf("%c ",'A'+i-9);
		for(int j=0;j<15;j++){
			if(tbl[i][j]==BLACK) printf("# ");
			if(tbl[i][j]==WHITE) printf("@ ");
			if(tbl[i][j]==BLANK) printf("0 ");
		}
		printf("\n");
	}
}

void play(int first){
	int step=0;	 			//总步数
	struct node p;
	double t1,t2; 			//记录用时 
	
	while(1){
		
	if(step==0&&first%2==0){
		tbl[7][7]=BLACK;
	}
	
	display();
	printf("你的子棋是@,输入格式为15进制数（1~F），先输入行号再输入列号，输入RS可以认输，输入RR可以发动时间回溯魔法(你可以无限耍赖皮)\n当前总步数：%d\n",(step+1)/2); 
	printf("上一步用时：%.3lf 秒\n",(t2-t1)/1000);
	
	if(step>1){
		char m,n;
		if(p.x+1>9){
			m='A'+p.x+1-10;
		} 
		else m='0'+p.x+1;
		if(p.y+1>9){
			n='A' +p.y+1-10;
		}
		else n = '0'+p.y+1;
		printf("对方落子点为: %c %c\n",m,n);
	}
	 
	int jud = whowin();
	if(jud == BLACK){
		 printf("噢，输了!");
		 system("pause");
		 break;
	} 
	if(jud == WHITE){
		printf("你赢了，就像2018年圣彼得堡上空的潘帕斯雄鹰一样!");
		system("pause");
		break;
	}
	
	char a,b;
	int cx,cy;
	printf("你的回合：\n");
	t1 = clock();
	scanf(" %c %c",&a,&b);
	t2 = clock();
	if(a=='R'&&b=='S'){
		system("cls");
		printf("你动用了魔法离开\n");
		return;
	} 
	
	if(a=='R'&&b=='R'){
		if(step>2){
			tbl[last[step-1].x][last[step-1].y]=BLANK;
			tbl[last[step-2].x][last[step-2].y]=BLANK;
			step-=2;
			continue;
		}
		else{
			printf("这里已经是时间原点!");
			system("pause");
			continue;
		}
	}
	if(a>'9'){
		cx=a-'A'+10;
	}
	else cx = a-'0';
	if(b>'9'){
		cy=b-'A'+10;
	}
	else cy = b-'0';
	if(tbl[cx-1][cy-1]!=BLANK){
		printf("你尚未掌握篡改棋子的魔法!\n");
		system("pause");
		continue;
	}
	tbl[cx-1][cy-1] = WHITE;
	display();
	jud = whowin();
	if(jud == BLACK){
		 printf("噢，输了!");
		 system("pause");
		 break;
	} 
	if(jud == WHITE){
		printf("你赢了，就像2018年圣彼得堡上空的潘帕斯雄鹰一样!");
		system("pause");
		break;
	}
	printf("对方正在思考-。-\n");
	t1 = clock();
	p=dfs(BLACK,1);
	t2 = clock();
	tbl[p.x][p.y] = BLACK;
	last[step].x=cx-1;
	last[step++].y=cy-1;
	last[step].x=p.x;
	last[step++].y=p.y;
}
} 
void meun(){
	system("cls");
	printf("来一局五子棋吧！");
	system("pause");
}
int main() {
	srand(time(0));
	printf("我的巫师猎人徽章在振动，这里附近一定有五子棋高手！"); 
	system("pause");
	meun();
	int k=rand();	//决定先手  
	play(k);
	return 0;
}

/*
srand(time(0));
	printf("我的巫师猎人徽章在振动，这里附近一定有五子棋高手！"); 
	system("pause");
	meun();
	int k=rand();	//决定先手  
	play(k);
	return 0;
	
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			scanf("%d",&tbl[i][j]);
		}
	}
	struct node p;
	int x=judge();
	p = dfs(BLACK,1);
	tbl[p.x][p.y] = BLACK;
	display();
*/

