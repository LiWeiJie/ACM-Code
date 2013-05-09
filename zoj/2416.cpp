//zoj 2416 Open the Lock
/*
这是一道bfs题目。
解法也不难。
但我一开始是用int存储原始四位数，和目标四位数。导致每次都需要先分解数位再进行变化。
后来改成每一数位单独表示就AC了
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 10
struct  lock
{
    int x[4];
    int step;
    bool operator<(const lock & rhs)const{
        return step>rhs.step;
    }
};



int used[MAXN][MAXN][MAXN][MAXN];

int dis;
int ori;
int ta[4];
priority_queue<lock> que;
inline int jia(int x)
{
    if (x==9) return 1;
    else return x+1;
}
inline int jiang(int x)
{
    if (x==1) return 9;
    else return x-1;
}


void swap(int &a,int &b)
{
    int z;
    z = a;
    a= b;
    b = z;
}

bool bfs(lock now)
{
    if (used[now.x[0]][now.x[1]][now.x[2]][now.x[3]]==-1||used[now.x[0]][now.x[1]][now.x[2]][now.x[3]]>now.step){
        used[now.x[0]][now.x[1]][now.x[2]][now.x[3]]=now.step;
        if (now.x[0]==ta[0]&&now.x[1]==ta[1]&&now.x[3]==ta[3]&&now.x[2]==ta[2])
        {
            return true;
        }

        lock tmp;
        for (int i=0;i<4;i++){
            tmp.x[i] = now.x[i];
        }
        tmp.step = now.step+1;
        for (int i=0;i<4;i++){
            tmp.x[i] = jia(now.x[i]);
            que.push(tmp);
            tmp.x[i] = jiang(now.x[i]);
            que.push(tmp);
            tmp.x[i] = now.x[i];
        }
        swap(tmp.x[0],tmp.x[1]);
        que.push(tmp);
        swap(tmp.x[0],tmp.x[1]);
        swap(tmp.x[2],tmp.x[1]);
        que.push(tmp);
        swap(tmp.x[2],tmp.x[1]);
        swap(tmp.x[2],tmp.x[3]);
        que.push(tmp);
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        for (int i=0;i<MAXN;i++)
            for (int j=0;j<MAXN;j++)
                for (int ii=0;ii<MAXN;ii++)
                    for (int jj=0;jj<MAXN;jj++)
                        used[i][j][ii][jj] = -1;
        scanf("%d",&ori);
        scanf("%d",&dis);
        ta[0] = dis/1000;
        ta[1] = (dis-ta[0]*1000)/100;
        ta[3] = dis%10;
        ta[2] = (dis-ta[3])/10%10;

        while(!que.empty())que.pop();
        lock now;
        now.x[0] = ori/1000;
        now.x[1] = (ori-now.x[0]*1000)/100;
        now.x[3] = ori%10;
        now.x[2] = (ori-now.x[3])/10%10;

        now.step = 0;
        que.push(now);
        while(!que.empty()){
            lock ll = que.top();
            que.pop();
            if (bfs(ll))
                break;
        }
        printf("%d\n",used[ta[0]][ta[1]][ta[2]][ta[3]]);
    }
    return 0;
}
