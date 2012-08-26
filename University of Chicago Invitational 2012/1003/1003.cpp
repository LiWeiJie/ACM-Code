#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
//#include <iostream>
#define N 801

using namespace std;

long long lcm(long long m, long long n)
{
	long long i,t;
	if(m<n)
	 {t=m;m=n;n=t;}
	for(i=m;i>=1;i++)
	 //if(i/m*m==m&&i/n*n==n) 这样是不对的i/m是整除的，比如3/4=1
	 if(i%m==0&&i%n==0)//判断整除是这么判断的
		 break;
	return i;
}



int main()
{
    int n,k;
    int *groupA,*groupB,*change;
    groupA = new int[N];
    groupB = new int[N];

    while (scanf("%d %d",&n,&k)!=EOF)
//    while (cin >> n >> k)
    {
//        n =800;
//        k = 11;
        bool mk[N] ;
        int num=0;
        if (n==0&&k==0) break;
        bool f =true;
        memset(mk,false,sizeof(mk));
        long long ans = 0;
        long long fans = 1;

//        change = new int[n+1];
        for (int i=1;i<=n;i++)
                groupA[i] = i ;
        int base = n/k;
        while (1)
        {
            f = false;
            ans ++;
            int tmp = n % k ;
            int mul = 1;
            int pos;
            for (int i = 1;i<=n;i++)
            {
                if (mul == k+1) mul = 1;
//                if (tmp==0)
//                {
//                    pos =mul*base-(i)/k;
//                }
//                else
//                {
                    if (mul>tmp) pos = tmp*(base+1)+(mul-tmp)*base-(i-1)/k;
                    else pos = mul*(base+1)-(i-1)/k;


//                }

                groupB[pos] = groupA[i] ;

                if (!mk[pos]&&groupB[pos] == pos)
                {
                    num++;
                    mk[pos] = true;
                    fans =lcm(fans,ans);
                }


                mul++;
            }
//            for (int i=1;i<=n;i++)
//            {
//                if (groupB[i]!=i)
//                {
//                    f = true;
//                    break;
//                }
//            }
            if (num==n) break;
            change = groupA;
            groupA = groupB;
            groupB = change;
        }
        printf("%lld\n",ans);
//        cout << ans << endl;

    }
    return 0;
}
