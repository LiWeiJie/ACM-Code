//usaco 2.4 cowtour
/*
PROG:cowtour
ID:apprent2
LANG:C++
Executing...
   Test 1: TEST OK [0.000 secs, 3432 KB]
   Test 2: TEST OK [0.000 secs, 3432 KB]
   Test 3: TEST OK [0.000 secs, 3432 KB]
   Test 4: TEST OK [0.000 secs, 3432 KB]
   Test 5: TEST OK [0.065 secs, 3432 KB]
   Test 6: TEST OK [0.054 secs, 3432 KB]
   Test 7: TEST OK [0.043 secs, 3432 KB]
   Test 8: TEST OK [0.065 secs, 3432 KB]
   Test 9: TEST OK [0.065 secs, 3432 KB]

All tests OK.
首先通过Floyd-Warshall计算每个节点可达节点的距离.
然后两重循环尝试将两个不可达节点i，j连接起来并计算出新的diameter of new field
最大的diameter of new field即为新形成的field
新形成的field的diameter可能比原有的要小，而题目要求Output that smallest possible diameter.
*/
#include <iostream>
#include <cstdio>
#include <cmath>

#define N 160
#define Z 1E-8
#define INF 9999999

using namespace std;

struct node
{
    int x;
    int y;
};

double dis[N][N];
node pastures[N];
int n;

double q_dis(node &a,node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double diameter(int x)
{
    double maxi = 0;
    for (int i=0;i<n;i++)
    {
        if (i==x) continue;
        if (abs(dis[x][i]-INF)>Z&&dis[x][i]>maxi)
            maxi = dis[x][i];
    }
    return maxi;
}

int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&pastures[i].x,&pastures[i].y);
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            dis[i][j] = INF;
    char sc;
    for (int i=0;i<n;i++)
    {
        getchar();
        for (int j=0;j<n;j++)
        {
            scanf("%c",&sc);
            if (sc=='1')
            {
                dis[i][j] = q_dis(pastures[i],pastures[j]);
                dis[j][i] = dis[i][j];
            }
        }
    }
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                    dis[j][i] = dis[i][j];
                }
            }
        }
    }
    double maxi = INF;
    double tmp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (abs(dis[i][j]-INF)<Z&&i!=j)
            {
                tmp = q_dis(pastures[i],pastures[j])+diameter(i)+diameter(j);
                if (tmp<maxi)
                    maxi = tmp;
            }
        }
    }
    //新形成的filed的diameter可能比原有的要小，而题目要求Output that smallest possible diameter.
    for (int i=0;i<n;i++)
        if (diameter(i)>maxi) maxi=diameter(i);
    printf("%.6lf\n",maxi);
    return 0;
}
