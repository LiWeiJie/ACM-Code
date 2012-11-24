/*
  PROG:numtri
  LANG:C++
  ID:apprent2
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf

#define N 505010


using namespace std;


int g[N],ori[N] ;


int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    memset(g,0,sizeof(g));
    int r;
    sf("%d",&r);
//    sf("%d",&ori[1]);
    FOR(i,1,r+1)
    {
        FOR(j,(i-1)*i/2+1,(i-1)*i/2+1+i)
            sf("%d",&ori[j]);
    }
//    pf("%d ",ori[1]);
//    FOR(i,1,r+1)
//    {
//        FOR(j,(i-1)*i/2+1,(i-1)*i/2+1+i)
//            pf("%d ",ori[j]);
//    }
    int maxn = (r+1)*r/2;
    int maxm = r*(r-1)/2;
    int count = 0,n=1;
    FOR(i,1,maxm+1)
    {
        count++;
        if (g[i]+ori[i]>g[i+n]) g[i+n] = g[i]+ori[i];
        if (g[i]+ori[i]>g[i+n+1]) g[i+n+1] = g[i]+ori[i];
        if (count == n)
        {
            n++;
            count = 0;
        }
    }
    int ans = 0;
    FOR(i,maxm+1,maxn+1)
    {
        if (g[i]+ori[i]>ans) ans = g[i]+ori[i];
    }
    pf("%d\n",ans);
    return 0;
}
