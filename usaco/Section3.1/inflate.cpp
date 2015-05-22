//usaco 3.1 inflate
/*
PROG:inflate
ID:apprent2
LANG:C++
完全背包问题
d[i] 时间为i内的最大价值
from i=0 to n-1
    from j=s[i].time to m
        if (d[j]<d[j-s[i].time]+s[i].score)
            d[j] = d[j-s[i].time]+s[i].score

*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 10010
#define INF 9000000

struct node
{
    int time;
    int score;
};

node s[N];
int m,n;
int d[N];

int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    scanf("%d %d",&m,&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&s[i].score,&s[i].time);
    }
    for (int i=0;i<=m;i++)
    {
        d[i] = 0;
    }
    d[0] = 0;
    for(int i=0;i<n;i++)
    {
        for (int j=(s[i].time);j<=m;j++)
        {
            if (d[j]<d[j-s[i].time]+s[i].score)
                d[j] = d[j-s[i].time]+s[i].score;
        }
    }
    printf("%d\n",d[m]);
    return 0;
}
