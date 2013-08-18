//poj 2478 Farey Sequence
//http://poj.org/problem?id=2478
/*
 * 题意:
 * 问Farey Sequence的Fn中有多少个元素
 * 思路:
 * Fi与F(i-1)相比，多了以i为分母，比i小且与i互质为分子的分数。
 * 这种分数的数量也就是，比i小且与i互质的数的数量，也就是欧拉函数phi[i]
 * 既f[i] = f[i-1] + phi[i]
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#define N 1000010
using namespace std;

long long ans[N];
long long phi[N];
int n;

void eular()
{
    int i,j,maxn = 1000001;
    for (i = 1; i <= maxn; i++) phi[i] = i;
    for (i = 2; i <= maxn; i += 2) phi[i] /= 2;
    for (i = 3; i <= maxn; i += 2) if(phi[i] == i) {
    for (j = i; j <= maxn; j += i)
        phi[j] = phi[j] / i * (i - 1);
}

}

int main()
{
    memset(phi,0,sizeof(phi));
    eular();
    ans[1] = 0;
    for (int i=2;i<=1000000;i++){
        ans[i] = ans[i-1]+ phi[i];
//        printf("%d:%d\n",i,ans[i]);
    }
    while(scanf("%d",&n)!=EOF){
        if (n==0)break;
        printf("%lld\n",ans[n]);
    }
	return 0;
}
