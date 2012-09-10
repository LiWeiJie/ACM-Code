/* 2012ChangChunOnline - Alice and Bob
 * 数据结构+贪心
 * 对于alice和bob的，进行排序，第一关键属性为x，第二为y，第三位alice还是bob，如果是bob就放在前面。
 * 最后对整个数组遍历，bob的放进set里面，alice的则寻找set里面可以覆盖的最大一个覆盖掉。
 */


#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define N 100005


struct NT
{
    int x,y,mode;
    bool
    operator<(const NT &b)const
    {
        return (x<b.x||(x == b.x && y<b.y )||(x == b.x && y==b.y&&mode>b.mode ));
    }
};

multiset<int> o;
NT g[N*2];


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<2*n;i++)
        {
            scanf("%d %d",&g[i].x,&g[i].y);
            if (i<n) g[i].mode = 0;
            else g[i].mode = 1;
        }
        sort(g,g+2*n);
        o.clear();
        int ans = 0;
        for (int i=0;i<2*n;i++)
        {
            if (g[i].mode==1)  o.insert(g[i].y);
            else
            {
                if (o.size())
                {
                    if (*(o.begin())<=g[i].y)
                    {
                        set<int>::iterator it = o.upper_bound(g[i].y);
                        it--;
                        ans ++;
                        o.erase(it);
                    }

                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
