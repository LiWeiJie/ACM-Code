//poj 1502 MPI Maelstrom
/*
 * 第一个作为源点求spfa，输出最远距离
 * author licatweijei
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define INF 1000000
#define MAXE 10100
#define MAXV 10100
#include <queue>
#include <cstring>

int dist[MAXV];
int fa[MAXV];
deque<int> pqu;
bool visited[MAXV];
int cnt[MAXV];

struct edge
{
    int x,y,d;
    int next;
}edges[MAXE];
int len;
int first[MAXV];
int V; // to be difine

void init(int v)
{
    memset(cnt,0,sizeof(cnt));
    memset(visited,false,sizeof(visited));
    memset(first,0,sizeof(first));
    len = 0;
    V = v;

}

void add_edge(int x,int y,int d)
{
    ++len;
    edges[len].x = x;
    edges[len].y = y;
    edges[len].d = d;
    edges[len].next = first[x];
    first[x] = len;
}

bool spfa(int st)
{
    for (int i=0;i<=V;i++)
    {
        dist[i] = INF;
    }
    dist[st] = 0;
    visited[st] = true;
    pqu.push_front(st);
    while(!pqu.empty()){
        int now = pqu.front();
        pqu.pop_front();
        visited[now] = false;
        for (int nt = first[now];nt!=0;nt = edges[nt].next){
            if (edges[nt].d + dist[now] < dist[edges[nt].y] ) {
                dist[edges[nt].y] =  edges[nt].d + dist[now];
                if (!visited[edges[nt].y]){
                    visited[edges[nt].y] = true;
                    cnt[edges[nt].y]++;
                    if (cnt[edges[nt].y]>V) return false;
                    if (!pqu.empty()){
                        if (dist[edges[nt].y]>dist[pqu.front()])
                            pqu.push_back(edges[nt].y);
                        else
                            pqu.push_front(edges[nt].y);
                    } else pqu.push_front(edges[nt].y);
                }
            }
        }
    }
    return true;
}
char tmp[1000];
int main ()
{
    int n;
    while(cin >> n ){
        init(n);
        for (int i=1;i<=n;i++){
            for (int j=1;j<i;j++){

                cin >> tmp;
                if (tmp[0]=='x') continue;
                int stoi = atoi(tmp) ;
                add_edge(i,j,stoi);
                add_edge(j,i,stoi);
            }
        }
        spfa(1);
        int ans = 0;
        for (int i=1;i<=n;i++){
            if (dist[i] > ans) ans = dist[i];
        }

        cout << ans << endl;
    }
}
