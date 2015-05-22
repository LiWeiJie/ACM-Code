//usaco 3.1 agrinet
/*
PROG:agrinet
ID:apprent2
LANG:C++
最小生成树题目
用dis[]记录到达每一个点的最短距离
先随意定一个基点，扫描基点能到达的位置，如果路程比dis[]中记录的更小，且目的地没曾访问，则更新dis[]记录。
扫描完后，在dis[]里面寻找没到达的点中的最近的一点，重复以上操作进行扫描更新。
最后把dis[]里面除了基点外的路程加起来就是ths sum of the minimum length of fiber required to connect the entire set of farms
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 101
#define INF 999999

int dis[N];
int m[N][N];
bool visted[N];
int n;

void init()
{
    memset(visted,0,sizeof(visted));
    for (int i=0;i<=n;i++)
    {
        dis[i] = INF;
    }
}

void spinning_prim(int x)
{
    visted[x] = true;
    int minidis=n;
    for (int k=0;k<n;k++)
    {
        if (visted[k]==0&&m[x][k]<dis[k])
        {
            dis[k] = m[x][k];
        }
    }
    for (int i=0;i<n;i++)
    {
        if (visted[i]==0&&dis[i]<dis[minidis])
        {
            minidis = i;
        }
    }
    if (minidis!=n)
    {
        spinning_prim(minidis);
    }
}

int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    init();
    spinning_prim(0);
    int sum = 0;
    for (int i=1;i<n;i++)
        sum += dis[i];
    printf("%d\n",sum);

    return 0;
}
