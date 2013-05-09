//zoj 1076 Gene Assembly
//贪心
//以结束时间降序排序，能加入队列的加入

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
#define N 1001

using namespace std;

struct NT{
    int st  ;
    int ed  ;
    int no;
    bool
    operator< (const NT & oth) const {
        return ed<oth.ed;
    }
};

int maxer(int a,int b)
{
    return a>b?a:b;
}


int main()
{
    int n;
    NT s[N];
    int dp[N];
    int last[N];
    while(sf("%d",&n))
    {
        int maxone = 0;
        if (n==0) break;
        FOR(i,0,n)
        {
            sf("%d %d",&s[i].st,&s[i].ed);
            s[i].no = i+1;
            last[i] = -1;
            dp[i] = 1;
        }
        sort(s,s+n);
        vector<int> result;
        int p = s[0].ed;
        result.pb(s[0].no);
        int count = 1;
        FOR(i,1,n)
        {
            if (s[i].st>p)
            {
                result.pb(s[i].no);
                p = s[i].ed;
                count++;
            }
        }
//        pf("%d\n",count);
        FOR(i,0,result.size()-1)
        {
            pf("%d ",result[i]);
        }
        pf("%d\n",result[result.size()-1]);
    }
    return 0;
}
