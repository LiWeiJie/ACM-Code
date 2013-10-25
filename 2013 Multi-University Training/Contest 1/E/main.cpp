#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define N 100100

int up_same[N],down_same[N],d_up[N],d_down[N];
int s[N];
int n;
vector<int> v;

void solve(int dp[],int same[]){
    v.clear();
    for(int i=0;i<n;i++){
        int a = lower_bound(v.begin(),v.end(),s[i]) - v.begin();
        int b = upper_bound(v.begin(),v.end(),s[i]) - v.begin();
        //s[i]是最大的
        if (b==v.size()){
            v.push_back(s[i]);
            dp[i] = v.size();
        } else {
            v[b] = s[i];
            dp[i] = b+1;
        }
        same[i] = b-a+1;
    }
}


int main()
{
    int T;
    cin >> T;

    while(T--){
        cin >> n ;
        for (int i=n-1;i>=0;i--){
            cin >> s[i];
        }
        solve(d_up,up_same);
        for (int i=0;i<n;i++){
            s[i]*=-1;
        }
        solve(d_down,down_same);
        int ans = 0;
        int tmp;
        for (int i=0;i<n;i++){
            tmp = d_down[i]+d_up[i]-min(down_same[i],up_same[i]);
            if (tmp>ans)
                ans = tmp;
        }
        cout << ans <<endl;
    }
    return 0;
}
