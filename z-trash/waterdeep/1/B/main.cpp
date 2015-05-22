#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
    int n=0;
    while (++n)
    {
        int m,mins,maxs;
        cin >> m >> mins >> maxs;
//        scanf("%d %d %d",&m,&mins,&maxs);
        if (m==mins&&mins==maxs&&m==0) break;
        long double  ans =0;
        long long num = 0;
        if (m<=mins)
            ans = 0;
        else
        {
            if (m>=maxs)
            {
                for (int i = mins;i<=maxs;i++)
                {
                    ans += (long long)(maxs - i)*(maxs-i+1) *0.05 + (long long)(2 * m - i -maxs)*(maxs-i+1)*0.1;
                    num +=(maxs-i+1);
                }
                ans = (long double )ans / (long double )num;
            }
            else
            {
                for (int i = mins;i<=m;i++)
                {
                    ans += (long double )(m - i+1)*(m-i)*0.05 + (long double ) (m-i)*(maxs-m)*0.1 +(long double )(m - i)*(m-i+1)*0.1 ;
                    num += maxs-i+1;
                }
                for (int i = m+1 ; i<=maxs;i++)
                    num += maxs-i+1;
                ans = (long double )ans / (long double )num;
            }
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Case " << n << ": " << ans << endl;
//        printf("Case %d: %.2Lf\n",n,ans);
    }

    return 0;
}
