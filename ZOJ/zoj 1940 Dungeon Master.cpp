//zoj 1940 Dungeon Master
/*
没什么好说的，bfs搜索
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define N 33

int n;
bool used[N][N][N];
int next_step[]={0,0,1,0,1,0,1,0,0,0,0,-1,0,-1,0,-1,0,0};
char map[N][N][N];
int l,r,c;
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
    bool operator<(const node & rhs)const{
        return step>rhs.step;
    }
};
void setnode(node &lhs,int x,int y,int z,int step = 0)
{
    lhs.x = x;
    lhs.y = y;
    lhs.z = z;
    lhs.step = step;
}

void setnode(node &lhs,node& rhs)
{
    lhs.x = rhs.x;
    lhs.y = rhs.y;
    lhs.z = rhs.z;
    lhs.step = rhs.step;
}

bool checknode(node& lhs)
{
    return lhs.x>=0 && lhs.x<l && lhs.y>=0 && lhs.y<r && lhs.z>=0 && lhs.z<c;
}


bool bfs(node start)
{

    priority_queue<node> que;
    while  (!que.empty()) que.pop();
    que.push(start);
    used[start.x][start.y][start.z] = true;
    while(!que.empty()){
        node next(que.top());
        que.pop();
        next.step = next.step+1;
        for (int i=0;i<18;i+=3){
            next.x += next_step[i];
            next.y += next_step[i+1];
            next.z += next_step[i+2];

            if (checknode(next)){
                if (!used[next.x][next.y][next.z]){
                    used[next.x][next.y][next.z] = true;
                    if (map[next.x][next.y][next.z]!='#'){
                        if (map[next.x][next.y][next.z]=='.'){
                            que.push(next);
                        }else{
                            printf("Escaped in %d minute(s).\n", next.step);
                            return true;
                        }
                    }
                }
            }
            next.x -= next_step[i];
            next.y -= next_step[i+1];
            next.z -= next_step[i+2];
        }
    }
    return false;
}


int main()
{
    while(scanf("%d %d %d",&l,&r,&c)){
        memset(used,0,sizeof(used));
        if (l==r&&l==c&&l==0) break;
        int sx,sy,sz;
        for (int i=0;i<l;i++){
            for (int j=0;j<r;j++){
                for (int k = 0;k<c;k++){
                    while(scanf("%c",&map[i][j][k])&&(map[i][j][k]=='\n'||map[i][j][k]==' '));
                    if (map[i][j][k]=='S') {
                        sx =i;sy =j;sz =k;
                    }
                }
            }
        }
        node start;
        start.x = sx;
        start.y = sy;
        start.z = sz;
        start.step = 0;
        if (!bfs(start))
            printf("Trapped!\n");
    }
    return 0;
}
