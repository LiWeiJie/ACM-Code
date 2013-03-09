//hdu 1242 & zoj 1649
/*
直接bfs。有几个剪枝的地方。
从angel的地方开始搜，一旦搜到朋友就退出
guard的处理，因为遇到guard，step要额外加一，所以用优先队列来记录bfs
10ms AC
最痛苦的是，本来应当1A的，但是因为忘记判EOF，结果一直TLE，我交了9次才AC，第7次发现实在不对劲，怎么算都不可能tle的，于是把过程全部注释掉上交，结果还是tle。最终发现是忘了加EOF判断。浪费了1个小时
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)

#define sf scanf
#define pf printf
using namespace std;

#define N 200


struct node{
    int x;
    int y;
    int step;
    node(int xx,int yy,int sstep = 0):x(xx),y(yy),step(sstep){}
    node(){x = 0;y = 0; step = 0;}
    node(const node & rhs)
    {
        x = rhs.x;
        y = rhs.y;
        step = rhs.step;
    }
    bool
    operator<(const node&rhs)const
    {
        return step>rhs.step;
    }
};


char nodemap[N][N];
bool is_used[N][N];
int f_num;
int mindis;
priority_queue<node> bfs_next;
int n,m;
int f_count;
node next[4];

inline void setnode(node &lhs,node rhs)
{
    lhs.x = rhs.x;
    lhs.y = rhs.y;
    lhs.step = rhs.step;
}
inline void setnode(node &lhs,int x,int y,int step = 0)
{
    lhs.x = x;
    lhs.y = y;
    lhs.step = step;
}

inline bool checknode(node lhs)
{
    return lhs.x>=0 && lhs.x<n && lhs.y>=0 && lhs.y<m ;
}

inline bool checkuse(node lhs)
{
    return (is_used[lhs.x][lhs.y]);
}

inline bool bfs(node pos)
{
    //不再访问已经搜索过的
    if (!checknode(pos)) return false;
    FOR(i,0,4)
    {
        node tmp;
        tmp.x = pos.x+next[i].x;
        tmp.y = pos.y+next[i].y;
        if (nodemap[tmp.x][tmp.y]!='#'&&!checkuse(tmp))
        {
            is_used[tmp.x][tmp.y] = true;
            tmp.step = pos.step+1;
            if (nodemap[tmp.x][tmp.y]=='x') tmp.step++;
            if (nodemap[tmp.x][tmp.y]=='r')
            {
                //一旦搜到朋友就退出输出
                if (tmp.step<mindis) mindis = tmp.step;
                return true;
                f_count--;
            }
            bfs_next.push(tmp);
        }
    }
    return false;
}



int main()
{
    setnode(next[0],0,1);
    setnode(next[1],0,-1);
    setnode(next[2],1,0);
    setnode(next[3],-1,0);
    while(sf("%d %d",&n,&m)!=EOF)
    {
        f_num = 0 ;
        node target;
        while(!bfs_next.empty()) bfs_next.pop();
        memset(is_used,0,sizeof(is_used));
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                sf("%c",&nodemap[i][j]);
                while(nodemap[i][j]=='\n'||nodemap[i][j]==' ')sf("%c",&nodemap[i][j]);

                if (nodemap[i][j]=='r')
                {
                    f_num ++;
                }
                if (nodemap[i][j]=='a')
                {
                    target.x = i;
                    target.y = j;
                    target.step = 0;
                    is_used[i][j] = true ;
                }
            }
        }
        mindis = 1000000;
        f_count = f_num;
        bfs_next.push(target);
        node nextnode;
        //bfs从angel处开始搜
        while(!bfs_next.empty())
        {
            setnode(nextnode,bfs_next.top());
            bfs_next.pop();
            if (bfs(nextnode)) break;
        }
        if (mindis!=1000000)
            pf("%d\n",mindis);
        else pf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
