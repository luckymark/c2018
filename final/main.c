#include <stdio.h>
#include <stdlib.h>
#include<conio.h> 
#include<windows.h>
#define len 15
int nowx,nowy;
int maxmin_x,maxmin_y;
int histx,histy;
int old_x=0,old_y=0;
int map[len][len]={0};
int count_turn;
int value1[len][len]=
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
   	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
    {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
    {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
    {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
    {0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
    {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
    {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
    {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
    {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
    {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int value2[len][len]=
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
   	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
    {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
    {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
    {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
    {0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
    {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
    {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
    {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
    {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
    {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
void display_map();
int player_turn(int side_chess);
void player_vs_player();
int OB(int side_chess,int row_want,int line_want);
int AI_turn(int side_chess);
int goal(int side_chess,int posx,int posy);
int maxmin(int now_chess, int count_0, int alpha, int beta);

int main(int argc, char *argv[]) 
{
	system("title  ¡¾KC's gobang game¡¿");
	while(1)
	{
		char c;
		printf("\n\n\n\n\n\nHELLO, WELCOME TO KC'S GOBANG GAME! GOOD LUCK!\n");
		Sleep(1500);
		system("cls");
		printf("CHOOSE THE GAME MODE:\n1 for AI, 2 for player_vs_player, or other buttons to exit\n");  
		c=getch();
//----------------------------------------------------player vs AI
		if(c=='1')
		{
			printf("choose your chess:1 for black, 2 for white\n"); 
			char d;
			d=getch();
			if(d=='1')
			{
				system("cls");
				display_map();
				int flag=0;
				while(flag==0)
				{
					flag=player_turn(1);
					count_turn++;
					if(flag==1)
					break;
					flag=AI_turn(2);
				}
				exit(0);
			}
			else
			{
				system("cls");
				map[7][7]=1;
				old_x=7;
				old_y=7;
				display_map();
				int flag=0;
				while(flag==0)
				{
					flag=player_turn(2);
					count_turn++;
					if(flag==1)
					break;
					flag=AI_turn(1);	
				}
				exit(0);
			}
				
		}
//------------------------------------------------player vs player		
		else if(c=='2')
		{
			display_map();
			player_vs_player();
			exit(0);
		}
		else
		{
			system("cls");
			printf("GOODBYE!\n");
			exit(0);
		}
	}
	return 0;
}


void display_map()
{
	system("cls");
	int i,j;
	printf("\n\n\n\n\n\n\n\n");
	for(i=0;i<len;i++)
	{
		printf("\t\t\t");
		if(i<9)
		printf("0%d",i+1);
		else
		printf("%d",i+1);
		for(j=0;j<len;j++)
		{
			if(map[i][j]==1)
			printf("¡ñ");
			else if(map[i][j]==2)
			printf("¡ð");
			else if(i==0&&j==0)
			printf("©³ ");
			else if(i==0&&j!=0&&j!=len-1)
			printf("©Ó ");
			else if(i==0&&j==len-1)
			printf("©· ");
			else if(j==0&&i!=len-1)
			printf("©Ä ");
			else if(j==len-1&&i!=len-1)
			printf("©Ì ");
			else if(i==len-1&&j==0)
			printf("©» ");
			else if(i==len-1&&j!=0&&j!=len-1)
			printf("©Û ");
			else if(i==len-1&&j==len-1)
			printf("©¿ ");	
			else
			printf("©à ");
		}
		printf("\n");
	}
	printf("\t\t\t  010203040506070809101112131415\n\n\n");
	printf("Due to the AI's limited intelligence, please do not play some strange steps! \n THANK YOU VERY MUCH!\n\n\ ");
}

int player_turn(int side_chess)
{
	int row_want,line_want;
	while(1)
	{
		printf("choose the drop point:\n");
		printf("row:");
		scanf("%d",&row_want);
		printf("line:");
		scanf("%d",&line_want);	
		row_want--;
		line_want--;
		if(map[row_want][line_want]!=0||row_want<0||row_want>len-1||line_want<0||line_want>len-1)
		printf("error point! please try again!\n\n");
		else
		break;
	}
	old_x=row_want;
	old_y=line_want;
	if(side_chess==1)
	{
		map[row_want][line_want]=1;
		if(OB(side_chess,row_want,line_want)==1)
		{
			display_map();
			printf("black has dropped at %d,%d\n\n",row_want+1,line_want+1);
			printf("black win!!!\n");
			return 1;	
		}	
		display_map();
		printf("black has dropped at %d,%d\n\n",row_want+1,line_want+1);
	}
	else
	{
		map[row_want][line_want]=2;
		if(OB(side_chess,row_want,line_want)==1)
		{
			display_map();
			printf("white has dropped at %d,%d\n\n",row_want+1,line_want+1);
			printf("white win!!!\n");
			return 1;
		}
		display_map();
		printf("white has dropped at %d,%d\n\n",row_want+1,line_want+1);
	}
	return 0;
}

void player_vs_player()
{
	int flag=0;
	int now_chess=1;
	while(flag==0)
	{
		flag=player_turn(now_chess);
		now_chess=3-now_chess;
	}
}


int OB(int side_chess,int row_want,int line_want)
{
	int x=1,y=1,z=1,w=1;
	int i;
	for(i=1;i<5;i++)
	{
		if(line_want-i>=0&&map[row_want][line_want-i]==side_chess)
		x++;
		else 
		break;
	}
	for(i=1;i<5;i++)
	{
		if(line_want+i<len&&map[row_want][line_want+i]==side_chess)
		x++;
		else 
		break;
	}
	if(x>4)
	return 1;
	
	for(i=1;i<5;i++)
	{
		if(row_want-i>=0&&map[row_want-i][line_want]==side_chess)
		y++;
		else 
		break;
	}
	for(i=1;i<5;i++)
	{
		if(row_want+i<len&&map[row_want+i][line_want]==side_chess)
		y++;
		else 
		break;
	}
	if(y>4)
	return 1;
	
	for(i=1;i<5;i++)
	{
		if(row_want-i>=0&&line_want-i>=0&&map[row_want-i][line_want-i]==side_chess)
		z++;
		else
		break;
	}
	for(i=1;i<5;i++)
	{
		if(row_want+i<len&&line_want+i<len&&map[row_want+i][line_want+i]==side_chess)
		z++;
		else
		break;
	}
	if(z>4)
	return 1;
	
	for(i=1;i<5;i++)
	{
		if(row_want-i>=0&&line_want+i<len&&map[row_want-i][line_want+i]==side_chess)
		w++;
		else
		break;
	}
	for(i=1;i<5;i++)
	{
		if(row_want+i<len&&line_want-i>=0&&map[row_want+i][line_want-i]==side_chess)
		w++;
		else
		break;
	}
	if(w>4)
	return 1;
	
	return 0;
}
//----------------------------------------------------------------- ordinary edition
/*int AI_turn(int side_chess)
{
	int count_1=0;
	int i,j,k,h;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			int mark=0;
			for(k=-3;k<4;k++)
			{
				for(h=-3;h<4;h++)
				{
					if(i+k>=0&&i+k<len&&j+h>=0&&j+h<len)
					{
						if(map[i+k][j+h]!=0)
						mark++;
					}
				}
			}
			if(mark)
			{
				if(i-old_x>=-4&&i-old_x<=4&&j-old_y>=-4&&j-old_y<=4&&map[i][j]==0)
				{
					value1[i][j]=goal(side_chess,i,j);
					value2[i][j]=goal(3-side_chess,i,j);
					count_1++;
				}
			}
		}
	}
	if(count_1<10)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				if(map[i][j]==0)
				{
					value1[i][j]=goal(side_chess,i,j);
					value2[i][j]=goal(3-side_chess,i,j);
				}
			}
		}	
	}
	int ansx,ansy,ansx1,ansy1,ansx2,ansy2;
	int max_goal_our=INT_MIN;
	int max_goal_oppo=INT_MIN;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(map[i][j]!=0)
			{
				value1[i][j]=INT_MIN;
				value2[i][j]=INT_MIN;
			}
			
		}
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(map[i][j]==0)
			{
				if(value1[i][j]>max_goal_our)
				{
					max_goal_our=value1[i][j];
					ansx1=i;
					ansy1=j;
				}
				if(value2[i][j]>max_goal_oppo)
				{
					max_goal_oppo=value2[i][j];
					ansx2=i;
					ansy2=j;	
				}
			}		
		}
	}
	if(max_goal_our>max_goal_oppo)
	{
		ansx=ansx1;
		ansy=ansy1;
	}
	else
	{
		ansx=ansx2;
		ansy=ansy2;
	}
	
	map[ansx][ansy]=side_chess;
	old_x=ansx;
	old_y=ansy;
	
	if(side_chess==1)
	{
		if(OB(side_chess,ansx,ansy)==1)
		{
			display_map();
			printf("black has dropped at %d,%d\n\n",ansx+1,ansy+1);
			printf("black win!!!\n");
			return 1;	
		}	
		display_map();
		printf("black has dropped at %d,%d\n\n",ansx+1,ansy+1);
	}
	else
	{
		if(OB(side_chess,ansx,ansy)==1)
		{
			display_map();
			printf("white has dropped at %d,%d\n\n",ansx+1,ansy+1);
			printf("white win!!!\n");
			return 1;
		}
		display_map();
		printf("white has dropped at %d,%d\n\n",ansx+1,ansy+1);
	}
	
	return 0;
}*/


//----------------------------------------------------- alpha-beta edition
int AI_turn(int side_chess)
{
	int count_1=0;
	int i,j,k,h;
	if(count_turn==1)
	{
		srand((unsigned)time(NULL));
		i= rand() % 3+old_x-1;
		j= rand() % 3+old_y-1;
		while (map[i][j]!=0||i<0||i>=len||j<0||j>=len||(i==old_x&&(j==old_y+1||j==old_y-1))
		||(j==old_y&&(i==old_x+1||i==old_x-1)))
		{	
			i= rand() % 3+old_x-1;
			j= rand() % 3+old_y-1;
		}
		if (goal(side_chess,i,j)<=12000)
		{
			map[6][6]=side_chess;
			old_x=6;
			old_y=7;
			display_map();
			if(side_chess==1)
			printf("black has dropped at %d,%d\n\n",i+1,j+1);
			else
			printf("white has dropped at %d,%d\n\n",i+1,j+1);
			return 0;
		}
		map[i][j]=side_chess;
		display_map();
		if(side_chess==1)
		printf("black has dropped at %d,%d\n\n",i+1,j+1);
		else
		printf("white has dropped at %d,%d\n\n",i+1,j+1);
		return 0;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			int mark=0;
			for(k=-3;k<4;k++)
			{
				for(h=-3;h<4;h++)
				{
					if(i+k>=0&&i+k<len&&j+h>=0&&j+h<len)
					{
						if(map[i+k][j+h]!=0)
						mark++;
					}
				}
			}
			if(mark)
			{
				if(i-old_x>=-4&&i-old_x<=4&&j-old_y>=-4&&j-old_y<=4&&map[i][j]==0)
				{
					value1[i][j]=goal(side_chess,i,j);
					value2[i][j]=goal(3-side_chess,i,j);
					count_1++;
				}
			}
		}
	}
	if(count_1<10)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				if(map[i][j]==0)
				{
					value1[i][j]=goal(side_chess,i,j);
					value2[i][j]=goal(3-side_chess,i,j);
				}
			}
		}	
	}
	int ansx,ansy,ansx1,ansy1,ansx2,ansy2;
	int max_goal_our=INT_MIN;
	int max_goal_oppo=INT_MIN;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(map[i][j]!=0)
			{
				value1[i][j]=INT_MIN;
				value2[i][j]=INT_MIN;
			}
			
		}
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(map[i][j]==0)
			{
				if(value1[i][j]>max_goal_our)
				{
					max_goal_our=value1[i][j];
					ansx1=i;
					ansy1=j;
				}
				if(value2[i][j]>max_goal_oppo)
				{
					max_goal_oppo=value2[i][j];
					ansx2=i;
					ansy2=j;	
				}
			}		
		}
	}
	if(max_goal_our>=max_goal_oppo)
	{
		if(max_goal_our>=9e5)
		{
			ansx=ansx1;
			ansy=ansy1;
		}
		else
		{
			nowx=old_x;
			nowy=old_y;
			maxmin(side_chess,0,INT_MIN,INT_MAX);
			if((maxmin_x==0&&maxmin_y==0)||map[maxmin_x][maxmin_y]!=0||
			/*(maxmin_x-old_x<-4||maxmin_x-old_x>4||maxmin_y-old_y<-4||maxmin_y-old_y>4)
			||*/goal(side_chess,maxmin_x,maxmin_y)<12000)
			{
				ansx=ansx1;
				ansy=ansy1;	
			}
			else
			{
				ansx=maxmin_x;
				ansy=maxmin_y;
			}
		}
			
	}
	else
	{
		if(max_goal_oppo>=9e5)
		{
			ansx=ansx2;
			ansy=ansy2;
		}
		else
		{
			nowx=old_x;
			nowy=old_y;
			maxmin(side_chess,0,INT_MIN,INT_MAX);
			if((maxmin_x==0&&maxmin_y==0)||map[maxmin_x][maxmin_y]!=0||
			/*(maxmin_x-old_x<-4||maxmin_x-old_x>4||maxmin_y-old_y<-4||maxmin_y-old_y>4)
			||*/goal(side_chess,maxmin_x,maxmin_y)<12000)
			{
				ansx=ansx2;
				ansy=ansy2;	
			}
			else
			{
				ansx=maxmin_x;
				ansy=maxmin_y;
			}
		}	
	}
	
	map[ansx][ansy]=side_chess;
	old_x=ansx;
	old_y=ansy;
	
	if(side_chess==1)
	{
		if(OB(side_chess,ansx,ansy)==1)
		{
			display_map();
			printf("black has dropped at %d,%d\n\n",ansx+1,ansy+1);
			printf("black win!!!\n");
			return 1;	
		}	
		display_map();
		printf("black has dropped at %d,%d\n\n",ansx+1,ansy+1);
	}
	else
	{
		if(OB(side_chess,ansx,ansy)==1)
		{
			display_map();
			printf("white has dropped at %d,%d\n\n",ansx+1,ansy+1);
			printf("white win!!!\n");
			return 1;
		}
		display_map();
		printf("white has dropped at %d,%d\n\n",ansx+1,ansy+1);
	}
	
	return 0;
}

int goal(int side_chess,int posx,int posy)
{
	int gobang_x=1,gobang_y=1,gobang_z=1,gobang_w=1;
	int blank_x1=0,blank_x2=0,blank_y1=0,blank_y2=0,blank_z1=0,blank_z2=0,blank_w1=0,blank_w2=0;
	int total_point=0;
	int count_g1=1,count_g2=1; 
	
	//------------------------------------------------------------------------- record the row and the blank
	while(1)
	{
		if(posy-count_g1>=0&&map[posx][posy-count_g1]==side_chess)
		{
			gobang_x++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posy-count_g1>=0&&map[posx][posy-count_g1]==0)
		{
			blank_x1++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posy+count_g2<len&&map[posx][posy+count_g2]==side_chess)
		{
			gobang_x++;
			count_g2++;	
		}
		else
		break;
	}
	while(1)
	{
		if(posy+count_g2<len&&map[posx][posy+count_g2]==0)
		{
			blank_x2++;
			count_g2++;	
		}
		else
		break;
	}
	
	//----------------------------------------------------------------------- record the line and the blank
	
	count_g1=1,count_g2=1; 
	
	while(1)
	{
		if(posx-count_g1>=0&&map[posx-count_g1][posy]==side_chess)
		{
			gobang_y++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posx-count_g1>=0&&map[posx-count_g1][posy]==0)
		{
			blank_y1++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posx+count_g2<len&&map[posx+count_g2][posy]==side_chess)
		{
			gobang_y++;
			count_g2++;	
		}
		else
		break;
	}
	while(1)
	{
		if(posx+count_g2<len&&map[posx+count_g2][posy]==0)
		{
			blank_y2++;
			count_g2++;	
		}
		else
		break;
	}
	//-----------------------------------------------------------------------record the left-up-right-down and the blank
	
	count_g1=1,count_g2=1; 
	while(1)
	{
		if(posx-count_g1>=0&&posy-count_g1>=0&&map[posx-count_g1][posy-count_g1]==side_chess)
		{
			gobang_z++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posx-count_g1>=0&&posy-count_g1>=0&&map[posx-count_g1][posy-count_g1]==0)
		{
			blank_z1++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posx+count_g2<len&&posy+count_g2<len&&map[posx+count_g2][posy+count_g2]==side_chess)
		{
			gobang_z++;
			count_g2++;	
		}
		else
		break;
	}
	while(1)
	{
		if(posx+count_g2<len&&posy+count_g2<len&&map[posx+count_g2][posy+count_g2]==0)
		{
			blank_z2++;
			count_g2++;	
		}
		else
		break;
	}
	
	//--------------------------------------------------------- record the right-up-left-down and the blank
	
	count_g1=1,count_g2=1; 
	while(1)
	{
		if(posx-count_g1>=0&&posy+count_g1<len&&map[posx-count_g1][posy+count_g1]==side_chess)
		{
			gobang_w++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posx-count_g1>=0&&posy+count_g1<len&&map[posx-count_g1][posy+count_g1]==0)
		{
			blank_w1++;
			count_g1++;
		}
		else
		break;
	}
	while(1)
	{
		if(posx+count_g2<len&&posy-count_g2>=0&&map[posx+count_g2][posy-count_g2]==side_chess)
		{
			gobang_w++;
			count_g2++;	
		}
		else
		break;
	}
	while(1)
	{
		if(posx+count_g2<len&&posy-count_g2>=0&&map[posx+count_g2][posy-count_g2]==0)
		{
			blank_w2++;
			count_g2++;	
		}
		else
		break;
	}
	
//------------------------------------------------------------------- judge the pattern
	int mark_4=0, mark_3=0, mark_2=0,mark_4_1=0,mark_3_1=0;
	
	//--------------------------------------------------------------------judge five in a row 
 	if(gobang_x>=5||gobang_y>=5||gobang_z>=5||gobang_w>=5) 
 	return 5e8;
 	
 	//--------------------------------------------------------------------judge alive four in a row
 	if(gobang_x==4&&blank_x1>=1&&blank_x2>=1)
 	mark_4++;
 	if(gobang_y==4&&blank_y1>=1&&blank_y2>=1)
 	mark_4++;
 	if(gobang_z==4&&blank_z1>=1&&blank_z2>=1)
 	mark_4++;
 	if(gobang_w==4&&blank_w1>=1&&blank_w2>=1)
 	mark_4++;
 	if(mark_4==1)
 	return 3e7;// single alive four
 	else if(mark_4>=2)
 	return 9e7;// double alive four
 	
 	//---------------------------------------------------------- judge bump four
	if(gobang_x==4&&(blank_x1>=1||blank_x2>=1))
	mark_4_1++;
	if(gobang_y==4&&(blank_y1>=1||blank_y2>=1))
	mark_4_1++;
	if(gobang_z==4&&(blank_z1>=1||blank_z2>=1))
	mark_4_1++;
	if(gobang_w==4&&(blank_w1>=1||blank_w2>=1))
	mark_4_1++;
	if(mark_4_1>=2)// double bump four
	return 9e5;
	else if(mark_4_1==1)// single bump four
	total_point+=3e4;
	//---------------------------------------------------------------- judge alive three
	if((gobang_x==3&&blank_x1>=1&&blank_x2>=2)||(gobang_x==3&&blank_x1>=2&&blank_x2>=1))
	mark_3++;
	if((gobang_y==3&&blank_y1>=1&&blank_y2>=2)||(gobang_y==3&&blank_y1>=2&&blank_y2>=1))
	mark_3++;
	if((gobang_z==3&&blank_z1>=1&&blank_z2>=2)||(gobang_z==3&&blank_z1>=2&&blank_z2>=1))
	mark_3++;
	if((gobang_w==3&&blank_w1>=1&&blank_w2>=2)||(gobang_w==3&&blank_w1>=2&&blank_w2>=1))
	mark_3++;
	if(mark_3>=2)//double alive three
	total_point+=5e5;
	else if(mark_3==1)
	total_point+=5e4;
	//--------------------------------------------------------------- judge bump four and alive three
	if(mark_4_1>=1&&mark_3>=1)
	return total_point+=7e5;
	
	//---------------------------------------------------------------- judge bump three
	if((gobang_x==3&&blank_x1==0&&blank_x2>=2)||(gobang_x==3&&blank_x2==0&&blank_x1>=2)
	||(gobang_x==3&&blank_x1==1&&blank_x2==1))
	mark_3_1++;
	if((gobang_y==3&&blank_y1==0&&blank_y2>=2)||(gobang_y==3&&blank_y2==0&&blank_y1>=2)
	||(gobang_y==3&&blank_y1==1&&blank_y2==1))
	mark_3_1++;
	if((gobang_z==3&&blank_z1==0&&blank_z2>=2)||(gobang_z==3&&blank_z2==0&&blank_z1>=2)
	||(gobang_z==3&&blank_z1==1&&blank_z2==1))
	mark_3_1++;
	if((gobang_w==3&&blank_w1==0&&blank_w2>=2)||(gobang_w==3&&blank_w2==0&&blank_w1>=2)
	||(gobang_w==3&&blank_w1==1&&blank_w2==1))
	mark_3_1++;
	if(mark_3_1==1)
	total_point+=3e3;
	else if(mark_3_1>1)
	total_point+=6e3;
	//---------------------------------------------------------- judge alive two
	if((gobang_x==2&&blank_x1>=2&&blank_x2>=2)||(gobang_x==3&&blank_x1>=2&&blank_x2>=1)
	||(gobang_x==2&&blank_x1==1&&blank_x2>=3)||(gobang_x==2&&blank_x1>=3&&blank_x2==1))
	mark_2++;
	if((gobang_y==2&&blank_y1>=2&&blank_y2>=2)||(gobang_y==3&&blank_y1>=2&&blank_y2>=1)
	||(gobang_y==2&&blank_y1==1&&blank_y2>=3)||(gobang_y==2&&blank_y1>=3&&blank_y2==1))
	mark_2++;
	if((gobang_z==2&&blank_z1>=2&&blank_z2>=2)||(gobang_z==3&&blank_z1>=2&&blank_z2>=1)
	||(gobang_z==2&&blank_z1==1&&blank_z2>=3)||(gobang_z==2&&blank_z1>=3&&blank_z2==1))
	mark_2++;
	if((gobang_w==2&&blank_w1>=2&&blank_w2>=2)||(gobang_w==3&&blank_w1>=2&&blank_w2>=1)
	||(gobang_w==2&&blank_w1==1&&blank_w2>=3)||(gobang_w==2&&blank_w1>=3&&blank_w2==1))
	mark_2++;
	if(mark_2==1)
	total_point+=9e3;
	else if(mark_2==2)
	total_point+=18000;
	else if(mark_2>2)
	total_point+=3e4;
	//-----------------------------------------------------------------------------judge three and two
	if(mark_2>=1&&mark_3>=1)
	total_point+=4e4;
	//------------------------------------------------------------------------------judge four and two
	if(mark_4_1>=1&&mark_2>=1)
	total_point+=25000;
	
	return total_point;
}

int maxmin(int now_chess, int count, int alpha, int beta)
{
	int i,j,k,h;
	int f;
	int flag;
	if(count>5)
	return f=goal(now_chess,nowx,nowy)-goal(3-now_chess,nowx,nowy);
	if(OB(now_chess,nowx,nowy)==1)
	return f=goal(now_chess,nowx,nowy)-goal(3-now_chess,nowx,nowy);
	histx=nowx;
	histy=nowy;
	if(now_chess==1)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				int mark=0;
				for(k=-3;k<4;k++)
				{
					for(h=-3;h<4;h++)
					{
						if(i+k>=0&&i+k<len&&j+h>=0&&j+h<len)
						{
							if(map[i+k][j+h]!=0)
							mark++;
						}
					}
				}
				if(mark)
				{
					
				if(i-histx>=-4&&i-histx<=4&&j-histy>=-4&&j-histy<=4&&map[i][j]==0)
				{
					if(goal(now_chess,i,j)>=10000||goal(3-now_chess,i,j)>=50000)
					{
					nowx=i;
					nowy=j;
					int val;
					map[i][j]=now_chess;
					val=maxmin(3-now_chess,count+1,alpha,beta);
					map[i][j]=0;
					if(val>alpha)
					{
						alpha=val;
						maxmin_x=i;
						maxmin_y=j;
					}
					if(alpha>=beta)
					return alpha;
					}
				}
				}
			}
		}		
		return alpha;
	}
	else 
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				int mark=0;
				for(k=-3;k<4;k++)
				{
					for(h=-3;h<4;h++)
					{
						if(i+k>=0&&i+k<len&&j+h>=0&&j+h<len)
						{
							if(map[i+k][j+h]!=0)
							mark++;
						}
					}
				}
				if(mark)
				{
				if(i-histx>=-4&&i-histx<=4&&j-histy>=-4&&j-histy<=4&&map[i][j]==0)
				{
					if(goal(now_chess,i,j)>=10000||goal(3-now_chess,i,j)>=50000)
					{
					nowx=i;
					nowy=j;
					int val;
					map[i][j]=now_chess;
					val=maxmin(3-now_chess,count+1,alpha,beta);
					map[i][j]=0;
					if(val<beta)
					{
						beta=val;
					}
					if(alpha>=beta)
					return beta;
					}
				}
				}
			}
		}		
		return beta;
	}	
} 
