//zoj 2097 Walking on a Chessboard
/*
很干脆的用dfs敲了
样例果断通过，但提交却返回WA，后来考虑到是否由于没有访问标记设为0，影响了计算过程。
于是把没有访问过的标记为-1.竟然就AC了
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 8
#define NEVER_REACH -1
int next[] = {0,1,0,-1,1,0,-1,0};
int map[10][10][5];
int costs[10][10];
int n;
int sx,sy,ex,ey;


void dfs(int nx,int ny,int sta,int sum)
{
    if (map[nx][ny][sta]==NEVER_REACH||map[nx][ny][sta]>sum){
        map[nx][ny][sta] = sum;
    }else {
        return;
    }
    int ta,tb;
    int cost;
    for (int i=0;i<8;i+=2){
        ta = nx+next[i];
        tb = ny+next[i+1];
        if (ta>0&&tb>0&&ta<9&&tb<9){
            cost = sta*(costs[ta][tb]);
            dfs(ta,tb,(cost%4)+1,sum+cost);
        }
    }
}

int main()
{
    while(scanf("%d %d %d %d",&sx,&sy,&ex,&ey)!=EOF){
        if (sx==0)
            break;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                for (int k=0;k<5;k++)
                    map[i][j][k] = NEVER_REACH;
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                scanf("%d",&costs[i][j]);
            }
        }
        dfs(sx,sy,1,0);
        int min=1<<30;
        for (int i=1;i<=4;i++){
            if (map[ex][ey][i]!=NEVER_REACH&&map[ex][ey][i]<min)
                min = map[ex][ey][i];
        }
        printf("%d\n",min);
    }

    return 0;
}
