//zoj 2326 Tangled in Cables
/*
map加上最小生成树。
利用map给各个house编号，并用于查找house对应的编号，构造一个费用矩阵。
然后对费用矩阵求最小生成树
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define MAXN 1001
#define MAX_PRICE 1<<30
#define names char




double net[MAXN][MAXN];
double minimun[MAXN];
bool used[MAXN];
int n;
double cable;
double sum;
void init()
{
    scanf("%lf",&cable);
    scanf("%d",&n);
    std::map<string, int> name_map;
    names houseA[255],houseB[255];
    string tmp;
    for (int i=1;i<=n;i++){
        scanf("%s",&houseA);
        tmp = houseA;
        name_map[tmp] = i;
        used[i] = false;
        minimun[i] = MAX_PRICE;
    }
    int m;
    scanf("%d",&m);
    int x,y;
    for (int i=1;i<=m;i++){
        scanf("%s %s",houseA,houseB);
        tmp = houseA;
        x = name_map[tmp];
        tmp = houseB;
        y = name_map[tmp];
        scanf("%lf",&net[x][y]);
        net[y][x] = net[x][y];
    }



}
void prim()
{
    minimun[1] = 0;
    used[1] = true;
    sum = 0;
    int now = 1;
    for (int i=1;i<n;i++){
        double min = MAX_PRICE;
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
    if (sum>cable){
        printf("Not enough cable\n");
    }else {
        printf("Need %.1lf miles of cable\n",sum);
    }

}

int main()
{
    memset(net,0,sizeof(net));
    init();
    prim();
    return 0;
}
