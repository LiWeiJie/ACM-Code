/*
	ID: apprent2
	PROG: milk
	LANG: C++
*/


#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct NT
{
    int num;
    int price;
};

bool cmp(NT a,NT b)
{
    return (a.price<b.price);
}

#define N 5001

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);

    int n,m;
    NT g[N];
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d %d",&g[i].price,&g[i].num);
    }
    sort(g,g+m,cmp);
    long ans = 0;
    for (int i=0;i<m;i++)
    {
        if (g[i].num<n)
        {
            ans +=g[i].price * g[i].num ;
            n -= g[i].num ;
        }
        else
        {
            ans += g[i].price * n;
            n  = 0;
        }
        if (n==0) break;
    }
    printf("%ld\n",ans);
    return 0;
}
