/*
  PROG:checker
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

#define N 18

using namespace std;

bool lu[N*2],ru[N*2],row[N],column[N];
int ans[4][N];
int ct;
int n;

int dfs(int r)
{
    if (r==n)
    {
        if (ct<3)
        {
            FOR(i,0,n)
                ans[ct][i] = ans[3][i];
        }
        ct++;
        return 0;
    }
    FOR(i,1,n+1)
    {
        if (column[i]||lu[r+i]||ru[n-i+r+1])
            continue;
        column[i] = true;
        lu[r+i] = true;
        ru[n-i+r+1] = true;
        ans[3][r] = i ;
        dfs(r+1);
        column[i] = false;
        lu[r+i] = false;
        ru[n-i+r+1] = false;
    }
    return 0;
}



int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    memset(lu,0,sizeof(lu));
    memset(ru,0,sizeof(ru));
    memset(row,0,sizeof(row));
    memset(column,0,sizeof(column));
    memset(ans,0,sizeof(ans));
    ct = 0;

    sf("%d",&n);

    dfs(0);
    FOR(i,0,3)
    {
        pf("%d",ans[i][0]);
        FOR(j,1,n) pf(" %d",ans[i][j]);
        pf("\n");
    }
    pf("%d\n",ct);

    return 0;
}
