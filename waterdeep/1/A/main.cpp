#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int list[101];
int mark[1001];

int main()
{

    int n;
    scanf("%d",&n);
    memset(mark,0,sizeof(mark));
    for (int i=1;i<=n;i++)
        scanf("%d",&list[i]);

    for (int i=1;i<=n;i++)
    {
        for (int j = i+1 ; j<=n ; j++)
        {
            if (list[i]+list[j]<1001)
            mark[list[i]+list[j]] = i;
        }
    }
    int ans = -1 ;
    for (int i=1;i<=n;i++)
    {
        if (mark[list[i]])
        {
            for (int j = mark[list[i]]+1 ; j<=n ; j++)
            {
                if (list[j]==list[i]-list[mark[list[i]]])
                {
                    printf("%d %d %d",i,mark[list[i]],j);
                    ans = 0;
                    break;
                }

            }
            if (ans == 0) break;
        }
    }
    if (ans == -1) printf("-1");
    return 0;
}
