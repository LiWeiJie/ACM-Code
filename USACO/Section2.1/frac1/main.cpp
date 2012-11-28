/*
  PROG:frac1
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

#define N 160



using namespace std;

struct NT
{
    int a;
    int b;
    bool
    operator<(const NT &ano) const
    {
        return a*ano.b<ano.a*b;
    }
};



int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    bool m[N+1][N+1];

    NT ans[N*N];
    int ansnum = 0;
    int n;
    sf("%d",&n);
    FOR(i,0,n+1)
    {
        FOR(j,0,n+1)
            m[i][j] = true;
    }
    FOR(i,2,n/2+1)
    {
        int tmp = i;
        while(tmp<n)
        {
            m[i][tmp] = false;
            tmp += i;
        }
    }
    m[0][1] = true;
    if (n!=0)
    {
        ans[0].a = 0;
        ans[0].b = 1;
        ans[1].a = 1;
        ans[1].b = 1;
        ansnum = 2;

        FOR(i,1,n+1)
        {
            FOR(j,1,i)
                if (m[j][i]) ans[ansnum].a = j,ans[ansnum].b = i,ansnum++;
        }
        sort(ans,ans+ansnum);
        FOR(i,0,ansnum)
            pf("%d/%d\n",ans[i].a,ans[i].b);
    }
    return 0;
}
