//zoj 1372 Networking
/*
建立矩阵时，当新的边的长度比原来短时，才输入费用矩阵。
然后也是Prim建最小生成树
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 101
#define MAX_PRICE 1<<30

int net[MAXN][MAXN];
int minimun[MAXN];
bool used[MAXN];
int n;
int sum;
void init()
{
    int m;
    scanf("%d",&m);
    int x,y,value;
    for (int i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&value);
        if (net[x][y]==0||net[x][y]>value){
            net[x][y] = value;
            net[y][x] = value;
        }
    }
    for (int i=1;i<=n;i++){
        used[i] = false;
        minimun[i] = MAX_PRICE;
    }
}
void prim()
{
    minimun[1] = 0;
    used[1] = true;
    sum = 0;
    int now = 1;
    for (int i=1;i<n;i++){
        int min = MAX_PRICE;
        int next = 0;
        for (int j=1;j<=n;j++){
            if (!used[j]){
                if(net[now][j]!=0&&minimun[j] > net[now][j]){
                    minimun[j] = net[now][j];
                }
                if(min>minimun[j]){
                    min = minimun[j];
                    next = j;
                }
            }
        }
        sum += min;
        now = next;
        used[now] = true;
    }
    printf("%d\n",sum);
}

int main()
{
    while(scanf("%d",&n)!=EOF&&n!=0){
        memset(net,0,sizeof(net));
        init();
        prim();
    }
    return 0;
}
