#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main()
{
    int t;

    while (scanf("%d",&t)!=EOF)
    {
        double ans = 0;
        int m=1,n=1;
        ans = 1;
        if (t != 1)
        {
            m++;
            n++;
            ans += n*m;
        }
		for (int i=2;i<t;i++)
		{
		    if (m<n) m++;
		    else n++;
		    ans += n*m;
		}
		if (t==0) ans =0;
		printf("%.3lf\n",ans);
    }
    return 0;
}
