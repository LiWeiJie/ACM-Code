/*
 *map记录进入序号，
 *离去时对比当前可用序号
 *小于则可用加一，否则说明没桌子离去
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

int main()
{
    map<char,int> l;
    int n;
    char cust[8000];
    while (sf("%d",&n))
    {
        l.clear();
        if (n==0) break;
        else
        {
            sf("%s",cust);
        }
        int leave = 0,no = 0;
        int len = strlen(cust);
        for (int i=0;i<len;i++)
        {
            map<char,int>::iterator iter = l.find(cust[i]);
            if (iter!=l.end())
            {
                if (iter->se == 1 )
                {
                    no--;
                }
                else
                {
                    leave++;
                    no--;
                }
                l.erase(iter);
            }
            else
            {
                l.insert(mp(cust[i],no<n?1:0));
                no++;
            }
        }
        if (leave==0)
            pf("All customers tanned successfully.\n");
        else
            pf("%d customer(s) walked away.\n",leave);

    }

    return 0;
}
