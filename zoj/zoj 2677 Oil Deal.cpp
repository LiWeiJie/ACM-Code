//zoj 2677 Oil Deal
/*
这次的生成树有点意思。
之前的最小生成树我都是用Prim做的，这题如果用Prim建立的矩阵会超出内存限制的，所以就改为用Kruskal算法来建立。
而且这次要建立的是最大生成树。然后对没被取用的边放进升序的优先队列里面
一个个地取出，直到资金不足，
每两组样例之间需要空行
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 51011
#define MAX_PRICE 1<<30

struct Edge
{
    int x,y;
    int price;
    int id;
    bool operator<(const Edge& rhs)const{
        return price<rhs.price;
    }
    bool operator>(const Edge& rhs)const{
        return price>rhs.price;
    }
};

priority_queue<Edge> que;
priority_queue<Edge,vector<Edge>,greater<Edge> > result;
int parent[MAXN];
int op[MAXN*2];
int n;
int m;
int fund;
int sum;
void init()
{
    for (int i=1;i<=n;i++){
        parent[i] = -1;
    }
    Edge edge;
    for (int i=1;i<=m;i++){
        scanf("%d %d",&edge.x,&edge.y);
        scanf("%d",&edge.price);
        edge.id = i;
        que.push(edge);
    }
}

int find(int x)
{
    if (parent[x]!=-1)
        return find(parent[x]);
    else return x;
}

void Kruskal()
{
    while(!que.empty()){
        Edge edge(que.top());
        que.pop();
        int fa,fb;
        fa = find(edge.x);
        fb = find(edge.y);
        if (fa!=fb){
            parent[fb] = fa;
        }
        else
        {
            result.push(edge);
        }
    }
    int sum = 0;
    int ct = 0;
    while(!result.empty()){
        Edge edge(result.top());
        result.pop();

        sum+=edge.price;
        if (sum<=fund){
            op[ct++]=edge.id;
        }
        else
            break;
    }
    printf("%d\n",ct);
    if (ct!=0){
        for (int i=0;i<ct-1;i++)
            printf("%d ",op[i]);
        printf("%d\n",op[ct-1]);
    }
}


int main()
{
    int ct=0;
    while(scanf("%d %d %d",&n,&m,&fund)!=EOF){
        if (ct==0)
            ct++;
        else
            printf("\n");

        while(!que.empty())que.pop();
        while(!result.empty())result.pop();
        init();
        Kruskal();
    }
    return 0;
}
