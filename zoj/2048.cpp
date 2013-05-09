//zoj 2048 Highways
/*
又是一道最小生成树的题，还是用了Prim算法。
需要特殊处理的就是已经连通的，就把连通的代价设为0，并对代价为0的不进行输出。
这题很快就敲好了，但是一直WA，我查了又查，实在没有找到算法错误，就返回去看题目要求，才发现输出块之间需要空行。改了之后竟然AC了。
我就郁闷了，少空行，多空行这些格式错误不是PE吗。。。。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 1001
#define MAX_PRICE 1<<30


struct PointA
{
    int x,y;
};

struct PointB
{
    int parent;
    double price;
};

double map[MAXN][MAXN];
PointB minimun[MAXN];//parent表示父节点，price表示代价
PointA towns[MAXN];
bool used[MAXN];
int n;
bool is_out;

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&towns[i].x,&towns[i].y);
        used[i] = false;
        minimun[i].price = MAX_PRICE;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
                map[i][j] = sqrt((towns[i].x-towns[j].x)*(towns[i].x-towns[j].x)+(towns[i].y-towns[j].y)*(towns[i].y-towns[j].y));
                map[j][i] = map[i][j];
        }
    }
    int m;
    scanf("%d",&m);
    int x,y;
    //对于已经连通的，距离为0
    for (int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        map[x][y] = 0;
        map[y][x] = 0;
    }
}
void prim()
{
    minimun[1].price = 0;
    used[1] = true;
    int now = 1;
    for (int i=1;i<n;i++){
        double min = MAX_PRICE;
        int next = 0;
        for (int j=1;j<=n;j++){
            if (!used[j]){
                if(minimun[j].price>map[now][j]){
                    minimun[j].price = map[now][j];
                    minimun[j].parent = now;
                }
                if(min>minimun[j].price){
                    min = minimun[j].price;
                    next = j;
                }
            }
        }
        //没有连通的才输出
        if (min!=0){
            is_out = false;
            printf("%d %d\n", next , minimun[next].parent);
        }

        now = next;
        used[now] = true;
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        is_out = true;
        init();
        prim();
        if(t)
            printf("\n");
    }
    return 0;
}
