/*
    ID:apprent2
    PROG:milk3
    LANG:C++
*/
/*以a，b桶的牛奶量为参数查重。
 *直接dfs进行六种操作即可
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

#define N 25

bool vis[N][N];

bool ans[N];

int x,y,z;

int min(int a,int b)
{
    return a<b?a:b;
}


int dfs(int a,int b,int c)
{
    if (vis[a][b]) return 0;
    vis[a][b] = true;
    if (a==0) ans[c] = true;
    dfs(a-min(a,y-b),b+min(a,y-b),c);
    dfs(a-min(a,z-c),b,c+min(a,z-c));
    dfs(a+min(b,x-a),b-min(b,x-a),c);
    dfs(a,b-min(b,z-c),c+min(b,z-c));
    dfs(a+min(c,x-a),b,c-min(c,x-a));
    dfs(a,b+min(c,y-b),c-min(c,y-b));
}


using namespace std;

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    sf("%d %d %d",&x,&y,&z);
    dfs(0,0,z);
    int i=0;
    while(!ans[i]) i++;
    pf("%d",i++);
    while(i<N)
    {
        if (ans[i]) pf(" %d",i);
        i++;
    }
    pf("\n");
    return 0;
}
