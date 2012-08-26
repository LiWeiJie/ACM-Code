#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
//#include <iostream>
#define N 801
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}


int main()
{
    int n,k;
    int *groupA;
    groupA = new int[N];

    while (scanf("%d %d",&n,&k)!=EOF)
//    while (cin >> n >> k)
    {
//        n =800;
//        k = 11;
        bool mk[N] ;
        int num=0;
        if (n==0&&k==0) break;
        memset(mk,false,sizeof(mk));



//        change = new int[n+1];
        int base = n/k;
        int tmp = n % k ;
        int mul = 1;
        int pos;
        long long ans = 1;
        long long fans = 1;
        for (int i = 1;i<=n;i++)
        {
            if (mul == k+1) mul = 1;

            if (mul>tmp) pos = tmp*(base+1)+(mul-tmp)*base-(i-1)/k;
            else pos = mul*(base+1)-(i-1)/k;


//

            groupA[i] = pos ;

//            if (!mk[pos]&&groupA[pos] == pos)
//            {
//                num++;
//                mk[pos] = true;
//                fans =fans/gcd(fans,ans)*ans;
//            }
            mul++;
        }





        for (int i = 1;i<=n;i++)
        {
            tmp = i;
            ans=0;
            while (!mk[tmp])
            {
                ans++;
                mk[tmp] = true;
                tmp = groupA[tmp];
            }
            if (ans != 0 )
            fans  = fans/gcd(fans,ans)*ans;
        }
//            for (int i=1;i<=n;i++)
//            {
//                if (groupB[i]!=i)
//                {
//                    f = true;
//                    break;
//                }
//            }

        printf("%I64d\n",fans);
//        cout << ans << endl;

    }
    return 0;
}
