//CodeForces 1A Theatre Square
//http://codeforces.com/problemset/problem/1/A
/*
 * 题意:
 * a*a的方块铺满n*m的地，问需要多少块
 * 思路:
 * 直接模拟即可
 * author liweijie
 */
#include <iostream>
#include <cstdio>

using namespace std;

int n,m,a;

int main()
{
    while(scanf("%d %d %d",&n,&m,&a)!=EOF)
    {
        int cn = n/a;
        if (n%a!=0) cn++;
        int cm = m/a;
        if (m%a!=0) cm++;
        __int64 ans=cm;
        ans *= cn;
        printf("%I64d\n",ans);
    }
    return 0;
}
