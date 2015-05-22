/* 2012ChangChunOnline - Alice and Bob
 * ���ݽṹ+̰��
 * ����alice��bob�ģ��������򣬵�һ�ؼ�����Ϊx���ڶ�Ϊy������λalice����bob�������bob�ͷ���ǰ�档
 * �����������������bob�ķŽ�set���棬alice����Ѱ��set������Ը��ǵ����һ�����ǵ���
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
