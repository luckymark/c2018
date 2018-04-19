#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void UP();
void DOWN();
void LEFT();
void RIGHT();
int JudgeObstacle();
void PRTmaze();

int x=1,y=1;    //人物坐标 
int judgeRE;

char a[13][31]={"##############################",
			    "#O    ####        ############",
			    "##### #### #### ##############",
			    "#     #### #### ##############",
			    "#####      #### ##############",
			    "############### ##############",
			    "###############  #############",
	 		    "################   ###########",
	 		    "################## ###########",
	 		    "################## ###########",
	 		    "##################     #######",
	 		    "######################        ",
				"##############################"};

int main(int argc, char *argv[]) 
{
	system("color f0");
	
	PRTmaze();
	
	int ch;
	while( (ch=getch())!=0x1B )
    {
   		switch(ch)
     	{
      		case 0xE0:
         	switch(ch=getch())
         	{
            	case 72:  UP(); break;
            	case 80:  DOWN(); break;
            	case 75:  LEFT(); break;
            	case 77:  RIGHT(); break;
            	default:continue;
         	}
         	if(x==11 && y==29)
         	{
         		MessageBox(NULL,"恭喜通关","Success",MB_OK);
         		exit(0);
			}
         	break;
      		default:
         	continue;
      }
   }
	
	return 0;
}

void UP()
{
	if(JudgeObstacle(x-1,y))
	{
		a[x][y]=' ';
		--x;
		a[x][y]='O';
	}
	else
	{
		
	}
	PRTmaze();
}

void DOWN()
{
	if(JudgeObstacle(x+1,y))
	{
		a[x][y]=' ';
		++x;
		a[x][y]='O';
	}
	PRTmaze();
}

void LEFT()
{
	if(JudgeObstacle(x,y-1))
	{
		a[x][y]=' ';
		--y;
		a[x][y]='O';
	}
	PRTmaze();
}

void RIGHT()
{
	if(JudgeObstacle(x,y+1))
	{
		a[x][y]=' ';
		++y;
		a[x][y]='O';
	}
	PRTmaze();
}

int JudgeObstacle(int X,int Y)
{
	if(a[X][Y]==' ')
		return 1;
	else
		return 0;
}

void PRTmaze()
{
	system("cls");
	int i;
	for(i=0;i<=12;i++)
	{
		printf("%s\n",a[i]);
	}
}
