#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

#define N 50000


int ind[N+1];

int main()
{
    int n,m;
    freopen("/home/ymwm/1","r",stdin);
    while (scanf("%d",&n))
    {
        vector<int> v;
        for (int i=1;i<=n;i++)
            v.push_back(i);
        int tmp;
		for (int i=0;i<n;i++)
		{

		    scanf("%d",&tmp);
		    ind[i] = v[tmp-1];
		    v.erase(v.begin()+tmp-1);
		}
		int m;
		scanf("%d",&m);
		scanf("%d",&tmp);
		printf("%d",ind[tmp]);
		for (int i=1;i<m;i++)
		{
		    scanf("%d",&tmp);
		    printf(" %d",ind[tmp]);
		}
		printf("\n");
    }
    return 0;
}
