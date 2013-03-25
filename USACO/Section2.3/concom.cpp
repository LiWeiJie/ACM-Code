//usaco 2.3 concom
/*
PROG:concom
ID:apprent2
LANG:C++
dfs递归搜索
用control[i][j]记录i公司拥有j公司的股权数
递归搜索超过等于50的股权的公司，添加到ct[]里面，同时用dis[]查重
最后搜索超过等于50的输出
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define N 110

using namespace std;

int control[N][N];
int ct[N];

bool dis[N];


void search(int x)
{
    for (int i=0;i<N;i++)
    {
        if (x!=i&&ct[i]>=50)
            printf("%d %d\n",x,i);
    }
}

void dfs(int x)
{
    if (dis[x]==false)
    {
        dis[x] = true;
        for (int i=1;i<N;i++)
        {
            ct[i] += control[x][i];
            if (ct[i]>=50)
                dfs(i);
        }
    }
    return;
}

int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    int n;
    scanf("%d",&n);
    memset(control,0,sizeof(control));

    while(n--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        control[a][b]+=c;
    }
    for (int i=0;i<N;i++)
    {
        memset(ct,0,sizeof(ct));
        memset(dis,0,sizeof(dis));
        dfs(i);
        search(i);
    }
    return 0;
}
