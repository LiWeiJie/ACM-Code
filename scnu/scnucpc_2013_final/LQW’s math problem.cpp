//scnucpc 2013 final 1001 LQW’s math problem
/*
a的大小可以由1-k里面5个倍数的个数来决定
因为唯有5和2的倍数相乘才会出现0，而5为因子的个数远远小于2
b的求法由观测规律得来
据观测，g 的循环周期为 
而b = log2(4*5^(p-1)) +1
所以b = 3+(p-1) * log(5)/log(2);
c:
h(m) = sum (i*(i+1)*(i+2))  (i=1->m) = sum(i^3+3*i^2+2*i) (i=1->m) = sum (i^3) + 3*sum(i^2) + 2*sum(i)
这就可以通过立方和，平方和等公式算出h(m)的值，最后通过mod2013处理就可以得到c的值了
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#define MAXN 11*11*11+8
using namespace std;

//map<long long,long long>  g;
map<long long,map<long long,map<long long,int > > > answer;
long long a,b,c;
int t,n;

const int m_mod = 8052;
//const int m_mod = 2013;
const int f_mod = 11;
int ans[MAXN];

long long ex(long long a,long long b)
{

    long long re = 1;
    while (b--)
    {
        re *= a;
        re %= m_mod;
    }
    return re;
}

long long mul(long long a,long long b)
{

    long long re = 0;
//    b % = m_mod;
    while (b--)
    {
        re += a;
        re %= m_mod;
    }
    return re;
}

int main()
{
//    freopen("in","r",stdin);
////***********************************************
////寻找b的规律
//    long long gt ;
//    long long mod = 1;
//    for (int i=1;i<12;i++)
//    {
//        long long ct = 1;
//        mod *=10;
//        g.clear();
//        gt = 2;
//        while(g[gt]==0)
//        {
//            g[gt] = ct;
//            ct++;
//            gt = gt*2 % mod;
//        }
//        int b = log(ct-g[gt])/log(2)+1;
//        printf("%d : %lld, Binary Length : %d\n", i,ct-g[gt],b);
//    }
////***********************************************
    int k,p,m;
    scanf("%d",&t);
    for (int tcase = 1;tcase<=t;tcase++)
    {
        answer.clear();
        if (tcase!=1) printf("\n");
        printf("Case %d:\n",tcase);
        scanf("%d%d%d%d",&k,&p,&m,&n);
        long long five = 5;
        a = 0;
        while(five<=k)
        {
            a += floor(k/five);
            five*=5;
        }
        b = 3+(p-1) * log(5)/log(2);
        c =((((ex(m,4) + mul(ex(m,3),6))%m_mod +mul(ex(m,2),11))%m_mod+mul(m,6))%m_mod)/4;
        int ct = 4;
        ans[1] = ans[2] = ans[3] = 1;
        while(answer[ans[ct-3]][ans[ct-2]][ans[ct-1]]==0)
        {
            ans[ct] = ((a*ans[ct-1])%f_mod +(b*ans[ct-2])%f_mod)%f_mod + (c*ans[ct-3])%f_mod ;
            ans[ct] %= f_mod;
            answer[ans[ct-3]][ans[ct-2]][ans[ct-1]] = ct++;
        }
        int head = answer[ans[ct-3]][ans[ct-2]][ans[ct-1]];
        if (n>head)
            n = (n-head) % (ct-head) + head;
        printf("%I64d %I64d %I64d %d\n",a,b,c,ans[n]);
//        printf("%lld %lld %lld %d\n",a,b,c,ans[n]);
    }
    return 0;
}

