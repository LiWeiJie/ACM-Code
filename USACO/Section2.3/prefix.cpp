//usaco 2.3 prefix
/*
PROG:prefix
ID:apprent2
LANG:C++
由前往后面扫S字符串
dp[i+prim[j].size()-1 ] = dp[i-1] + prim[j].size() (prim[j]与s.substr(i,i+prim[j].size() 匹配))
加上一个限制条件dp[i-1]!=0,则可以保证可以与前缀连接起来
*/
#include <iostream>
#include <cstdio>
#include <cstring>

#define N 202

using namespace std;

string s = "";
string prim[N];
int ps = 0;
int dp[200020];


int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    int maxsub = 0;
    do
    {
        cin >> prim[ps];
        if (prim[ps].size()>maxsub) maxsub = prim[ps].size();
    }while (prim[ps++][0]!='.');
    string tmp;

    while (cin >> tmp)
    {
        s +=tmp;
    }
    memset(dp,0,sizeof(dp));
    for (int j=0;j<ps;j++)
    {
        tmp = s.substr(0,prim[j].size());
        if (tmp==prim[j])
        {
            dp[0+prim[j].size()-1] = prim[j].size();
        }
    }
    for (int i=1;i<s.size();i++)
    {
        for (int j=0;j<ps;j++)
        {
            //如果剩余匹配长度大于基元长度，则无必要比较
            if (prim[j].size()+i>s.size()) continue;
            //如果不是前缀子串，则没必要比较
            if (dp[i-1]==0) continue;
            tmp = s.substr(i,prim[j].size());
            if (tmp==prim[j])
            {
                if (prim[j].size()+dp[i-1] > dp[i+prim[j].size()-1])
                dp[i+prim[j].size()-1] = prim[j].size()+dp[i-1];
            }
        }
    }
    maxsub = 0;
    for (int i=0;i<s.size();i++)
    {
        if (dp[i]>maxsub) maxsub = dp[i];
    }
    cout << maxsub << endl;
    return 0;
}
