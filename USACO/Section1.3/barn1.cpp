/*
    ID:apprent2
    PROG:barn1
    LANG:C++
*/
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

#define N 201

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int m,s,c;
    bool g[N];
    memset(g,0,sizeof(g));
    scanf("%d %d %d",&m,&s,&c);
    int tmp,tmpc;
    tmpc = c;
    while(tmpc--)
    {
        scanf("%d",&tmp);
        g[tmp] = true;
    }
    tmp =0;
    priority_queue<int> pg;
    int st = 1;
    while (!g[st]&&st<s) st++;
    int ed = s;
    while (!g[ed]&&ed>st) ed --;
    for (int i=st;i<=ed;i++)
    {
        if (!g[i])
            tmp++;
        else
        {
            if (tmp!=0 )  pg.push(tmp);
            tmp = 0;
        }
    }
    int ans = 0;
    while (--m && pg.size())
    {
        ans += pg.top();
        pg.pop();
    }
    printf("%d\n",ed-st+1-ans);
    return 0;
}
