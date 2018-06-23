#include<bits/stdc++.h>
#include"CNeuralNet.h"
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int T=100000,crowd=20,outcrowd=100;
CNeuralNet network[crowd*crowd],bestnet;
bool cmp(const CNeuralNet&a,const CNeuralNet&b){
    return a.loss<b.loss;
}
CNeuralNet operator*(CNeuralNet a,CNeuralNet b){
    for (int i=0;i<a.Layer.size();i++)
        if (a.Layer[i].tag){
            if (rand()%2==1)a.Layer[i]=b.Layer[i];
        }else
        for (int j=0;j<a.Layer[i].w.size();j++)
            a.Layer[i].w[j]=(a.Layer[i].w[j]+b.Layer[i].w[j])/2;
    return a;
}
int main(){
    srand((int)time(0));
    string list="list.txt";
    string model="model.in";
    fstream f;
    bestnet.train(list,model,1,1);
    network[0]=bestnet;
    for (int i=1;i<crowd;i++)
        network[i].train(list,model,0,1);
    cout<<"The origin loss is:"<<bestnet.loss<<endl;
    int clo=0;
    while (1){
        ++clo;
        if (clo==40){
            for (int i=0;i<crowd;i++)
                network[i].train(list,model,0,1);
        }
        int sum=crowd-1;
        for (int i=0;i<crowd;i++)
            for (int j=i+1;j<crowd;j++)
                network[++sum]=network[i]*network[j];
        for (int i=0;i<sum;i++)
            network[i].train(list,model,0,0);
        for (int i=sum;i<sum+outcrowd;i++)
            network[i].train(list,model,0,1);
        sum+=outcrowd; 
        sort(network,network+sum,cmp);
        if (bestnet.loss>network[0].loss){
            clo=0;
            bestnet=network[0];
            cout<<"find a better model with loss of "<<bestnet.loss<<"!"<<endl;
            bestnet.work(list,model,0);
            bestnet.save(model);
            cout<<"Save successful!!"<<endl;
        }
        /*for (int i=0;i<sum;i++)
            for (int k=0;k<network[i].Layer.size();k++){
                int limit=10000000;
                if (network[i].Layer[k].tag)limit=1000;
                for (int j=0;j<network[i].Layer[k].w.size();j++)
                    if (rand()%100==1){
                        if (rand()&1)
                            network[i].Layer[k].w[j]=(rand()%limit+1)*(-0.00001);
                        else
                            network[i].Layer[k].w[j]=(rand()%limit+1)*(0.00001);
                    }
            }
        for (int i=0;i<sum;i++)
            network[i].train(list,model,0,0);
        sort(network,network+sum,cmp);
        if (bestnet.loss>network[0].loss){
            clo=0;
            bestnet=network[0];
            cout<<"find a better model with loss of "<<bestnet.loss<<"!"<<endl;
            bestnet.work(list,model,0);
            bestnet.save(model);
            cout<<"Save successful!!"<<endl;
        }*/
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
