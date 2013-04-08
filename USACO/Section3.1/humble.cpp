//usaco 3.1 humble
/*
PROG:humble
ID:apprent2
LANG:C++
基本是暴力过的，对于第I位humble numbers，可以用 每个prime寻找在第i个前面的humble numbers里面的最小一个满足 prime * humble number 大于第i-1个humble number 。在所有找到的prime * humble number里面最小的一个就是第i个humble number
有一个优化要注意，每次对应prime寻找humble number，用一个数组记录初始寻找位置为上一次寻找的终端位置
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 100010
#define INF 2<<30

int n,k;

int p[110];
long long d[N];
int ppos[110];


int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    scanf("%d %d",&k,&n);
    for (int i=0;i<k;i++)
    {
        scanf("%d",&p[i]);

    }
    for (int i=0;i<=n;i++)
    {
        d[i] = (long long)INF;
    }
    d[0] = 1;
    memset(ppos,0,sizeof(ppos));
    for (int i=1;i<=n;i++)
    {
        for (int z=0;z<k;z++)
        {
            for (int j=ppos[z];j<i;j++)
            {
                if (d[j]*p[z]>d[i-1])
                {
                    ppos[z] = j;
                    if (d[j]*p[z]<d[i])
                    {
                        d[i] = d[j]*p[z];
                    }
                    break;
                }
            }
        }
    }
    printf("%lld\n",d[n]);
    return 0;
}
