//hdu 1003 Max Sum
/*
http://acm.hdu.edu.cn/showproblem.php?pid=1003
用dp记录累加值
初始化为自己本身
若dp[i-1]>=0,则dp[i] +=dp[i-1]
累加值最大的则为所求的最大子串。
*/
#include <iostream>
#include <cstdio>

#define N 100020

using namespace std;

int dp[N];
int n;
int fa[N];

int main()
{
    int t;
    cin >> t;
    for (int m = 1;m<=t;m++)
    {
        cin >> n;
        for (int i=0;i<n;i++)
        {
            cin >> dp[i];
            fa[i] = i;
        }
        int maxp = 0;
        for (int i=1;i<n;i++)
        {
            if (dp[i-1]>=0)
            {
                dp[i] += dp[i-1];
                fa[i] = fa[i-1];

            }
            if (dp[i]>=dp[maxp]) maxp = i;
        }
        cout << "Case "<<m<<":"<< endl;
        cout << dp[maxp]<<" "<<fa[maxp]+1<<" "<<maxp+1<< endl;
        if (m!=t)cout << endl;
    }

    return 0;
}
