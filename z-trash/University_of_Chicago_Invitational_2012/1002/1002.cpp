#include <stdio.h>
//#include <algorithm>
//#include <iomanip>
#include <cstring>
#include <vector>
//#include <queue>
//#include <list>
//#include <pair>
#include <iostream>
#define N 10000

#define ll long long
using namespace std;
typedef pair<long long ,long long> llp;


ll x[N];
ll cacu(ll x, llp g)
{
    return x*g.first+x*x+g.second;
}


void updata(int ii,vector<llp> &g,llp x)
{
    while (g.size()-ii>1)
    {
        if (g[g.size()-1].second-(g[g.size()-1].first/2)*(g[g.size()-1].first/2) >= x.second-(x.first/2)*-(x.first/2) )
            g.resize(g.size()-1);
        else break;
    }
    g.push_back(x);
}

int main()
{
    int n,c;
    while (scanf("%d %d",&n,&c)!=EOF)
    {
        if (!n&&!c) break;
        long long ans = 0,tmp;
        for (int i=0;i<n;i++) scanf("%d",&x[i]);
        vector<llp> g;

        g.push_back(make_pair(-2*x[0],x[0]*x[0]));
        int ii=0;
        for (int i = 0;;i++)
        {
            ii = 0;
            while (g.size()-ii>1 && (cacu(x[i],g[ii+1])<cacu(x[i],g[ii])))
            {
                ii++;
            }
            ll v = c+cacu(x[i],g[ii]);
            if (i==n-1)
            {
                printf("%I64d\n",v);
                break;
            }
            updata(ii,g,make_pair(-2*x[i+1],v+x[i+1]*x[i+1]));
        }
    }
    return 0;
}
