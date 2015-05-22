/*
  PROG:frac1
  LANG:C++
  ID:apprent2
*/
/*
    暴力+gcd

*/

#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 160



using namespace std;

struct NT
{
    int a;
    int b;
    bool
    operator<(const NT &ano) const
    {
        return a*ano.b<ano.a*b;
    }
};


int prime(int a,int b)
{
    if (b==0) return a;
    return (prime(b,a%b));
}

int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);

    NT ans[N*N];
    int ansnum = 0;
    int n;
    scanf("%d",&n);
    if (n!=0)
    {
        ans[0].a = 0;
        ans[0].b = 1;
        ans[1].a = 1;
        ans[1].b = 1;
        ansnum = 2;

        for(int i=1;i<n+1;i++)
        {
            for (int j=1;j<i;j++)
                if (prime(i,j)==1)
                    ans[ansnum].a = j,ans[ansnum].b = i,ansnum++;
        }
        sort(ans,ans+ansnum);
        for (int i=0;i<ansnum;i++)
            printf("%d/%d\n",ans[i].a,ans[i].b);
    }
    return 0;
}
