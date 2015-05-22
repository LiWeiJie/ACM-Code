//usaco 2.3 nocows
/*
PROG:nocows
ID:apprent2
LANG:C++
Executing...
   Test 1: TEST OK [0.000 secs, 3388 KB]
   Test 2: TEST OK [0.000 secs, 3388 KB]
   Test 3: TEST OK [0.000 secs, 3388 KB]
   Test 4: TEST OK [0.000 secs, 3388 KB]
   Test 5: TEST OK [0.011 secs, 3388 KB]
   Test 6: TEST OK [0.000 secs, 3388 KB]
   Test 7: TEST OK [0.086 secs, 3388 KB]
   Test 8: TEST OK [0.151 secs, 3388 KB]
   Test 9: TEST OK [0.119 secs, 3388 KB]
   Test 10: TEST OK [0.162 secs, 3388 KB]
   Test 11: TEST OK [0.389 secs, 3388 KB]
   Test 12: TEST OK [0.216 secs, 3388 KB]

All tests OK.
*/
#include <iostream>
#include <cstdio>
#include <cstring>

#define N 202

using namespace std;

long long d[202][101];

//结点数为x，小于y层的树的数量。如果用一个二维数组记录，应该可以更快
long long lessD(int x,int y)
{
    long long result = 0;
    for(int i=1;i<y;i++)
        result += d[x][i];
    return result;
}

int main()
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    memset(d,0,sizeof(d));
    d[1][1] = 1;
    for (int i=3;i<=n;i+=2)
    {
        for (int j=1;j<=k;j++)
        {
            for (int z=1;z<i-1;z++)
            {
                //结点为i，层次为j的树有三种构成方式
                //1：左子树结点数为z，层次为j-1，右子树层次小于j-1。d[z][j-1]*(lessD(i-1-z,j-1)
                //2：左子树结点数为z，层次小于j-1，右子树层次为j-1。d[i-1-z][j-1]*(lessD(z,j-1)
                //3：左右子树层次为j-1 。 d[z][j-1]*d[z][j-1]
                // 在这里，把1和3汇总为d[z][j-1]*(lessD(i-1-z,j)
                // 所以d[i][j] = sum(d[z][j-1]*(lessD(i-1-z,j)+d[i-1-z][j-1]*(lessD(z,j-1)) (z=1,2,3...i-2)
                d[i][j] = (d[i][j]+(d[z][j-1]*(lessD(i-1-z,j)%9901)%9901)+(d[i-1-z][j-1]*(lessD(z,j-1)%9901)%9901))%9901;
            }
        }
    }
    printf("%lld\n",d[n][k]);
    return 0;
}
