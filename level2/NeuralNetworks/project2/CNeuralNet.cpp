#include<bits/stdc++.h>
#include"CNeuralNet.h"
#include"fft.h"
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int Rounds=10;
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
    int sum=0;
    for (int i=0;i<b.size();i++){
        double v=0;
        int len1=len;
        if (i<a.size()%b.size())len1++;
        for (int j=0;j<len1;j++)
            v+=a[sum+j];
        sum+=len1;
        b[i]*=v;
    }
    return b;
}
vector<double> operator<(vector<double>a,vector<double>b){
    int len=a.size()/b.size();
    int sum=0;
    for (int i=0;i<b.size();i++){
        double v=0;
        int len1=len;
        if (i<a.size()%b.size())len1++;
        for (int j=0;j<len1;j++)
            v+=a[sum+j];
        v/=b[i];
        for (int j=0;j<len1;j++)
            a[sum+j]*=v;
        sum+=len1;
    }
    return a;
}
void CNeuralNet::addLayer(int Numvec, int tag)
{
    Layer.push_back(SNeuronLayer(Numvec, tag));
}
void CNeuralNet::forward(vector<double> Input)
{
    Output.clear();
    Output.push_back(Input);
    for (int i=0;i<Layer.size();i++)
        if (Layer[i].tag==1){
            Output.push_back(convol(Output[i],Layer[i].w));
        }else
            Output.push_back(Output[i]>Layer[i].w);
}
void CNeuralNet::backward(vector<double> RealOutput)
{
    static double sum;
    sum=Layer.size();
    int sum1=Output.size()-1;
    double Rate=min(rand()%50*0.1,1.0);
    static vector<double> ChangeSetting;
    for (int i=Layer.size()-1;i>=0;i--){
        if (Layer[i].tag==1){
            ChangeSetting=niconvol(RealOutput,Output[sum1-1]);
            while (ChangeSetting.size()>Layer[i].w.size())ChangeSetting.pop_back();
            for (int j=0;j<Layer[i].w.size();j++)
                if (isnormal(ChangeSetting[j]))Layer[i].w[j]=ChangeSetting[j];
            RealOutput=niconvol(RealOutput,Layer[i].w);
            while (RealOutput.size()>Output[sum1-1].size())RealOutput.pop_back();
        }else{
            ChangeSetting=((Output[sum1]*(1-Rate))+(RealOutput*Rate))/Output[sum1];
            Layer[i].change(ChangeSetting);
            RealOutput=(Output[sum1-1]<(RealOutput/Layer[i].w));
        }
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
        d.clear();
        int tag;
        f>>tag;
        f>>num;
        while (num--){
            double x;
            f>>x;
            d.push_back(x);
        }
        Layer.push_back(SNeuronLayer(d,tag));
    }
    f.close();
}
void CNeuralNet::save(string&filename)
{
    ofstream f;
    f.open(filename.c_str());
    f<<Layer.size()<<endl;
    for (int i=0;i<Layer.size();i++){
        f<<Layer[i].tag<<endl;
        f<<Layer[i].w.size()<<endl;
        for (int j=0;j<Layer[i].w.size();j++)
            f<<Layer[i].w[j]<<' ';
        f<<endl;
    }
    f.close();
}
vector<double>loadData(string&filename,int sum)
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
        else{
            addLayer(16,0);
            addLayer(rand()%20+2,1);
            addLayer(rand()%20+2,1);
            addLayer(8,0);
            addLayer(4,0);
            addLayer(1,0);
        }
    }
    vector<SNeuronLayer>Layer1=Layer;
    double loss1=0;
    int d[inputData.size()];
    for (int j=0;j<inputData.size();j++){
        vector<double>dataInput=loadData(inputData[j],64);
        vector<double>dataOutput=loadData(outputData[j],1);
        forward(dataInput);
        loss1+=exp(abs(Output[Output.size()-1][0]-dataOutput[0]));
    }
    for (int i=0;i<inputData.size();i++)d[i]=i;
    for (int i=1;i<=Rounds;i++){
        random_shuffle(d+0,d+inputData.size());
        for (int J=0;J<inputData.size();J++){
            if (rand()%5==1)continue;
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
            loss+=exp(abs(Output[Output.size()-1][0]-dataOutput[0]));
        }
        if (loss<loss1||loss1<0)loss1=loss,Layer1=Layer;
    }
    f.close();
    Layer=Layer1,loss=loss1;
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
}
SNeuronLayer::SNeuronLayer(int Numvec,int Tag){
    tag=Tag;
    int limit=10000000;
    if (Tag)limit=1000;
    while (Numvec--)
        if (rand()&1)
            w.push_back((rand()%limit+1)*(-0.00001));
        else
            w.push_back((rand()%limit+1)*0.00001);
}
SNeuronLayer::SNeuronLayer(vector<double>d,int Tag)
{
    w=d,tag=Tag;
}
void SNeuronLayer::change(vector<double>&d){
    for (int i=0;i<d.size();i++)
        w[i]*=d[i];
}
