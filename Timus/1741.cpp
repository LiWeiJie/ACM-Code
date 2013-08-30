//ural 1741 Communication Fiend
//http://acm.timus.ru/problem.aspx?space=1&num=1741
/*
 * 题意:
 * 原有Licensed的版本1一份，欲升级到版本n，现有m份升级程序，每一份指定原始版本x，升级后版本y，代价cost和程序类型type
 * Licensed只能作用在Licensed上，Pirated 能作用在任何类型上，但会把升级后的变为Pirated，Cracked 能作用在任何类型上,不改变程序类型
 * 输出Online和最小升级代价或者Offline表示不能升级
 * 思路:
 * DP,先把M个升级程序按照x升序排序，然后逐个应用，d[i][0]表示升级到i的Licensed需要的最小代价，d[i][1]则表示升级到i的Pirated的最小代价
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 10010
#define LOL long long
using namespace std;

LOL d[N][2];
struct up{
    int x,y;
    int cost;
    int type;
    bool operator<(const up& rhs)const {
        return x<rhs.x;
    }
}ups[N];

int n,m;

int get_second(int x,int now){
    if (ups[x].type==2)
        return 1;
    if (ups[x].type==1)
        return now;
    else return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    char ty[10];
    while(cin >> n >> m){
        for (int i=0;i<m;i++){
            cin >> ups[i].x >> ups[i].y >> ups[i].cost >> ty;
            if (ty[0]=='L'){
                ups[i].type = 0;
            }else if (ty[0]=='C'){
                ups[i].type = 1;
            }else ups[i].type = 2;
        }
        sort(ups,ups+m);
        memset(d,0,sizeof(d));
        d[1][0] = 1;
        for (int i =0;i<m;i++){
            if (d[ups[i].x][0]!=0){
                //正版前置存在
                if (d[ups[i].y][get_second(i,0)]==0 || d[ups[i].x][0]+ups[i].cost < d[ups[i].y][get_second(i,0)]){
                    d[ups[i].y][get_second(i,0)] = d[ups[i].x][0]+ups[i].cost;
                }
            }

            if (d[ups[i].x][1]!=0){
                if (ups[i].type==0) continue;
                //前置存在
                if (d[ups[i].y][1]==0 || d[ups[i].x][1]+ups[i].cost < d[ups[i].y][1] )
                    d[ups[i].y][1] = d[ups[i].x][1]+ups[i].cost;
            }
        }
        LOL ans = 0;
        if (d[n][0]!=0)
            ans = d[n][0];
        if (ans==0|| (d[n][1]!=0 && d[n][1]<ans  )){
            ans = d[n][1];
        }
        if (ans!=0){
            cout << "Online" << endl;
            cout << ans-1 << endl;
        } else {
            cout << "Offline" << endl;
        }
    }

	return 0;
}
