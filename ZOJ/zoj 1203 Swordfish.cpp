//zoj 1203 Swordfish
/*
题意要求令总的代价最小，很明显是最小生成树。
在这里，很明显用Prim算法要比用Kruskal算法更方便
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 108
//计算出来的两城市之间距离最大值
#define MAX_DOUBLE 28285

struct Point
{
	double x,y;
};
//计算两city之间距离
double computerDist(Point A,Point B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

//记录各个点之间的距离
double dists[MAXN][MAXN];
//记录每个端点与0号端点的最小距离
double distzero[MAXN];
Point cites[MAXN];
//记录城市是否在最小生成树中
bool used[MAXN];
int n;
int ct = 0;


void init()
{
    //计算好各city之间的距离
    for (int i=0;i<n;i++){
        scanf("%lf %lf",&cites[i].x,&cites[i].y);
        for (int j=0 ;j<i;j++){
            dists[i][j] = computerDist(cites[i],cites[j]);
            dists[j][i] = dists[i][j];
        }
        used[i] = 0;
        distzero[i] = MAX_DOUBLE;
    }
}
void prim()
{
    distzero[0] = true;
    used[0] = true;
    int now = 0;
    double sum = 0;
    for (int i=0;i<n-1;i++){
        double min = MAX_DOUBLE;
        int next = 0;
        for (int j=0;j<n;j++){
            if (!used[j]){
                if(distzero[j]>dists[now][j]){
                    distzero[j] = dists[now][j];
                }
                if(min>distzero[j]){
                    min = distzero[j];
                    next = j;
                }
            }
        }
        sum += min;
        now = next;
        used[now] = true;
    }
    printf("Case #%d:\n", ct);
    printf("The minimal distance is: ");
    printf("%.2lf\n", sum);
}

int main()
{

	while(scanf("%d",&n)&&n!=0){
		ct++;
		//格式控制
		if (ct!=1) printf("\n");
		init();
        prim();
	}
    return 0;
}

