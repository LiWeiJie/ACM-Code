/*zoj 1091 Knight Moves
 *bfs
 *只需知道马走日字就可以了
 *从初始结点开始bfs直到发现目标点
 *
 */


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;

#define N 9;

struct torun
{
    int x;
    int y;
    int count;
    torun(const torun& rst)
    {
        x = rst.x;
        y = rst.y;
        count = rst.count;
    }
    torun()
    {
        x = 0;
        y = 0;
        count = 0;
    }
    bool check()
    {
        return x>=0&&x<8&&y>=0&&y<8;
    }
};

torun run[8];
queue<torun> bfslist;

int bfs(torun now,torun target)
{
    if (now.x==target.x&&now.y==target.y)
        return now.count;
    for (int i=0;i<9;i++)
    {
        torun bfsbasic;
        bfsbasic.x = now.x+run[i].x;
        bfsbasic.y = now.y+run[i].y;
        bfsbasic.count = now.count+1;
        if (bfsbasic.check())   bfslist.push(bfsbasic);
    }
    if (!bfslist.empty())
    {
        torun bfsbasic(bfslist.front());
        bfslist.pop();
        return bfs(bfsbasic,target);
    }
    else
        return -1;
}

int main()
{
    char col,row;

    run[0].x = 1; run[0].y = -2;
    run[1].x = 1; run[1].y = 2;
    run[2].x = 2; run[2].y = -1;
    run[3].x = 2; run[3].y = 1;
    run[4].x = -1; run[4].y = 2;
    run[5].x = -1; run[5].y = -2;
    run[6].x = -2; run[6].y = 1;
    run[7].x = -2; run[7].y = -1;

    while(scanf("%c%c",&col,&row)!=EOF)
    {
        while(!bfslist.empty())bfslist.pop();
        int c = col-'a' , r = row - '1';
        scanf(" %c%c\n",&col,&row);
        int tc = col-'a' , tr = row - '1';
        torun now,target;
        now.x = c ; now.y = r ; now.count = 0;
        target.x = tc ; target.y = tr; target.count = 0;
        printf("To get from %c%c to %c%c takes %d knight moves.\n",c+'a',r+'1',tc+'a',tr+'1',bfs(now,target));
    }

    return 0;
}
