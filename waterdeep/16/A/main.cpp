#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int st[6];
    int tmp =k;
    while (tmp)
    {
        tmp--
		scanf("%d",&st[tmp]);
    }
    sort(st,st+k,cmp);


    return 0;
}
