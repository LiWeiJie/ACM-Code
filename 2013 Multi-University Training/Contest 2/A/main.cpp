//Balls Rearrangement
//http://acm.hdu.edu.cn/showproblem.php?pid=4611
//2013多校#2
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define LL __int64

LL gcd(LL a,LL b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

LL solve(LL p,LL a,LL b)
{
    int pos = 0;
    LL ans = 0;
    //特别注意。。。int会越界
    LL ra=0,rb=0;
    while(pos<p){
        int tmp = min(a-ra,b-rb);
        tmp =(tmp+pos<p)?tmp:p-pos;
        ans += tmp*abs(ra-rb);
        ra = (ra+tmp)%a;
        rb = (rb+tmp)%b;
        pos+=tmp;
    }
    return ans;
}

int main()
{
    int T;
    LL n,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d %I64d %I64d",&n,&a,&b);
        if(a<b)
            swap(a,b);
        LL lim = a/gcd(a,b)*b;
        LL ans = 0;
        if (lim<n)
            ans = solve(n%lim,a,b) + n/lim*solve(lim,a,b);
        else
            ans = solve(n,a,b);
        printf("%I64d\n",ans);
    }
    return 0;
}
