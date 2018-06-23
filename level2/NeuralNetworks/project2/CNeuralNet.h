#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
struct SNeuronLayer// 神经层
{
    int tag;//0:分块;1:卷积
    vector<double>w;
    SNeuronLayer(int Numvec=0, int Tag=0);
    SNeuronLayer(vector<double>d,int Tag);
    void change(vector<double>&d);
};
struct CNeuralNet// 神经网络对象
{
    vector<SNeuronLayer>Layer;
    vector<vector<double> >Output;
    double loss;
    void addLayer(int Numvec,int tag);
    void forward(vector<double> Input);
    void backward(vector<double> RealOutput);
    void load(string&filename);
    void save(string&filename);
    void train(string&list,string&model,bool sig,bool sig1);
    void work(string&list,string&model,bool sig);
};

