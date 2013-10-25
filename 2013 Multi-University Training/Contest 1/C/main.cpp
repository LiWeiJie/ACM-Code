#include <iostream>
#define LL long long
using namespace std;

#define MOD 1000000007

LL pow(int x){
    if (x==0) return 1;
    if (x==1) return 2;
    int half = x/2;
    LL ans = pow(half);
    ans = ans*ans % MOD;
    if (x%2)
        ans = ans *2 % MOD;
    return ans;
}

int main()
{
    int T;
    cin  >>T ;
    int n,k;
    while(T--){
        cin >> n >>k;
        LL ans = 0;
        if (n<k)
            ans = 0;
        else  if (n==k)
                ans = 1;
        else if (n-1==k)
                ans = 2;
        else {
            ans = (LL)(n-k+3) * pow(n-k-2) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
