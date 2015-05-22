//usaco 2.4 ttwo
/*
PROG:ttwo
ID:apprent2
LANG:C++
Executing...
   Test 1: TEST OK [0.000 secs, 3240 KB]
   Test 2: TEST OK [0.000 secs, 3240 KB]
   Test 3: TEST OK [0.000 secs, 3240 KB]
   Test 4: TEST OK [0.000 secs, 3240 KB]
   Test 5: TEST OK [0.000 secs, 3240 KB]
   Test 6: TEST OK [0.000 secs, 3240 KB]
   Test 7: TEST OK [0.000 secs, 3240 KB]
   Test 8: TEST OK [0.000 secs, 3240 KB]
   Test 9: TEST OK [0.000 secs, 3240 KB]

All tests OK.
模拟，用cx，cy和jx，jy记录牛和人的坐标，cd，jd分别记录牛和人的方向。用walk［］［］表示四个方向的操作。用do_walk（）执行。
*/

#include <iostream>
#include <cstdio>

#define walk_time 1000

using namespace std;

char m[10][10];
int jx,jy,cx,cy,cd,jd;

int walk[][2] = {{-1,0},
                {0,+1},
                {+1,0},
                {0,-1},
                };

int ct;

void do_walk(int &wa,int &x,int &y)
{
    int next_x,next_y;
    next_x = x + walk[wa][0];
    next_y = y + walk[wa][1];
    if (next_x>=0&&next_x<10&&next_y>=0&&next_y<10&&m[next_x][next_y]!='*')
    {
        x = next_x;
        y = next_y;
    }else
    {
        wa = (wa+1)%4;
    }
    return;
}

int main()
{
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<9;j++)
        {
            scanf("%c",&m[i][j]);
        }
        scanf("%c\n",&m[i][9]);
    }

    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            if (m[i][j]=='C')
            {
                cx = i;
                cy = j;
            }else if (m[i][j]=='F')
            {
                jx = i;
                jy = j;
            }
        }
    }

    ct = jd = cd = 0;
    while(ct<walk_time)
    {
        if (cx==jx&&cy==jy)
        {
            break;
        }
        do_walk(cd,cx,cy);
        do_walk(jd,jx,jy);
        ct++;
    }

    if (ct==walk_time)
        printf("0\n");
    else
        printf("%d\n",ct);
    return 0;
}
