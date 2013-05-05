//zoj 1586 QS Network
/*
最小生成树题目。
把每一个连接双方的adopters的费用加到代价地图map里面。
然后就是最常规的最小生成树了。
这里是用Prim法
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1001
#define MAX_PRICE 1<<30

int map[MAXN][MAXN];
int minimun[MAXN];
int adapters[MAXN];
bool used[MAXN];
int n;

void init()
{
    for (int i=0;i<n;i++)
        scanf("%d",&adapters[i]);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
            if (i!=j)
                map[i][j] += adapters[i]+adapters[j];
            else
                map[i][j] = 0;
        }
    }
    for (int i=0;i<n;i++){
        used[i] = 0;
        minimun[i] = MAX_PRICE;
    }

}
void prim()
{
    minimun[0] = 0;
    used[0] = true;
    int now = 0;
    int sum = 0;
    for (int i=0;i<n-1;i++){
        int min = MAX_PRICE;
        int next = 0;
        for (int j=0;j<n;j++){
            if (!used[j]){
                if(minimun[j]>map[now][j]){
                    minimun[j] = map[now][j];
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
    printf("%d\n", sum);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        prim();

    }
    return 0;
}
