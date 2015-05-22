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
    int t,chair,n;
    scanf("%d %d %d",&t,&chair,&n);
    int ans = 0,tmp;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if (tmp<=(t+chair)) ans ++ ;
    }
    printf("%d\n",ans);
    return 0;
}
