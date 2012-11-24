/*
  PROG:sprime
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


int n;

struct INT
{
    int x;
    bool
    operator<(const INT &b)const
    {
        return (x>b.x);
    }
};


priority_queue<INT> ans;




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

int dfs(int x,int k)
{
    if (k==n)
    {
        INT tmp;
        tmp.x = x;
        ans.push(tmp);
        return 0;
    }
    int i;
    if (k==0) i=1;
    else i=0;
    for ( ;i<10;i++)
    {
        if (is_prime(x*10+i))
        {
            dfs(x*10+i,k+1);
        }
    }
    return 0;
}

int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);

    sf("%d",&n);
    dfs(0,0);
    INT tmp ;
    while(ans.size())
    {
        tmp = ans.top();
        ans.pop();
        pf("%d\n",tmp.x);
    }
    return 0;
}
