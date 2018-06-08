#include<bits/stdc++.h>
#include"CNeuralNet.h"
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
// 清除屏幕  
#define CLEAR() printf("\033[2J")  
  
// 上移光标  
#define MOVEUP(x) printf("\033[%dA", (x))  
  
// 下移光标  
#define MOVEDOWN(x) printf("\033[%dB", (x))  
  
// 左移光标  
#define MOVELEFT(y) printf("\033[%dD", (y))  
  
// 右移光标  
#define MOVERIGHT(y) printf("\033[%dC",(y))  
  
// 定位光标  
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))  
  
// 光标复位  
#define RESET_CURSOR() printf("\033[H")  
  
// 隐藏光标  
#define HIDE_CURSOR() printf("\033[?25l")  
  
// 显示光标  
#define SHOW_CURSOR() printf("\033[?25h")  
  
//反显  
#define HIGHT_LIGHT() printf("\033[7m")  
#define UN_HIGHT_LIGHT() printf("\033[27m") 
using namespace std;
const int N=8,M=8;
int num;
bool pendown;
char penpoint;
struct point{
    int X,Y; 
};
struct Cursor{
	point coord;
	int n,m;
	void show(){
	    MOVETO(coord.X,coord.Y);
	}
	Cursor(int x=0,int y=0,int N=0,int M=0){
		coord.X=x;
		coord.Y=y;
	    show();
		n=N,m=M;
	}
	bool move(int x,int y){
		if (coord.X+x==0||coord.X+x>n||coord.Y+y==0||coord.Y+y>m)return 0;
		coord.X+=x,coord.Y+=y;
		return 1;
	}
}a;
char Map[N*2][M*2];
string tostring(int x){
	string s;
	s.clear();
	while (x)s+=x%10+'0',x/=10;
	if (!s.size())s+='0';
	return string(s.rbegin(),s.rend());
}
void sleep(int x){
	while (x--)
		for (int i=0;i<15e7;i++);
}
void waitdraw(){
	for (int i=5;i;i--){
        printf("\033c");
		cout<<"Datas are loading"<<endl;
		cout<<"Please wait "<<i<<"s";
		for (int j=1;j<=5-i;j++)cout<<".";
		sleep(1);
	}
}
void savemap(){
	ofstream f;
	f.open("test.in");
	for (int i=1;i<=N;i++){
		for (int j=1;j<=M;j++)
			if (Map[i][j]==' ')
				f<<0;
			else
				f<<1;
		f<<endl;
	}
	f.close();
}
void init(){
	waitdraw();
    printf("\033c");
	for (int i=0;i<=N+1;i++)for (int j=0;j<=M+1;j++)Map[i][j]=' ';
	for (int i=0;i<=N+1;i++)Map[i][0]=Map[i][M+1]='|';
	for (int i=0;i<=M+1;i++)Map[0][i]=Map[N+1][i]='-';
	Map[0][0]=Map[0][M+1]=Map[N+1][0]=Map[N+1][M+1]='+';
	penpoint='*';
	pendown=0;
	a=Cursor(1,1,N,M);
}
void drawmap(){
    printf("\033c");
	for (int i=0;i<=N+1;i++){
		for (int j=0;j<=M+1;j++)
			cout<<Map[i][j];
		cout<<endl;
	}
	cout<<"Use direction keys to move the cursor."<<endl;
	cout<<"u:lift up pen/eraser"<<endl;
	cout<<"d:put down pen/eraser"<<endl;
	cout<<"e:change to eraser"<<endl;
	cout<<"p:change to pen"<<endl;
	cout<<"r:restart"<<endl;
	cout<<"s:save the data"<<endl;
	cout<<"q:quit"<<endl;
	if (penpoint=='*')
		cout<<"Now you are using pen.";
	else
		cout<<"Now you are using eraser.";
	if (pendown)
		cout<<"And the pen/eraser point is down."<<endl;
	else
		cout<<"And the pen/eraser point is up."<<endl;
	a.show();
} 
void change(){
	if (pendown)Map[a.coord.Y][a.coord.X]=penpoint;
}
int test(){
    CNeuralNet network[10];
    string inputfile="test.in";
    int ans=0;
    for (int i=0;i<10;i++){
        string model="model";
        model+=to_string(i);
        model+=".in";
        network[i].load(model);
        network[i].test(inputfile);
        if (network[i].accuracy>network[ans].accuracy)ans=i;
    }
    return ans;
}
int main(){
    printf("\033c");
	while (1){
		system("cls");
		cout<<"Input the number you want to draw(or q to quit):";
		char c;
		cin>>c;
		if (c=='q'){
            printf("\033c");
			cout<<"Thanks for using"<<endl;
			return 0;
		}
		num=c-'0';
		if (num<0||num>9){
			cout<<"Sorry!Please input 0~9 or q!"<<endl;
			sleep(3);
			continue;
		}
		init();
		int tty = open("/dev/tty", O_RDONLY);
        struct termios newt, oldt;
        tcgetattr(tty, &oldt);
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr(tty, TCSANOW, &newt);
		drawmap();
		while (1){
			bool sig=0;
			char c;
			read(tty, &c, 1);
			cout<<c;
			switch(c){
				case'q':
                printf("\033c");
                printf("Thanks for using it!");
                tcsetattr(tty, TCSANOW, &oldt);
				return 0;
				case'u':
				pendown=0;
				break;
				case'd':
				pendown=1;
				change();
				break;
				case'e':
				penpoint=' ';
				pendown=0;
				break;
				case'p':
				penpoint='*';
				pendown=0;
				break;
				case'r':
				init();
				break;
				case's':
				sig=1;
				break;
				case-32:
				int x=0,y=0;
				cout<<c;
				switch(c){
					case 65:
					y=-1;
					break;
					case 66:
					y=1;
					break;
					case 68:
					x=-1;
					break;
					case 67:
					x=1;
					break;
				}
					if (a.move(x,y))change();
				break;
			}
			if (sig)break;
			//drawmap();
		}
		savemap();
        printf("\033c");
        int ans=test();
        printf("Your input is %d.\nMy answer is %d.",num,ans);
        if (num!=ans){
            printf("Wa!\n");    
            return 0;
        }else
            printf("Ac!\n");
	    printf("Print any input key to continue!");
	    char cc;
	    cin>>cc;
	}
	return 0;
}
