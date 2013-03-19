//codeforces 246/D Colorful Graph
/*
由于颜色和结点的范围都为1--10E5
不能直接开邻接矩阵来记录结点与结点之间的关系
所以通过map来记录结点和结点的关系。
在每一个结点里面用map记录和其他结点的连接关系
而颜色集里面也用一个map来记录是否已经和其他颜色相邻
*/
#include <iostream>
#include <cstdio>
#include <map>
#define N 100020

using namespace std;

struct point
{
    map<int,int>v;
    int num;
    int color;
    point(){num=0;v.clear();}
}cal[N];

int main()
{
    int n,m;
    int temp;
    scanf("%d %d",&n,&m);
    map<int,point > v;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        cal[i].color = temp;
        cal[i].num = 0;
    }
    int one, two;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&one,&two);
        if (cal[one].color == cal[two].color) continue;
        if (v[cal[one].color].v[cal[two].color]!=1)
        {
            v[cal[one].color].v[cal[two].color]=1;
            v[cal[one].color].num++;
        }
        if (v[cal[two].color].v[cal[one].color]!=1)
        {
            v[cal[two].color].v[cal[one].color]=1;
            v[cal[two].color].num++;
        }
    }
    int maxi = -1,maxp = 0;
    for (int i=1;i<=n;i++)
    {
        if (v[cal[i].color].num>maxi)
        {
            maxi = v[cal[i].color].num;
            maxp = cal[i].color;
        } else if (v[cal[i].color].num==maxi && cal[i].color<maxp)
        {
            maxp = cal[i].color;
        }
    }
    printf("%d\n",maxp);
    return 0;
}
