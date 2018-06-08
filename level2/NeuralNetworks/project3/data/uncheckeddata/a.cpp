#include<bits/stdc++.h>
#include"CNeuralNet.h"
using namespace std;
const int N=8,M=8;
int cnt,num;
bool pendown;
char penpoint;
struct Cursor{
	COORD coord;
	int n,m;
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	Cursor(int x=0,int y=0,int N=0,int M=0){
		coord.X=x;
		coord.Y=y; 
		SetConsoleCursorPosition(hout,coord); 
		n=N,m=M;
	}
	bool move(int x,int y){
		if (coord.X+x==0||coord.X+x>n||coord.Y+y==0||coord.Y+y>m)return 0;
		coord.X+=x,coord.Y+=y;
		return 1;
	}
	void show(){
		SetConsoleCursorPosition(hout,coord); 
	}
}a;
char Map[N*2][M*2];
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
	f.open("test.txt");
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
string tostring(int x){
	string s;
	s.clear();
	while (x)s+=x%10+'0',x/=10;
	if (!s.size())s+='0';
	return string(s.rbegin(),s.rend());
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
int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
}
void change(){
	if (pendown)Map[a.coord.Y][a.coord.X]=penpoint;
}
void test(){
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
}
int main(){
    printf("\033c");
	loadcnt();
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
		drawmap();
		while (1){
			bool sig=0;
			char c;
			if (_kbhit()){
				c=getch();
				switch(c){
					case'q':
                    printf("\033c");
					cout<<"Thanks for using"<<endl;
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
					cnt--;
					init();
					break;
					case's':
					sig=1;
					break;
					case-32:
					c=getch();
					int x=0,y=0;
					switch(c){
						case 'H':
						y=-1;
						break;
						case 'P':
						y=1;
						break;
						case 'K':
						x=-1;
						break;
						case 'M':
						x=1;
						break;
					}
					if (a.move(x,y))change();
					break;
				}
				if (sig)break;
				drawmap();
			}
		}
		savemap();
        printf("\033c");
	    
	}
	return 0;
}
