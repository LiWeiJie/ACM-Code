//hdu 4602 partition
//http://acm.hdu.edu.cn/showproblem.php?pid=4602
/*
 *
 可以把数字n看做n个1的集合，那么k就可以看作k个1的集合。
考虑k在不同的地方可以看作是不同的的k，且k在同一个地方时，其他地方的改变也视为不同的k，所以当n>k时可以按照以下两种种情况分类：
1.  k处于序列的最左边和最右边。此时除k外其他地方的情况数为f(n-k)=2^(n-k-1)  ，总的情况为2*2^(n-k-1)  
2.  k处于序列的中间，这种情况数为n-k-1。此时假设k的左边有left个1，则k的左边情况数为f(left)=2^(left-1)  ，则右边有n-k-left个1，情况数为f(n-k-left)=2^(n-k-left-1)  总数为2^(n-k-left-1) * 2^(left-1)  =2^(n-k-2)，再乘以k的数量则是(n-k-1)* 2^(n-k-2)，
把以上两种情况加起来2*2^(n-k-1) +(n-k-1)* 2^(n-k-2) = (n-k+3)* 2^(n-k-2) 。
当n==k时，k最多有一个
当n<k时，k的数量为0
考虑当n>k时中，n-k-1必须为正整数时，情况2才存在，所以当n-k-1==0时特判为2
 */
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
