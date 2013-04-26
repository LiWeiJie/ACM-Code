//cf 298B Sail
/*
模拟题，开始坐标(sx,sy),终点坐标(ex,ey)。
用终点坐标减去现在坐标的绝对值表示距离远近，
若风向导致绝对值变小，则采纳此次行动。否则不予理会。
*/
#include <iostream>
#include <cstdio>


using namespace std;

int t,sx,sy,ex,ey;
int ct;
char s[100020];

inline int dabs(int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{
    while(scanf("%d %d %d %d %d",&t,&sx,&sy,&ex,&ey)!=EOF)
    {
        ct =-1;
        scanf("%s",s);
        int nextx,nexty;
        for (int i = 0;i<t;i++)
        {
            switch (s[i])
            {
                case 'E':
                {
                    nextx = sx +1;
                    nexty = sy;
                    break;
                }
                case 'S':
                {
                    nextx = sx;
                    nexty = sy-1;
                    break;
                }
                case 'W':
                {
                    nextx = sx -1;
                    nexty = sy;
                    break;
                }
                case 'N':
                {
                    nextx = sx;
                    nexty = sy+1;
                    break;
                }
                default:break;
            }
            if (dabs(ex-nextx)<dabs(ex-sx)||dabs(ey-nexty)<dabs(ey-sy))
            {
                sx = nextx;
                sy = nexty;
                if (sx==ex&&sy==ey)
                {
                    ct = i+1;
                    break;
                }
            }
        }
        printf("%d\n",ct);
    }

    return 0;
}
