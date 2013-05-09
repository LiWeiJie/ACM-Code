//scnucpc 2013 final 1002 A simple tree problem
/*
由题意可知，这是一个简单图
用bfs遍历所有点到根节点root1的距离，保存在dis[]里面
对dis排序之后
使用两个指针扫描dis，一个指针从前往后扫，另外一个指针从后面往前扫
若是大于k则计数器加1
最后处理一下后指针大于前指针时，表示剩下的数任意配对都大于K。
累加到计数器里面去
需要注意的是，在运算过程中，dis[]有可能大于10^9.用longlong记录
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#define MAXN 30030
using namespace std;

int n,k;
map<int ,int> m[MAXN];
long long dis[MAXN];

void bfs()
{
    queue<int> qu;
    while(!qu.empty())qu.pop();
    qu.push(1);
    int curr;
    map<int,int>::iterator it;
    while(!qu.empty())
    {
        curr = qu.front();
        qu.pop();
        for (it = m[curr].begin();it!=m[curr].end();it++)
        {
            if(dis[it->first]==0&&it->second!=0)
            {
                dis[it->first] = dis[curr] + it->second;
                qu.push(it->first);
            }
        }
    }
}

int ask_ans()
{
    dis[1] = 0;
    sort(dis+1,dis+1+n);
    int pre = n;
    int num = 0;
    for (int i=1;i<=pre;i++)
    {
        num += n-pre;
        for (int j=pre;j>i;j--)
        {
            if (dis[i]+dis[j]>=k)
            {
                pre--;
                num++;
            }else
            {
                break;
            }
        }
    }
    num += (n-pre)*(n-pre-1)/2;
    return num;
}

int main()
{
//    freopen("in","r",stdin);
    int u,v,l;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            m[i].clear();
            dis[i] = 0;
        }

        for (int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&l);
            m[u][v] = l;
            m[v][u] = l;
        }
        bfs();
        printf("%d\n",ask_ans());
    }
    return 0;
}
