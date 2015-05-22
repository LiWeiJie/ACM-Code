//hdu 4602 Partition
//http://acm.hdu.edu.cn/showproblem.php?pid=4602
/*
 * 题意:
 * 给出n，问n的各种组合方式中出现了多少次k
 * 思路:
 * 可以看作有n个点，从中选取连续的k个点，在剩下的点之间位置插入分隔符，就等于把n划分为不同的组合方式
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#define Mod 1000000007
#define LOL long long
using namespace std;


int t,n,k;
LOL ans;

LOL quick_pow (LOL a, LOL b ) {
    LOL r = 1, base = a;
    while( b != 0 ) {
        if( b & 1 ){
            r *= base;
            r %= Mod;
        }
        base *= base;
        base %= Mod;
        b >>= 1;
    }
    return r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> k;
        if (k>n){
            cout << 0 << endl;
        } else {
            if (k==n) {
                cout << 1 << endl;
            } else {

                LOL tmp = n-k-2;
                if (tmp<0){
                    ans = 2;
                } else {
                    tmp = n-k-2;
                    ans = quick_pow(2,tmp);
                    ans *= n-k-1;
                    ans %= Mod;
                    LOL tmp2 = n-k;
                    ans += quick_pow(2,tmp2);
                    ans %= Mod;
//                    ans = quick_pow(2,n-k-2);
//                    ans *= (n-k+3)%Mod;
//                    ans %= Mod;
                }
                cout << ans << endl;
            }
        }
    }
	return 0;
}
