#include<bits/stdc++.h>
#include"fft.h"
using namespace std;
vector<Z>tp,ap,bp;
Z u,v,wi;
Z operator +(Z a,Z b){return Z(a.x+b.x,a.y+b.y);}
Z operator -(Z a,Z b){return Z(a.x-b.x,a.y-b.y);}
Z operator *(Z a,Z b){return Z(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);}
Z operator /(Z a,Z b){
    double s=b.x*b.x+b.y*b.y;
    return Z((a.x*b.x+a.y*b.y)/s,(-a.x*b.y+b.x*a.y)/s);
}
void fft(vector<Z>&a,int sig){
	tp.clear();
	for (int i=0;i<a.size();i++)tp.push_back(Z(0));
	for (int i=0,j,k,l;i<a.size();i++){
		for (j=i,k=0,l=1;l<a.size();l<<=1,j>>=1)k=(k<<1)+(j&1);
	    tp[i]=a[k];
	}
	for (int i=2,hal,j,k;i<=a.size();i<<=1)
		for (hal=i>>1,j=0;j<hal;j++){
			wi=Z(cos(j*pi*sig/hal),sin(j*pi*sig/hal));
			for (k=j;k<a.size();k+=i){
				u=tp[k];
				v=tp[k+hal]*wi;
				tp[k]=u+v;
				tp[k+hal]=u-v;
			}
		}
    a=tp;
}
vector<double> convol(vector<double>a,vector<double>b)
{
    int len=1,lenc=a.size()+b.size()-1;
    while (len<a.size()+b.size())len<<=1;
    ap.clear(),bp.clear();
    for (int i=0;i<a.size();i++)ap.push_back(Z(a[i]));
    for (int i=0;i<b.size();i++)bp.push_back(Z(b[i]));
    while (ap.size()<len)ap.push_back(Z());
    while (bp.size()<len)bp.push_back(Z());
    fft(ap,1),fft(bp,1);
    for (int i=0;i<len;i++)ap[i]=ap[i]*bp[i];
    fft(ap,-1);
    a.clear();
    for (int i=0;i<lenc;i++)a.push_back(ap[i].x/len);
    return a;
}
vector<double> niconvol(vector<double>a,vector<double>b)
{
    int len=1,lenc=a.size()-b.size()+1;
    while (len<a.size()+b.size())len<<=1;
    ap.clear(),bp.clear();
    for (int i=0;i<a.size();i++)ap.push_back(Z(a[i]));
    for (int i=0;i<b.size();i++)bp.push_back(Z(b[i]));
    while (ap.size()<len)ap.push_back(Z());
    while (bp.size()<len)bp.push_back(Z());
    fft(ap,1),fft(bp,1);
    for (int i=0;i<len;i++)ap[i]=ap[i]/bp[i];
    fft(ap,-1);
    a.clear();
    for (int i=0;i<lenc;i++)a.push_back(ap[i].x/len);
    return a;
}
