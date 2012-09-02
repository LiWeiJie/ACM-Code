#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;
int g[101][101];

bool cmp(int a,int b)
{
    return g[a][0]<g[b][0];
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
		int n,m;
		scanf("%d %d",&n,&m);

		int f[101] ;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            g[a][0]++;
            g[b][0]++;
            g[a][g[a][0]] = b;
            g[b][g[b][0]] = a;
        }
        int rank[101];
        for (int i=0;i<101;i++)
            rank[i] = i;
        sort(rank+1,rank+n+1,cmp);
        int tmp=1,name = 1;
        while (!g[rank[tmp]][0])
        {
            rank[tmp] = name;
            if (tmp % 2 ==0) name++;
            tmp++;
        }
        if (tmp!=1 &&tmp % 2 == 1 ) name++;

        for (int i=tmp;i<=n;i++)
        {
            queue<int> mk ;
            int kk;
            mk.push(rank[tmp]);
            if (!f[mk.front()]) name++;
            while (mk.size())
            {
                kk = mk.front();
                mk.pop();
                f[kk] = name-1;
                for (int j=1;j<=g[kk][0];j++)
                {
                    if (!f[g[kk][j]])
                    {
                         f[g[kk][j]] = name-1;
                         mk.push(g[kk][j]);
                    }
                }
            }
        }
        int out[101];
        memset(out,0,sizeof(out));
        name = 1;
        printf("1");
        out[f[1]] = name;
        for (int i=2;i<=n;i++)
        {
            if (out[f[i]]==0)
            {
                name++;
                out[f[i]]=name;
            }
            printf(" %d",out[f[i]]);
        }
        printf("\n");
    }
    return 0;
}
