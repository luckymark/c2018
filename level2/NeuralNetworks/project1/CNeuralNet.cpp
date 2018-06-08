#include<bits/stdc++.h>
#include"CNeuralNet.h"
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int Rounds=20;
double sigmoid(double x)
{
    return (1 / (1 + exp(-x)));
}
double nisigmoid(double x)
{
    return log(x/(1-x));
}
void nisigmoid(vector<double>&a){
    for (int i=0;i<a.size();i++)
        a[i]=nisigmoid(a[i]);
} 
vector<double> operator-(vector<double>a,vector<double>b){
    for (int i=0;i<a.size();i++)
        a[i]-=b[i];
    return a;
}
vector<double> operator+(vector<double>a,vector<double>b){
    for (int i=0;i<a.size();i++)
        a[i]+=b[i];
    return a;
}
vector<double> operator/(vector<double>a,vector<double>b){
    for (int i=0;i<a.size();i++){
        a[i]/=b[i];
    }
    return a;
}
vector<double> operator/(vector<double>a,double b){
    for (int i=0;i<a.size();i++)
        a[i]/=b;
    return a;
}
vector<double> operator*(vector<double>a,double b){
    for (int i=0;i<a.size();i++)
        a[i]*=b;
    return a;
}
vector<double> operator>(vector<double>a, vector<double>b){
    int len=a.size()/b.size();
    for (int i=0;i<b.size();i++){
        double v=0;
        for (int j=0;j<len;j++)
            v+=a[i*len+j];
        //b[i]=sigmoid(b[i]*v);
        b[i]*=v;
    }
    return b;
}
vector<double> operator<(vector<double>a,vector<double>b){
    int len=a.size()/b.size();
    for (int i=0;i<b.size();i++){
        double v=0;
        for (int j=0;j<len;j++)
            v+=a[i*len+j];
        v/=b[i];
        for (int j=0;j<len;j++)
            a[i*len+j]*=v;
    }
    return a;
}

void CNeuralNet::addLayer(int Numvec)
{
    Layer.push_back(SNeuronLayer(Numvec));
}
void CNeuralNet::forward(vector<double> Input)
{
    Output.clear();
    Output.push_back(Input);
    for (int i=0;i<Layer.size();i++)
        Output.push_back(Output[i]>Layer[i].w);
}
void CNeuralNet::backward(vector<double> RealOutput)
{
    static double sum;
    sum=Layer.size();
    int sum1=Output.size()-1;
    double Rate=min(rand()%500*0.01,1.0);
    if (rand()&3)Rate=1;
    static vector<double> ChangeSetting;
    for (int i=Layer.size()-1;i>=0;i--){
        ChangeSetting=((Output[sum1]*(1-Rate))+(RealOutput*Rate))/Output[sum1];    
        Layer[i].change(ChangeSetting);
        if (sum1)
            RealOutput=(Output[sum1-1]<(RealOutput/Layer[i].w));
        sum--;
        sum1--;
    }
}
void CNeuralNet::load(string&filename)
{
    fstream f;
    f.open(filename.c_str());
    int sum=0;
    f>>sum;
    int num;
    vector<double>d;
    Layer.clear();
    while (sum--){
        f>>num;
        d.clear();
        while (num--){
            double x;
            f>>x;
            d.push_back(x);
        }
        Layer.push_back(SNeuronLayer(d));
    }
    f.close();
}
void CNeuralNet::save(string&filename)
{
    ofstream f;
    f.open(filename.c_str());
    f<<Layer.size()<<endl;
    for (int i=0;i<Layer.size();i++){
        f<<Layer[i].w.size()<<endl;
        for (int j=0;j<Layer[i].w.size();j++)
            f<<Layer[i].w[j]<<' ';
        f<<endl;
    }
    f.close();
}
vector<double> CNeuralNet::loadData(string&filename,int sum)
{
    fstream f;
    f.open(filename.c_str());
    vector<double>d;
    d.clear();
    for (int i=0;i<sum;i++){
        char c;
        f>>c;
        d.push_back(c-'0'+1);
    }
    f.close();
    return d;
}
double power(double x,int y){
    double s=1;
    while (y--)s*=x;
    return s;
}
void CNeuralNet::train(string&list,string&model,bool sig,bool sig1)
{
    fstream f;
    f.open(list);
    vector<string> inputData;
    vector<string> outputData;
    inputData.clear(),outputData.clear();
    string s;
    while (f>>s){
        inputData.push_back(s+".in");
        outputData.push_back(s+".out");
    }
    if (sig1){
        Layer.clear();
        if (sig)load(model);
        else
            for (int i=64;i;i/=2)addLayer(i);
    }
    vector<SNeuronLayer>Layer1=Layer;
    double loss1=0;
    for (int j=0;j<inputData.size();j++){
        vector<double>dataInput=loadData(inputData[j],64);
        vector<double>dataOutput=loadData(outputData[j],1);
        forward(dataInput);
        loss1+=exp(exp(abs(Output[Output.size()-1][0]-dataOutput[0])));
    }
    int d[inputData.size()];
    for (int i=0;i<inputData.size();i++)d[i]=i;
    for (int i=1;i<=Rounds;i++){
        random_shuffle(d+0,d+inputData.size());
        int x=rand()%20+5;
        for (int J=0;J<inputData.size();J++){
            if (rand()%x==1)continue;
            int j=d[J];
            vector<double>dataInput=loadData(inputData[j],64);
            vector<double>dataOutput=loadData(outputData[j],1);
            forward(dataInput);
            backward(dataOutput);
            forward(dataInput);
        }
        loss=0;
        for (int j=0;j<inputData.size();j++){
            vector<double>dataInput=loadData(inputData[j],64);
            vector<double>dataOutput=loadData(outputData[j],1);
            forward(dataInput);
            loss+=exp(exp(abs(Output[Output.size()-1][0]-dataOutput[0])));
        }
        if (loss<loss1)loss1=loss,Layer1=Layer;
    }
    f.close();
    Layer=Layer1,loss=loss1;
   /* cout<<"My output:"<<endl;
    for (int i=0;i<Output[Output.size()-1].size();i++)
        cout<<Output[Output.size()-1][i]<<' ';
    cout<<endl;
    cout<<"Standard output:"<<endl;
    for (int i=0;i<dataOutput.size();i++)
        cout<<dataOutput[i]<<' ';
    cout<<endl;
    save(model);*/
}
void CNeuralNet::work(string&list,string&model,bool sig)
{
    if (sig){
        Layer.clear();
        load(model);
    }
    fstream f;
    f.open(list);
    vector<string> inputData;
    vector<string> outputData;
    inputData.clear(),outputData.clear();
    string s;
    while (f>>s){
        inputData.push_back(s+".in");
        outputData.push_back(s+".out");
    }
    cout<<"Test begin!!"<<endl;
    for (int j=0;j<inputData.size();j++){
        vector<double>dataInput=loadData(inputData[j],64);
        vector<double>dataOutput=loadData(outputData[j],1);
        forward(dataInput);
        cout<<"My output:"<<endl;
        cout<<Output[Output.size()-1][0]-1<<endl;
        cout<<"Standard output:"<<endl;
        cout<<dataOutput[0]-1<<endl;
    }
    f.close();
    /*cout<<"My output:"<<endl;
    for (int i=0;i<Output[Output.size()-1].size();i++)
        cout<<Output[Output.size()-1][i]<<' ';
    cout<<endl;
    cout<<"Standard output:"<<endl;
    for (int i=0;i<dataOutput.size();i++)
        cout<<dataOutput[i]<<' ';
    cout<<endl;*/
    //save(model);
}
SNeuronLayer::SNeuronLayer(int Numvec){
    while (Numvec--)
        if (rand()&1)
            w.push_back((rand()%100000+1)*(-0.001));
        else
            w.push_back((rand()%100000+1)*0.001);
}
SNeuronLayer::SNeuronLayer(vector<double>d)
{
    w=d;
}
void SNeuronLayer::change(vector<double>&d){
    for (int i=0;i<d.size();i++)
        w[i]*=d[i];
}
