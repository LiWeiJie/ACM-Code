#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <limits.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
//#include <vector>
//#define ll long long
//const int INF = 1e9;
//const double exp = 1e-9;

using namespace std;

int ans[10005][10];

int main()
{
    memset( ans , 0 , sizeof(ans));
    int i;
    int k;
    int res;
    for( k = 1 ; k < 10000 ; k++)
    {
        i = k;
        while( i > 0 )
        {
            res = i % 10 ;
            i = i / 10 ;
            ans[k][res]++;
        }
        for( i = 0 ; i < 10 ; i++)
        {
            ans[k][i] = ans[k-1][i] + ans[k][i];
        }
    }
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        int tmp ;
        while(n--)
        {
            scanf("%d", &tmp);
            printf("%d", ans[tmp][0]);
            for( i = 1 ; i < 10 ; i++)
            {
                printf(" %d", ans[tmp][i]);
            }
            printf("\n");
        }
    }
    return 0;
}
