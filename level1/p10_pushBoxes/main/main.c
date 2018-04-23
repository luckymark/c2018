#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char map[15][30],raw_map[15][30];   //设计地图禁忌：不要让箱子和目标重叠 
int length=0,height=0;
int account_status=0;

int x,y;
int point,top,score,choose;  //考虑要不要给choose赋初始值 
char now_account[21]={};

/*地图模块*/ 
void readmap(int n);
void getmap(void);

/*移动模块*/ 
void UP(void);
void DOWN(void);
void LEFT(void);
void RIGHT(void);
void JudgeObstacle(int X,int Y,int target);

/*账号模块*/ 
void do_register(void);
void sign_in(void);
void save_data(void);

/*结算模块*/ 
int judge_success(void);

/*视图模块*/
int manu(void); 
void welcome(void);
int mapselect(void);

/*行动模块*/ 
int input(void);


/*主函数*/ 
int main(int argc, char *argv[]) 
{
	while(!account_status)
	{
		welcome();
	}
	int choose_manu,continue_or_not=1;
	
	while(1)
	{
		choose_manu=manu();
		
		switch(choose_manu)
		{
			case 1:
				while(continue_or_not)
				{
					choose=mapselect();
					readmap(choose);
					getmap();
				
					continue_or_not=input();
				}
				break;
			case 2:save_data();break;
			case 3:return 0;break;
			default:MessageBox(NULL,"输入错误，请重新输入！","Error",MB_OK);system("cls");break;
		}
	}
	
	
	
	return 0;
}



void readmap(int n)   //地图读取函数 
{
	int i;
	if(n==1)
	{
		FILE *fp = fopen("map1.txt", "r+");
		for(i=0;i<10;i++)
		{
			fscanf(fp,"%s\n",map[i]);
			strcpy(raw_map[i],map[i]);
		}
		fscanf(fp,"%d %d %d",&point,&x,&y);
	}
	if(n==2)
	{
		FILE *fp = fopen("map2.txt", "r+");
		for(i=0;i<10;i++)
		{
			fscanf(fp,"%s\n",map[i]);
			strcpy(raw_map[i],map[i]);
		}
		fscanf(fp,"%d %d %d",&point,&x,&y);
	}
	length=strlen(map[0]);
	height=i;
}

void getmap(void)  //地图重置输出函数 
{
	int i;
	system("cls");
	for(i=0;i<height;i++)
	{
		printf("%s\n",map[i]);
	}
	printf("\nPoint:%d\n",point);
}

void UP(void)
{
	JudgeObstacle(x,y,1);
}

void DOWN(void)
{
	JudgeObstacle(x,y,2);
}

void LEFT(void)
{
	JudgeObstacle(x,y,3);
}

void RIGHT(void)
{
	JudgeObstacle(x,y,4);
}

void JudgeObstacle(int X,int Y,int target)
{
	int move=1;
	switch(target)
	{
		case 1:
			if(map[X-1][Y]=='$' && map[X-2][Y]!='#')
			{
				map[X-2][Y]='$';
				getmap();
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			else if(map[X-1][Y]=='*' && move)
			{
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			if(!move)
			{
				--X;
				x=X;
				map[X][Y]='O';
				--point;           //顺便扣个分 
			}
			getmap();
			break;
		case 2:
			if(map[X+1][Y]=='$' && map[X+2][Y]!='#')
			{
				map[X+2][Y]='$';
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			else if(map[X+1][Y]=='*' && move)
			{
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				
				move=0;
			}
			if(!move)
			{
				++X;
				x=X;
				map[X][Y]='O';
				--point;           //顺便扣个分 
			}
			getmap();
			break;
		case 3:
			if(map[X][Y-1]=='$' && map[X][Y-2]!='#')
			{
				map[X][Y-2]='$';
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			else if(map[X][Y-1]=='*' && move)
			{
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			if(!move)
			{
				--Y;
				y=Y;
				map[X][Y]='O';
				--point;           //顺便扣个分 
			}
			getmap();
			break;
		case 4:
			if(map[X][Y+1]=='$' && map[X][Y+2]!='#')
			{
				map[X][Y+2]='$';
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			else if(map[X][Y+1]=='*' && move)
			{
				if(raw_map[X][Y]!='$' && raw_map[X][Y]!='O')             
				{
					map[X][Y]=raw_map[X][Y];
				}
				else
				{
					map[X][Y]='*';
				}
				move=0;
			}
			if(!move)
			{
				++Y;
				y=Y;
				map[X][Y]='O';
				--point;           //顺便扣个分 
			}
			getmap();
			break;
	}
}

int judge_success(void)
{
	int judge1,judge2;
	for(judge1=0;judge1<height;judge1++)
	{
		for(judge2=0;judge2<length;judge2++)
		{
			if(map[judge1][judge2]=='@')
			{
				return 0;
			}
		}
	}
	if(choose==top)
	{
		top++;
	}
	return 1;
}

void do_register(void)
{
	int stored_score=0,stored_top=0,judge_register=1;
	char account[21]={},stored_account[21]={};
	FILE *fp = fopen("information.txt", "r+");
	while(judge_register)
	{
		printf("请输入账号(不超过20个字符)：");
		scanf("%s",account);
		judge_register=0;
		while(fscanf(fp,"%s ",stored_account)!=EOF)
		{
			fscanf(fp,"%d %d\n",&stored_score,&stored_top);
			judge_register=0;
			if(!strcmp(account, stored_account))
			{
				judge_register=1;
				MessageBox(NULL,"与已有帐号重复，注册失败！","Failed",MB_OK);
				break; 
			}
		}
	}
	fprintf(fp,"%s 0 1\n",account);    //账号 累积分数 最高关数
	system("cls");
	MessageBox(NULL,"Success","账号创建成功！",MB_OK);
	account_status=1;
}

void sign_in(void)
{
	char account[21]={},stored_account[21]={};
	int stored_score,stored_top;
	FILE *fp = fopen("information.txt", "r+");
	printf("请输入账号：");
	scanf("%s",account);
	while(fscanf(fp,"%s ",stored_account)!=EOF)
	{
		fscanf(fp,"%d %d\n",&stored_score,&stored_top);
		if(!strcmp(account, stored_account))
		{
			score=stored_score;
			top=stored_top;
			strcpy(now_account,stored_account);
			system("cls");
			MessageBox(NULL,"登录成功！","Success",MB_OK);
			account_status=1;
		}
	}
	if(!account_status)
	{
		MessageBox(NULL,"账号未找到！程序即将退出...","Failed",MB_OK);
		exit(0); 
	}
}

void save_data(void)
{
	char stored_account[21]={},count=0;
	int stored_score,stored_top;
	FILE *fp = fopen("information.txt", "r+");
	while(fscanf(fp,"%s ",stored_account)!=EOF)
	{
		fscanf(fp,"%d %d\n",&stored_score,&stored_top);
		if(!strcmp(now_account, stored_account))
		{
			/*怎么保存*/ 
			system("cls");
			MessageBox(NULL,"保存成功！程序即将结束...","Success",MB_OK);
			exit(0);
		}
		++count;
	}	
}

void welcome(void)
{
	int choose_welcome,result_of_welcome;
	printf("欢迎\n1.注册账号\n2.登录帐号\n请输入序号：");
	scanf("%d",&choose_welcome);
	system("cls");
	if(choose_welcome==1)
	{
		do_register();
	}
	if(choose_welcome==2)
	{
		sign_in();
	}
} 

int manu(void)
{
	int choose_in_manu;
	printf("欢迎您，%s，您的可选择关卡数为：%d，当前累积分数为：%d\n1.选择关卡\n2.存储并退出\n3.直接退出\n请输入序号：",now_account,top,score);
	scanf("%d",&choose_in_manu);
	system("cls");
	return choose_in_manu;
}

int input(void)
{
	int continue_or_not;
	char ch;
	while(ch=getch())
    {
   		switch(ch)
     	{
        	case 97:  LEFT(); break;
        	case 100:  RIGHT(); break;
        	case 115:  DOWN(); break;
        	case 119:  UP(); break;
        	default:continue;
        }
        if(judge_success())               
    	{
        	MessageBox(NULL,"恭喜过关","Success",MB_OK);
        	score += point;
        	continue_or_not=MessageBox(NULL,"是否继续？","Continue?", MB_YESNO);
        	system("cls");
        	switch(continue_or_not)
        	{
        		case IDYES:return 1;
				case IDNO:return 0;
			}
		}
    }
}

int mapselect(void)
{
	int map_select;
	while(1)
	{
		system("cls");
		printf("请输入地图序号：");
		scanf("%d",&map_select);
		if(map_select<=top)
		{
			break;
		}
		MessageBox(NULL,"输入错误，请重新输入！","Error",MB_OK);
		system("cls");
	}
	return map_select;
}

//存储数据没实现 
