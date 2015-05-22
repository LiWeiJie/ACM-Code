//The Castle
/*

PROG:castle
LANG:C++
ID:apprent2
*/
#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>

#define N 50
using namespace std;

int castle[N][N];
int is_used[N][N];//标记属于哪个房间
int rspace[N*N];//各个房间的大小
int ct=0;//房间数
int max_room=0;//拆墙前最大的房间大小
int broom=0;//拆墙后最大的房间大小
int bx,by;//要拆除的墙的坐标
char position;//方位
int n,m;


void dfs(int x,int y,int flag)
{
    bitset<4> check(castle[x][y]);
    is_used[x][y] = flag;
    rspace[flag]++;
    //西部没有墙
    if (check.test(0)==false){
        if (is_used[x][y-1]==0)
        dfs(x,y-1,flag);
    }
    //北部没有墙
    if (check.test(1)==false){
        if (is_used[x-1][y]==0)
        dfs(x-1,y,flag);
    }
    //东部没有墙
    if (check.test(2)==false){
        if (is_used[x][y+1]==0)
        dfs(x,y+1,flag);
    }
    //南部没有墙
    if (check.test(3)==false){
        if (is_used[x+1][y]==0)
        dfs(x+1,y,flag);
    }

}

void check_max(int x,int y)
{
    bitset<4> check(castle[x][y]);
    //北部有墙
    if (check.test(1)==true){
        if (is_used[x-1][y]!=is_used[x][y])
            if ((rspace[is_used[x-1][y]]+rspace[is_used[x][y]])>broom){
                broom = rspace[is_used[x-1][y]]+rspace[is_used[x][y]];
                bx = x;
                by = y;
                position = 'N';
            }
    }

    //东部有墙
    if (check.test(2)==true){
        if (is_used[x][y+1]!=is_used[x][y])
            if ((rspace[is_used[x][y+1]]+rspace[is_used[x][y]])>broom){
                broom = rspace[is_used[x][y+1]]+rspace[is_used[x][y]];
                bx = x;
                by = y;
                position = 'E';
            }
    }
}

int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    scanf("%d %d",&m,&n);
    memset(is_used,0,sizeof(is_used));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&castle[i][j]);
        }
    }

    //扫描各个房间大小
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (is_used[i][j]==0){
                ct++;
                dfs(i,j,ct);
            }
        }
    }

    for (int j=0;j<m;j++){
        for (int i=n-1;i>=0;i--){
            check_max(i,j);
        }
    }

    for (int i=1;i<=ct;i++)
        if (rspace[i]>max_room)
            max_room = rspace[i];

    printf("%d\n",ct);
    printf("%d\n",max_room);
    printf("%d\n",broom);
    printf("%d %d %c\n",bx+1,by+1,position);

    return 0;
}
