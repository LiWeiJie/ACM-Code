//hdu 2159 FATE
//http://acm.hdu.edu.cn/showproblem.php?pid=2159
/*
 * 题意:
 * 中文题目不多说了
 * 思路:
 * 二维背包
 * d[i][j][z] 表示计算前i个怪兽，消耗j忍耐度和击杀z只所得到的最大经验值
 * 转移方程为d[j][z] = max{d[j][z], d[ j-endure[i] ][ z-1 ] + exp[i] };   (i=0->n-1 ; j=endure[i]->m ; z=1->s )
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 108
using namespace std;

int endure[N],exp[N];
int d[N][N];
int ans;
int n,m,k,s;

void init()
{
    memset(d,0,sizeof(d));
    ans = m+1;
}

void work()
{

    for (int i=0;i<k;i++){
        //忍耐度
        for (int j=endure[i];j<=m;j++){
            //杀怪数
            for (int z = 1;z<=s;z++){

                if (d[j][z]<d[j-endure[i]][z-1]+exp[i]) {
                    d[j][z] = d[j-endure[i]][z-1]+exp[i];
                    //若使用的忍耐度较少
                    if (d[j][z]>=n && j<ans) ans = j;
                }

            }

        }

    }
}

int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
    while(scanf("%d %d %d %d",&n,&m,&k,&s)!=EOF){
        init();
        for (int i=0;i<k;i++){
            scanf("%d %d",&exp[i],&endure[i]);
        }
        work();
        if (ans==m+1){
            printf("-1\n");
        } else {
            printf("%d\n",m-ans);
        }
    }
	return 0;
}
