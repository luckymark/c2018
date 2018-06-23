#include<bits/stdc++.h>
using namespace std;
const int n=8,m=8;
char a[n][m];
int cnt,cnt1,num;
string s1in,s1out,s2in,s2out;
void loadcnt(){
    fstream f;
    f.open("cnt.txt");
    f>>cnt;
    f.close();    
}
void loadcnt1(){
    fstream f;
    f.open("uncheckeddata/list.txt");
    f>>cnt1;
    f.close();    
}
void loada(string b){
    fstream f;
    f.open(b);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            f>>a[i][j];
    f.close();
}
void loadnum(string a){
    fstream f;
    f.open(a);
    f>>num;
    f.close();
}
void savea(string b){
    ofstream f;
    f.open(b);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            f<<a[i][j];
        cout<<endl; 
    }
    f.close();
}
void savenum(string a){
    ofstream f;
    f.open(a);
    f<<num;
    f.close();
}
void savecnt(){
    ofstream f;
    f.open("cnt.txt");
    f<<cnt;
    f.close();    
}
void savelist(string a,string b){
    ofstream f;
    f.open(a,ios::app);
    f<<b<<endl;
    f.close();
}
void show(){
    cout<<"\033c";
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++)
            if (a[i][j]=='1')cout<<'*';
            else
                cout<<' ';
        cout<<endl;
    } 
    cout<<num<<endl;
    cout<<"Is it ok?(y/n)";
}
int main(){
    loadcnt();
    loadcnt1();
    for (int i=0;i<=cnt1;i++){
        s1in="uncheckeddata/data";
        s1in+=to_string(i);
        s1out=s1in;
        s1in+=".in";
        s1out+=".out";
        loada(s1in);
        loadnum(s1out);
        show();
        char sig;
        cin>>sig;
        if (sig=='y'){
            ++cnt;
            s2in="data";
            s2in+=to_string(cnt);
            savelist("../list.txt",s2in);
            s2out=s2in;
            s2in+=".in";
            s2out+=".out";
            savea(s2in);
            savenum(s2out);
        }
    }
    savecnt();
    return 0;
}
