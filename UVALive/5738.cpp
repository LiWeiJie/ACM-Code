//UVALive 5738 Robot Navigation
/*
bfs加上路数标记
QUES1:忘记在终点位置，路程一样的方位的路径数是可以相加起来的
QUES2:终点位置的路径数累加起来后忘记求余数
QUES3:给初始位置的路径数赋予初值时忘记求余数
AUTHOR:liweijie
08/4/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1010
#define MAX_INT (int)0x7FFFFFFF

using namespace std;

struct node
{
    long long times;
    int dis;
}s[MAXN][MAXN][4];

char plantmap[MAXN][MAXN];

struct coor
{
    int x;
    int y;
    int dir;
//    int dis;
};

int M,N,m;
coor st,ed;

const int walk[][2] = {{-1,0},
                 {0,+1},
                 {+1,0},
                 {0,-1}
                };

void init()
{
    for (int i=0;i<M;i++)
    {
        for (int j=0;j<N;j++)
        {
            for (int z=0;z<4;z++)
            {
                s[i][j][z].dis = MAX_INT;
                s[i][j][z].times = 0;
            }

        }
    }
}

bool check(coor to_check)
{
    if (to_check.x==st.x&&to_check.y==st.y)
        return true;
    if (to_check.x==ed.x&&to_check.y==ed.y)
        return true;
    if (to_check.x>=0&&to_check.x<M&&to_check.y>=0&&to_check.y<N&&plantmap[to_check.x][to_check.y]!='*')
        return true;
    return false;
}

void bfs()
{
    queue<coor> qu;
    while(!qu.empty()) qu.pop();
    coor now,next;
    qu.push(st);
    while(!qu.empty())
    {
        now = qu.front();
        qu.pop();
        if (now.x==ed.x&&now.y==ed.y) break;
        next.x = now.x;
        next.y = now.y;
        int dis = s[now.x][now.y][now.dir].dis+1;
        for (int i=1;i<4;i+=2)
        {
            next.dir = (now.dir+i)%4;
            if (check(next)==true)
            {
                if (dis<s[next.x][next.y][next.dir].dis)
                {
                    s[next.x][next.y][next.dir].dis = dis;
                    s[next.x][next.y][next.dir].times = s[now.x][now.y][now.dir].times;
                    qu.push(next);
                }
                else
                {
                    if (dis==s[next.x][next.y][next.dir].dis)
                    {
                        s[next.x][next.y][next.dir].times = (s[next.x][next.y][next.dir].times+s[now.x][now.y][now.dir].times)%m;
                    }
                }
            }
        }

        next.x = now.x+walk[now.dir][0];
        next.y = now.y+walk[now.dir][1];
        next.dir = now.dir;
        if (check(next)==true)
        {
            if (dis<s[next.x][next.y][next.dir].dis)
            {
                s[next.x][next.y][next.dir].dis = dis;
                s[next.x][next.y][next.dir].times = s[now.x][now.y][now.dir].times;
                qu.push(next);
            }
            else
            {
                if (dis==s[next.x][next.y][next.dir].dis)
                {
                    s[next.x][next.y][next.dir].times = (s[next.x][next.y][next.dir].times+s[now.x][now.y][now.dir].times)%m;
                }
            }
        }
    }
}

int main()
{
    int ct = 0;
    while(scanf("%d %d %d",&M,&N,&m)==3)
    {
        if (m==0) break;
        ct++;
        printf("Case %d: %d ",ct,m);
        for (int i=0;i<M;i++)
        {
            getchar();
            for (int j=0;j<N;j++)
            {
                scanf("%c",&plantmap[i][j]);
            }
        }
        char d;
        scanf("%d %d %d %d %c",&st.x,&st.y,&ed.x,&ed.y,&d);
        switch (d)
        {
            case 'N': st.dir = 0;break;
            case 'E': st.dir = 1;break;
            case 'S': st.dir = 2;break;
            case 'W': st.dir = 3;break;
        }
        init();
        s[st.x][st.y][st.dir].dis = 0;
        s[st.x][st.y][st.dir].times = 1%m;
        bfs();
        int min = 0;
        long long sum = 0;
        for (int i=0;i<4;i++)
        {
            if (s[ed.x][ed.y][i].dis<s[ed.x][ed.y][min].dis)
            {
                min = i;
                sum = s[ed.x][ed.y][i].times;
            }
            else
            {
                if (s[ed.x][ed.y][i].dis==s[ed.x][ed.y][min].dis)
                {
                    sum += s[ed.x][ed.y][i].times;
                    sum %= m;
                }
            }
        }

        if (s[ed.x][ed.y][min].dis!=MAX_INT)
            printf("%lld\n",sum);
        else
            printf("%d\n",-1);

    }
    return 0;
}

