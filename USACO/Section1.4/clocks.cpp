/*
    ID:apprent2
    PROG:clocks
    LANG:C++
*/


/*
 *本来写了一个bfs，每一个状态的扩展状态用结构体储存在优先队列中。
 *但没想到后来的规模实在太大了，是9的指数规模，
 *细细想想，最终结果与顺序无关，且每一次变换最多三次，
 *完全可以用dfs来写
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
#include <strstream>

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

using namespace std;

struct NT
{
    int sta[9];
    string ans;
};



int sta[9] ;
int final[50];
int cacu[9][6] = {
    4,1,2,4,5,0,
    3,1,2,3,0,0,
    4,2,3,5,6,0,
    3,1,4,7,0,0,
    5,2,4,5,6,8,
    3,3,6,9,0,0,
    4,4,5,7,8,0,
    3,7,8,9,0,0,
    4,5,6,8,9,0
    };

bool f = false;
int dfs(NT now,int k)
{
    if (k==9)
    {
        bool tmp = true;
        FOR(j,0,9){
            if (now.sta[j]!=0)
            {
                tmp = false;
                break;
            }
        }
        if (tmp)
        {
            f = true;
        }
        return 0;
    }
    dfs(now,k+1);
    if (f) return 0;
    FOR(i,1,4)
    {

        FOR(j,1,cacu[k][0]+1)
        {
            now.sta[cacu[k][j]-1]++;
            now.sta[cacu[k][j]-1] = now.sta[cacu[k][j]-1]%4;
        }
        final[0]++;
        final[final[0]] = k+1;
        dfs(now,k+1);
        if (f) return 0 ;
    }
    final[0] -=3;
}



int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);


    NT g;

    FOR(i,0,9)
    {
        sf("%d",&g.sta[i]);
        g.sta[i] = g.sta[i]/3%4;
    }
    final[0]=0;
    dfs(g,0);
    int i=1;
    bool isfirst = true;
    while (i<=final[0])
    {
        if (isfirst)
        {
            printf("%d",final[i++]);
            isfirst = false;
        }
        else printf(" %d",final[i++]);
    }
    pf("\n");
    return 0;
}
