/*
  PROG:pprime
  LANG:C++
  ID:apprent2
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf



using namespace std;



bool is_prime(int x)
{
    if (x==1) return false;
    if (x==2) return true;
    FOR(i,2,sqrt(x)+1)
    {
        if (x % i ==0)
        {
            return false;
        }
    }
    return true;
}

int revero(int x)
{
    int result = 0;
    int y = x;
    while(x)
    {
        result =result*10 + x %10;
        x /= 10;
        y *= 10;
    }
    return result+y;
}
int rever(int x)
{
    int result = 0;
    int y = x;
    x/=10;
    while(x)
    {
        result =result*10 + x %10;
        x /= 10;
        y *= 10;
    }
    return result+y;
}


int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    int a,b;
    sf("%d %d",&a,&b);

    int ans[15000];
    ans[0] = 0;

    ans[2] = 7;


    if (a<=5)
    {
        ans[1] = 5;
        ans[0]++;
        if (a<7&&b>7)
        {
            ans[2] = 7;
            ans[0]++;
        }
    }
    else
    if (a<=7&&b>=7)
    {
        ans[1] = 7;
        ans[0]++;
    }
    int tmp,judge;
    for (int i=1;i<10;i+=2)
    {
        tmp = i;
//        judge =  rever(tmp);
//        if (judge>b) break;
//        if (judge>=a&&judge<=b)
//        {
//            if (is_prime(judge)) ans[++ans[0]] = judge;
//        }
        judge = revero(tmp);
        if (judge>=a&&judge<=b)
        {
            if (is_prime(judge)) ans[++ans[0]] = judge;
        }
        tmp *=10;
        for (int j=0;j<10;j++)
        {
            tmp = tmp+j;
            judge =  rever(tmp);
            if (judge>b)
            {
                tmp -=j;
                break;
            }
            if (judge>=a&&judge<=b)
            {
                if (is_prime(judge)) ans[++ans[0]] = judge;
            }
            judge = revero(tmp);
            if (judge>=a&&judge<=b)
            {
                if (is_prime(judge)) ans[++ans[0]] = judge;
            }
            tmp *=10;
            for (int p=0;p<10;p++)
            {
                tmp += p;

                judge =  rever(tmp);
                if (judge>b)
                {
                    tmp -=p;
                    break;
                }
                if (judge>=a&&judge<=b)
                {
                    if (is_prime(judge)) ans[++ans[0]] = judge;
                }
                judge = revero(tmp);
                if (judge>=a&&judge<=b)
                {
                    if (is_prime(judge)) ans[++ans[0]] = judge;
                }
                tmp *=10;
                for (int q=0;q<10;q++)
                {
                    tmp += q;
                    judge =  rever(tmp);
                    if (judge>b)
                    {
                        tmp -=q;
                        break;
                    }
                    if (judge>=a&&judge<=b)
                    {
                        if (is_prime(judge)) ans[++ans[0]] = judge;
                    }
                    judge = revero(tmp);
                    if (judge>=a&&judge<=b)
                    {
                        if (is_prime(judge)) ans[++ans[0]] = judge;
                    }
                    tmp-=q;
                }
                tmp/=10;
                tmp-=p;
            }
            tmp/=10;
            tmp-=j;
        }
    }
    sort(ans+1,ans+(ans[0]+1));
    for (int i = 1;i<=ans[0];i++)
    {
        pf("%d\n",ans[i]);
    }
    return 0;
}
