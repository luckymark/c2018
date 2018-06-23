#include<bits/stdc++.h>
#include"CNeuralNet.h"
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int T=1000,crowd=40,T1=100;
CNeuralNet network[crowd*crowd],bestnet;
bool cmp(const CNeuralNet&a,const CNeuralNet&b){
    return a.loss<b.loss;
}
CNeuralNet operator*(CNeuralNet a,CNeuralNet b){
    for (int i=0;i<a.Layer.size();i++){ 
        int x=rand()%101;
        for (int j=0;j<a.Layer[i].w.size();j++){
            a.Layer[i].w[j]=(a.Layer[i].w[j]*x+b.Layer[i].w[j]*(100-x))/100;
        }
    }
    return a;
}
int main(){
    srand((int)time(0));
    string list="list.txt";
    string model="model.in";
    fstream f;
    bestnet.train(list,model,1,1);
    cout<<"The origin loss is:"<<bestnet.loss<<endl;
    network[0]=bestnet;
    for (int i=1;i<crowd;i++)
        network[i].train(list,model,0,1);
    int clo=0;
    while (1){
        ++clo;
        if (clo==10){
            clo=0;
            int x=rand()%5;
            cout<<"Bang!!!Left "<<x+1<<"people"<<endl;
            for (int i=x;i<crowd;i++)
                network[i].train(list,model,0,1);
        }
        int sum=crowd-1;
        for (int i=0;i<crowd;i++)
            for (int j=0;j<crowd;j++)
                if (i!=j)
                    network[++sum]=network[i]*network[j];
        for (int i=0;i<crowd*crowd;i++)
            network[i].train(list,model,0,0);
        sort(network,network+crowd*crowd,cmp);
        if (bestnet.loss>network[0].loss){
            if (network[0].loss/bestnet.loss<0.80)clo=0;
            bestnet=network[0];
            cout<<"find a better model with loss of "<<bestnet.loss<<"!"<<endl;
            bestnet.work(list,model,0);
            bestnet.save(model);
            cout<<"Save successful!!"<<endl;
        }
        for (int i=0;i<crowd*crowd;i++){
            if (rand()%10==1)network[i].train(list,model,0,1);
            else
            if (rand()%10==1)
            for (int j=0;j<network[i].Layer[j].w.size();j++)
                if (rand()%5==1){
                    if (rand()&1)network[i].Layer[j].w[j]=(rand()%100000+1)*(-0.001);
                    else
                        network[i].Layer[j].w[j]=(rand()%100000+1)*(0.001);
                }
        }
        for (int i=0;i<crowd*crowd;i++)
            network[i].train(list,model,0,0);
        sort(network,network+crowd*crowd,cmp);
        if (bestnet.loss>network[0].loss){
            if (network[0].loss/bestnet.loss<0.80)clo=0;
            bestnet=network[0];
            cout<<"find a better model with loss of "<<bestnet.loss<<"!"<<endl;
            bestnet.work(list,model,0);
            bestnet.save(model);
            cout<<"Save successful!!"<<endl;
        }
    }
    /*for (int i=1;i<=1000;i++){
        f.open("list.txt");
        while (f>>inputData){
            outputData=inputData;
            inputData+=".in";
            outputData+=".out";
            network.train(inputData,outputData,model,1);
        }
        f.close();
    }*/
    /*cout<<"Test Begin!"<<endl;
    f.open("list.txt");
    while (f>>inputData){
        outputData=inputData;
        inputData+=".in";
        outputData+=".out";
        network.work(inputData,outputData,model);
    }
    f.close();*/
    return 0;
}
