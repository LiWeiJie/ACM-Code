//zoj 1406 Jungle Roads
/*
一看就是最小生成树的题目
我这里用的是Prim方法。每次取与树的连通边值最小的一条。
WA了3、4次，自觉没有地方敲错的。
再重新看一遍，才发现判断连通边值最小的条件写错了。
为图方便，把判断连通边值最小的放到了更新的部分里面
错误地把第55行写成if (!used[j]){
改正只需把maintains[now][j]这个条件放到第56行if(maintains[now][j]&&minimun[j]>maintains[now][j]){就可以了。
0msAC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 30

#define MAX_MAINTENANCE 108



//记录各个点之间的距离
double maintains[MAXN][MAXN];
//记录每个端点与0号端点的最小距离
double minimun[MAXN];
//记录城市是否在最小生成树中
bool used[MAXN];
int n;
int ct = 0;


void init()
{
    //计算好各village之间的距离
    for (int i=0;i<n-1;i++){
        int m,price;
        char village;
        int va;
        while (scanf("%c",&village)&&(village=='\n'||village==' '));
        va = village-'A';
        scanf("%d",&m);
        for (int j=0;j<m;j++){
            while (scanf("%c",&village)&&(village=='\n'||village==' '));
            scanf("%d",&price);
            maintains[va][village-'A'] = price;
            maintains[village-'A'][va] = price;
        }
    }
    for (int i=0;i<n;i++){
        used[i] = 0;
        minimun[i] = MAX_MAINTENANCE;
    }

}
void prim()
{
    minimun[0] = 0;
    used[0] = true;
    int now = 0;
    int sum = 0;
    for (int i=0;i<n-1;i++){
        int min = MAX_MAINTENANCE;
        int next = 0;
        for (int j=0;j<n;j++){
            if (!used[j]){
                if(maintains[now][j]&&minimun[j]>maintains[now][j]){
                    minimun[j] = maintains[now][j];
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

	while(scanf("%d",&n)&&n!=0){
	    memset(maintains,0,sizeof(maintains));
		init();
        prim();
	}
    return 0;
}
