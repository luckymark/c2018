#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<vector<int> > VVI;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;
#define len(a) ((int)(a.size()))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ms(x,c) memset(x,c,sizeof(x))
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
template<class T> T sqr(const T &x) { return x*x; }
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; }
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); }
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; }
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; }

const double pi=acos(-1.0);
const double eps=1e-11;
const int oo=2*(1<<30)+1;

int n,i,j,k;
int main()
{
 	//freopen("1.in","r",stdin);freopen("1.out","w",stdout)
 	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin>>a>>b;
	cout<<a+b<<endl; 

 	return 0;
}



