// #include<bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long int

const int MAX_N = 11;
const int MAX_STATE = 1<<MAX_N;


inline ll pw( int a, int p ) { return p ? a*pw(a,p-1) : 1; }

ll gcd(ll a, ll b)
{
    if (a%b==0)
        return b;
    else 
    {
        return gcd(b, a%b);
    }
}

int main() 
{
    int T;
    cin >> T;
    int lt;
    for (lt=0; lt<T; lt++)
    {
        int n,k;
        cin >> n >> k;
        if (n>k) {
            cout << "1/1" << endl;
            continue;
        }
        int i,j;
        int dp[MAX_N][MAX_STATE] = {0};
        dp[0][0] = 1;
        ll ans = 0;
        for (i=1; i<=n; i++)
        {
            int state;
            for (state=0; state<(1<<k); state++) 
            {
                if (dp[i-1][state] != 0) 
                {
                    for (j=0; j<k; j++) {
                        int x = j;
                        while(x<k && (state & (1<<x))!=0) 
                            x++;
                        if (x<k && (state & (1<<x))==0) 
                        {
                            dp[i][state | (1<<x)] += dp[i-1][state];
                        } else 
                        {
                            ans +=dp[i-1][state] *  pw(k, n-i);
                        }
                    }
                }
            }
        }
        ll t = pw(k,n);
        ll c = gcd(ans, t);
        ans /= c;
        t /= c;
        cout << ans << "/" << t << endl;

    }
}