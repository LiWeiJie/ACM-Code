//Spreading the Wealth
/*
一道很好的数学题，与数据结构无关
把每一个人传递给上一个人的金币设为x[i],负数为逆传递
每人原有金币数位A[i]
ave为每人最终目的金币数
通过分析得知A[i]-x[i]+x[i+1] =  sum/n ;
x[n] = x1 - (A1+A2+...+A[n-1] - (n-1) *ave)
用R[n]表示 上式后面括号部。
R[n] = R[n-1]+A[n-1] - ave
而所求值
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 10000200

using namespace std;

long long A[N];
long long R[N];

int main()
{
    long long n;
    while(scanf("%lld",&n)==1)
    {
        long long sum = 0;
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&A[i]);
            sum+=A[i];
        }
        long long  ave = sum / n;

        //x[i]设为第i个人要给上一个人的金币数，A[i]为原有金币
        //x[1] = x1 - 0
        //x[2] = x1 - (A1-ave)
        //x[3] = x1 - (A1+A2-2*ave)
        //x[n] = x1 - (A1+A2+...+A[n-1] - (n-1) *ave
        //result = sum(x[1],x[2],...,x[n])
        //R[1] = 0;
        //R[2] = A1-ave = R[1] + A[1] - ave;
        //R[3] = A1+A2-2*ave = R[2] + A[2] -ave;
        //...
        //R[n] = R[n-1]+A[n-1] - ave
        R[0] = 0;
        for (int i=1;i<n;i++)
        {
            R[i] = R[i-1] + A[i-1] -ave;
        }
        sort(R,R+n);
        long long x1 = R[n/2];
        long long result = 0;
        for (int i=0;i<n;i++)
        {
            result += abs(x1- R[i]) ;
        }
        printf("%lld\n",result);
    }

    return 0;
}
