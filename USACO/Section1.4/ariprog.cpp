/*
    ID:apprent2
    PROG:ariprog
    LANG:C++
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


#define N  125000
#define IT vector<int>::iterator
using namespace std;
bool exist[125002];
vector<int> g;


struct NT
{
    int a;
    int b;
    bool
    operator<(const NT &c) const
    {
        return (b>c.b)||(b==c.b&&a>c.a);
    }
};
priority_queue<NT> ans;


int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    int n,m;
    memset(exist,0,sizeof(exist));
    sf("%d %d",&n,&m);
    FOR(i,0,m+1)
    {
        FOR(j,1,m+1)
        {
            exist[i*i+j*j] = true;
        }
    }
    exist[0] = true;
    FOR(i,0,N+1) if (exist[i]) g.pb(i);

    for (IT i=g.begin() ; i!=g.end() ;i++)
    {
        for(IT j = i+1 ; j!=g.end() ; j++)
        {
            int tmp = n-1 ;
            int base = *j-*i;
            if (base*(n-1)+*i>N) break;
            while (1)
            {

                if (!exist[tmp*base+*i]) break;
                else tmp--;
                if (tmp == 1) break;
            }

            if (tmp == 1 )
            {
                NT an;
                an.a = *i;
                an.b = base ;
                ans.push(an);
            }
        }
    }
    NT tmp;
    if (ans.size())
    {
        while(ans.size())
        {
            tmp = ans.top();
            pf("%d %d\n",tmp.a,tmp.b);
            ans.pop();
        }
    }
    else
    pf("NONE\n");



    return 0;
}
