// #include<bits/stdc++.h>
#include <iostream>

using namespace std;

int d[100][100];

#define ll long long int
ll ans;
int n,m,k;
const int modn = 420047;

int dfs(int passgner, int pos)
{
    if (passgner==0) {
        ans ++;
        ans = ans %modn;
        return 0;
    }
    for (int i=1; i<=m; i++) 
    {
        for (int j=1;j<=n;j++)
        {
            int next = (i-1)*n+j-1;
            if (next<pos)
                continue;
            if (d[i][j-1]==0 && d[i-1][j]==0)
            {
                d[i][j] = true;
                dfs(passgner-1, next+1);
                d[i][j] = false;
            }
        }
    }
    return 0;
}

int main() 
{
    int T;
    cin >> T;
    while(T--) 
    {
        ans = 0;
        fill(d[0], d[0]+100*100, 0);
        cin >> n >> m >> k;
        dfs(k, 0);
        cout << ans%modn << endl;
    }

}