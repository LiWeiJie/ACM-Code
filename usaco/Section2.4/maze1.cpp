//usaco 2.4 maze1
/*
PROG:maze1
ID:apprent2
LANG:C++
Executing...
   Test 1: TEST OK [0.000 secs, 3332 KB]
   Test 2: TEST OK [0.000 secs, 3332 KB]
   Test 3: TEST OK [0.000 secs, 3332 KB]
   Test 4: TEST OK [0.000 secs, 3332 KB]
   Test 5: TEST OK [0.011 secs, 3332 KB]
   Test 6: TEST OK [0.011 secs, 3444 KB]
   Test 7: TEST OK [0.000 secs, 3332 KB]
   Test 8: TEST OK [0.000 secs, 3332 KB]
   Test 9: TEST OK [0.000 secs, 3332 KB]
   Test 10: TEST OK [0.086 secs, 3332 KB]

All tests OK.
从两个出口开始dfs搜索，记录到达每一个格子的最小值。
最后输出整个地图步数的最大值
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char m[202][101];
int t[202][101];
int x[2],y[2],ct;
int w,h;

int walk[][2] = {{-1,0},
                {0,+1},
                {+1,0},
                {0,-1},
                };



bool check_do(int x,int y)
{
    if (m[x][y]!='-'&&m[x][y]!='|')
        return true;
    else return false;
}

void do_search(int x,int y)
{
    int next_x,next_y;
    for (int i=0;i<4;i++)
    {
        next_x = x + walk[i][0];
        next_y = y + walk[i][1];
        if (check_do(next_x,next_y))
        {
            next_x += walk[i][0];
            next_y += walk[i][1];
            if (next_x>=0&&
                next_x<=2*h&&
                next_y>=0&&
                next_y<=2*w&&
                (t[next_x][next_y]==0||t[x][y]+1<t[next_x][next_y])
                )
            {
                t[next_x][next_y] = t[x][y]+1;
                do_search(next_x,next_y);
            }
        }
    }
}

int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    scanf("%d %d",&w,&h);
    for (int i=0;i<=2*h;i++)
    {
        getchar();
        for (int j=0;j<=2*w;j++)
        {
            scanf("%c",&m[i][j]);
        }
    }
    ct = 0;
    for (int i=0;i<=2*h;i++)
    {
        if (m[i][0]==' ')
        {
            x[ct] = i;
            y[ct] = 1;
            ct++;
        }
        if (m[i][2*w]==' ')
        {
            x[ct] = i;
            y[ct] = 2*w-1;
            ct++;
        }
    }
    for (int j=0;j<=2*w;j++)
    {
        if (m[0][j]==' ')
        {
            x[ct] = 1;
            y[ct] = j;
            ct++;
        }
        if (m[2*h][j]==' ')
        {
            x[ct] = 2*h-1;
            y[ct] = j;
            ct++;
        }
    }
//    printf("%d %d\n%d %d",x[0],y[0],x[1],y[1]);
    memset(t,0,sizeof(t));
    t[x[0]][y[0]] = 1;
    t[x[1]][y[1]] = 1;
    do_search(x[0],y[0]);
    do_search(x[1],y[1]);
    int maxi = 0;
    for (int i=0;i<=2*h;i++)
    {
        for (int j=0;j<=2*w;j++)
        {
            if (t[i][j]>maxi)
                maxi = t[i][j];
        }
    }
    printf("%d\n",maxi);
    return 0;
}

