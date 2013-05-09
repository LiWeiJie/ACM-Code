//scnucpc 2013 final 1004 qzhouayi ’ s annoyance
/*
 * dp动态规划
 * 从1节点开始遍历，因为可以走任意路径不需要付出代价，所以首先d[i] = d[i-1]
 * 然后开始遍历i节点可达的比i小的节点j，如果该路径的权值mm[i][j]+d[j]>d[i]
 * 则更新d[i] = mm[i][j]+d[j]
 * 最后d[n-1]则是所求
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
using namespace std;

#define MAXN 10010

int d[MAXN];
map<int,map<int,int> > mm;

int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
    int n,m;
    int x,y,z;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if (n==0&&m==0)break;
        mm.clear();
        memset(d,0,sizeof(int)*n);
        for (int i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if (x<y) swap(x,y);
            mm[x][y] = z;
        }
        map<int,int >::iterator it;
        for (int i=1;i<n;i++)
        {
            d[i] = d[i-1];
            for (it = mm[i].begin();it!=mm[i].end();++it)
            {
                if (it->second+d[it->first] > d[i])
                {
                    d[i] = d[it->first]+it->second;
                }
            }
        }
        printf("%d\n",d[n-1]);
    }
	return 0;
}
