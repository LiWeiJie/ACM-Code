//usaco 2.3 money
/*
PROG:money
ID:apprent2
LANG:C++
题目给出v个币值，要求计算出用这v个币值组合成n的方案数
通过二重循环实现
for (int i=0;i<v;i++)
    {
        for (int j=0;j<=n-s[i];j++)
        {
            d[j+s[i]] += d[j];
        }
    }
*/

#include <iostream>
#include <cstdio>
#include <cstring>

long long v,n;
long long s[30];
long long d[10010];

using namespace std;

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%lld %lld",&v,&n);
    for (int i=0;i<v;i++)
    {
        scanf("%lld",&s[i]);
    }
    memset(d,0,sizeof(long long)*(n+1));
    d[0] = 1;
    for (int i=0;i<v;i++)
    {
        for (int j=0;j<=n-s[i];j++)
        {
            d[j+s[i]] += d[j];
        }
    }
    printf("%lld\n",d[n]);
    return 0;
}

