#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define CROSSOVER_RATE 0.7               //交叉概率 
#define MUTATE_RATE 0.001                //突变概率 
#define POP_SIZE 120                     //种群大小 
#define CHROMO_SIZE 60                   //染色体最大长度 
#define MAXGENERATION 1000               //最大繁衍代数 
#define MAP_LEN  21
#define MAP_WIDE 12

struct path{
	int chromo[CHROMO_SIZE];
	double fiteness;
};	 
struct COD{                    //坐标结构 
	int x;
	int y;
}; 
char map[MAP_WIDE][MAP_LEN];
struct path baby[POP_SIZE+1];
struct path baby1,baby2;

void Initmap(void);
void coding(int *code); 
double FitenessJudge(int* chromo);
void JudgeWall(struct COD* now,struct COD* New);
int SelectionParents(struct path*);
void Crossover(struct path,struct path);
void Mutate(int *code);
int choosebest(const struct path* pop);

int main(void){
	Initmap();
	struct path pop[POP_SIZE];
	srand((unsigned int) (time(NULL)));
	int i,j,k;
	for(i=0;i<POP_SIZE;i++){
		coding(pop[i].chromo);                       //初代编码 
	}
	int generations=1;
	while(generations<=MAXGENERATION){ 
		for(j=0;j<POP_SIZE;j++){
			pop[j].fiteness=FitenessJudge(pop[j].chromo);//得出适应性分数 
		}
		int newbabies=0;
		while(newbabies<POP_SIZE){
			struct path mum=pop[SelectionParents(pop)]; //选择亲代 
			struct path dad=pop[SelectionParents(pop)];
			Crossover(mum,dad);                        //交叉 
			Mutate(baby1.chromo);                      //突变 
			Mutate(baby2.chromo);
			baby[newbabies]  =baby1;
			baby[newbabies+1]=baby2;
			newbabies+=2;
		}
		generations++;
		int best=choosebest(pop);
		pop[0]=pop[best];
		for(k=1;k<POP_SIZE;k++){
		pop[k]=baby[k];
		}
	}	
		printf("Lose!\n");
		for(i=0;i<POP_SIZE;i++){
			for(j=0;j<CHROMO_SIZE;j++){
				printf("%d",pop[i].chromo[j]);
			}
			printf("\n");
		} 
	return 0;
}

void Initmap(void){
	int i,j;
	for(i=1;i<MAP_WIDE;i++){
		for(j=1;j<MAP_LEN;j++){
			map[i][j]=' ';
		}
	}
	for(i=0;i<MAP_WIDE;i++){
		map[i][0]='#';
		map[i][MAP_LEN-1]='#';
	}
	for(i=0;i<MAP_LEN;i++){
		map[0][i]='#';
		map[MAP_WIDE-1][i]='#';
	}                                                  //生成边界墙 
	for(i=1;i<5;i++){
		map[i][3]='#';
	}
	map[5][7]='#',map[5][8]='#',map[6][12]='#',map[6][13]='#';
	map[6][7]='#',map[4][8]='#',map[5][12]='#',map[5][13]='#',map[8][17]='#';
	map[8][20]=' ';
}

void coding(int *code){
	int i;
	for(i=0;i<CHROMO_SIZE;i++){
		code[i]=rand()%2;
	}
}

double FitenessJudge(int* chromo){
	int twd,i;                 
	struct COD start={1,1};
	struct COD end  ={8,20};
	struct COD *now=&start;
	struct COD n =*now;
	struct COD *New=&n;
	for(i=0;i<CHROMO_SIZE;i+=2){
		twd=chromo[i]*2+chromo[i+1];         //规划方向 0-east,1-south,2-west,3-north 
		switch(twd){
			case  0: n.y++;JudgeWall(now,New);break;
			case  1: n.x++;JudgeWall(now,New);break;
			case  2: n.y--;JudgeWall(now,New);break;
			case  3: n.x--;JudgeWall(now,New);break;
		}
	}
	int diff_x,diff_y,a,b;
	a=end.x-n.x,b=end.y-n.y;
	diff_x=abs(a),diff_y=abs(b);
	if( (diff_x+diff_y) == 0){
		for(i=0;i<CHROMO_SIZE;i++){
			printf("%d",chromo[i]);
		}
		exit(0);
	}
	double score=1/(double)(diff_x+diff_y+1);
	
	return score;
}

void JudgeWall(struct COD* now,struct COD* New){
	if(map[New->x][New->y] == ' ' ){
		*now = *New;
	}
}

int SelectionParents(struct path *pop){                       //轮盘赌选法
	int parent=0;
	int i,j;
	double total,ctotal=0;
	for(i=0;i<POP_SIZE;i++){
		total+=pop[i].fiteness;
	}
	double a=rand()/(double)(RAND_MAX/(int)total);
	for(j=0;j<POP_SIZE;j++){
		ctotal+=pop[j].fiteness;
		if(ctotal>a){
			parent=j;
			break;
		}
	}
	return parent;
}

void Crossover(struct path dad,struct path mum){
	double pro1=rand()/(double)(RAND_MAX);
	int i,j;
	if(pro1>CROSSOVER_RATE){
		baby1=dad;
		baby2=mum;
		return ;
	} 
	int breakpoint=rand()%(CHROMO_SIZE-1);
	int temp[CHROMO_SIZE];
	for(i=0;i<CHROMO_SIZE;i++){
		baby1.chromo[i]=dad.chromo[i];
		baby2.chromo[i]=mum.chromo[i];
	}
	for(j=breakpoint;j<CHROMO_SIZE;j++){
		baby1.chromo[j]=mum.chromo[j];
		baby2.chromo[j]=dad.chromo[j];
	}
}

void Mutate(int *code){
	int i;
	double pro2=rand()/(double)(RAND_MAX);
	for(i=0;i<CHROMO_SIZE;i++){
		if(pro2>MUTATE_RATE){
			code[i]=!code[i];
		}
	}
}

int choosebest(const struct path* pop){
	int i;
	int best=0;
	for(i=1;i<POP_SIZE;i++){
		if(pop[best].fiteness<pop[i].fiteness){
			best=i;
		}
	}
	return best;
} 
