//zoj 1438 Asteroids!
/*
三维bfs题目。
题目长，还不好好看题真的是找死啊。自以为坐标表示与前面的矩阵表示一样是层，行，列。没想到竟然是列、行、层。导致一直WA。
幸好最后发现改回来了，果然AC
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define sf scanf
#define pf printf
using namespace std;

#define N 10


struct node{
    int x;
    int y;
    int z;
    int step;
    node(int xx,int yy,int zz,int sstep = 0):x(xx),y(yy),z(zz),step(sstep){}
    node(){x = 0;y = 0; z = 0; step = 0;}
    node(const node & rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        step = rhs.step;
    }
};


queue<node> bfs_next;
node target;
char s[N][N][N];
int n;
node next[6];
bool is_out;
bool is_used[N][N][N];

void setnode(node &lhs,int x,int y,int z,int step = 0)
{
    lhs.x = x;
    lhs.y = y;
    lhs.z = z;
    lhs.step = step;
}

void setnode(node &lhs,node rhs)
{
    lhs.x = rhs.x;
    lhs.y = rhs.y;
    lhs.z = rhs.z;
    lhs.step = rhs.step;
}

bool checknode(node lhs)
{
    return lhs.x>=0 && lhs.x<n && lhs.y>=0 && lhs.y<n && lhs.z>=0 && lhs.z<n;
}

bool checkuse(node lhs)
{
    return (is_used[lhs.x][lhs.y][lhs.z]);
}



void bfs(node where)
{
    if (!checknode(where) || checkuse(where) || s[where.x][where.y][where.z] == 'X')
    return;
    else
    {
        is_used[where.x][where.y][where.z] = true;
        if (where.x==target.x && where.y == target.y && where.z == target.z)
        {
            is_out = true;
            pf("%d %d\n",n,where.step);
            while(!bfs_next.empty()) bfs_next.pop();
        }
        else
        {
            node tmp;
            tmp.step = where.step+1;
            FOR(i,0,6)
            {
                tmp.x = where.x + next[i].x;
                tmp.y = where.y + next[i].y;
                tmp.z = where.z + next[i].z;
                bfs_next.push(tmp);
            }
        }
    }
    return;
}
int main()
{
    setnode(next[0],0,0,1);
    setnode(next[1],0,0,-1);
    setnode(next[2],0,1,0);
    setnode(next[3],0,-1,0);
    setnode(next[4],1,0,0);
    setnode(next[5],-1,0,0);
    while(sf("START %d\n",&n)!=EOF)
    {
        memset(is_used,false,sizeof(is_used));
        is_out = false;
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                FOR(k,0,n)
                {
                    sf("%c",&s[i][j][k]);
                }
                sf("\n");
            }
        }
        int x,y,z;
        //列行层输入
        scanf("%d %d %d\n",&z,&y,&x);
        node start(x,y,z,0);
        scanf("%d %d %d\n",&z,&y,&x);
        setnode(target,x,y,z);
        bfs_next.push(start);
        while(!bfs_next.empty())
        {
            setnode(start,bfs_next.front());
            bfs_next.pop();
            bfs(start);
        }
        if (!is_out) pf("NO ROUTE\n");
        sf("END\n");
    }
    return 0;
}
