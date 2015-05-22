//hdu 4571 Travel in time
//http://acm.hdu.edu.cn/showproblem.php?pid=4571
/*
 * 题意:
 * 有N个景点，M条路径，有T单位时间，S为入口，E为出口
 * 每个景点有观赏值和消耗时间，路过景点时可选择是否游览，每条路径也有时间耗费。
 * 求在时间允许内，从入口进入，出口退出，最多能获得的观赏值。要求游览的景点观赏值必须递增
 * 思路:
 * 二维动态规划问题。
 * 由于要求观赏值递增，首先按照观赏值对景点进行排序，然后计算每两个点的最短路径
 * d[i][j]表示从到达i点并游览i点耗费j时间获得的最大观赏值。
 * d[i][j] = max {d[i][j], d[k][j-map[i][k]-cost[i]] + value[i] };
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 105
#define TLIMIT 303

using namespace std;

struct node{
    int id;
    int cost;
    int sat;
    bool operator<(const node&rhs)const {
        if (sat==rhs.sat) return id<rhs.id;
        else return sat<rhs.sat;
    }
}nodes[N];


int t,n,m,s,e;

int d[N][TLIMIT];
int map[N][N];
int mark[N];

void init(){
    memset(map,-1,sizeof(map));
    memset(d,-1,sizeof(d));
    cin >> n >> m >> t >> s >> e;
    for (int i=0;i<n;i++){
        cin >> nodes[i].cost;
        nodes[i].id = i;
    }
    for (int i=0;i<n;i++){
        cin >> nodes[i].sat;
    }
    sort(nodes,nodes+n);
    for (int i=0;i<n;i++){
        mark[nodes[i].id] = i;
    }
    s = mark[s];
    e = mark[e];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            map[i][j] = 1000000;
        }
        map[i][i] = 0;
    }
    int x,y,z;

    for (int i=0;i<m;i++){
        cin >>  x >> y >> z;
        x = mark[x];y=mark[y];
//        map[x][y] =z;
//        map[x][y] =z;
        map[x][y] = min(map[x][y],z);
        map[y][x] = min(map[y][x],z);
    }


}

void shortest(){

    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                map[i][j] = min(map[i][k]+map[k][j],map[i][j]);
            }
        }
    }
}

int solve(){

    for (int i=0;i<n;i++){
        for (int j=map[s][i]+nodes[i].cost;j<=t;j++)
            d[i][j] = nodes[i].sat;
    }

    for (int i=0;i<n;i++){
        for (int k=0;k<i;k++){
            if (nodes[k].sat==nodes[i].sat) break;
            for (int j=map[i][k]+nodes[i].cost;j<=t;j++){
                if (d[k][j-map[i][k]-nodes[i].cost ]==-1) continue;
                d[i][j] = max(d[i][j],d[k][j-map[i][k]-nodes[i].cost ] + nodes[i].sat);
            }
        }
    }

    int ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j+map[i][e]<=t;j++){
            ans = max(ans,d[i][j]);
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cc=0;cc<T;cc++){

        init();
        shortest();
        int ans = solve();
        cout << "Case #"<<cc+1<<":"<<endl;
        cout << ans << endl;
    }
	return 0;
}
