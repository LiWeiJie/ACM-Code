//poj 2457 Part Acquisition
/*
 * 记录每个星球的买入卖出a,b 就是object a to b 的长度为1 的路径
 * 最后spfa(1) ,输出dist[k]
 * author licatweijei
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define INF 1000000
#define MAXE 1000100
#define MAXV 1001
#include <queue>
#include <cstring>

int dist[MAXV];
int fa[MAXV];
deque<int> pqu;
bool visited[MAXV];
int cnt[MAXV];
int last[MAXV];

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
    memset(last,0,sizeof(last));
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
                last[edges[nt].y] = now;
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

#include <stack>

int main ()
{
    int n,k;
    while(cin >> n >> k){

        init(k);
        int a,b;
        for (int i=1;i<=n;i++){
            cin >> a >> b;
            add_edge(a,b,1);
        }
        spfa(1);
        if (dist[k]==INF)
            cout << -1 << endl;
        else {
            int ans = 0;
            stack<int> path;
            int t = k;
            while(t!=0)
                path.push(t),t = last[t];
            cout << dist[k]+1 << endl;
            while(!path.empty()){
                cout << path.top() << endl;
                path.pop();
            }
        }

    }
}
