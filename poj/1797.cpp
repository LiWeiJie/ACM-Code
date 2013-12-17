//poj 1797 Heavy Transportation
/*
 * 将spfa的dist初始化为0，dist[源点]= INF, 然后将dist更新条件改为if (  min(edges[nt].d, dist[now]) > dist[edges[nt].y] ) 则更新dist即可
 * author licatweijei
 */

#include<iostream>

using namespace std;

#define INF 1001000
#define MAXE 1010000
#define MAXV 1010
#include <queue>
#include <cstring>

double dist[MAXV];
deque<int> pqu;
bool visited[MAXV];
int cnt[MAXV];
int last[MAXV];

struct edge
{
    int x,y;
    double d;
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

void add_edge(int x,int y,double d)
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
        dist[i] = 0;
    }
    dist[st] = INF;
    visited[st] = true;
    pqu.push_front(st);
    while(!pqu.empty()){
        int now = pqu.front();
        pqu.pop_front();
        visited[now] = false;
        for (int nt = first[now];nt!=0;nt = edges[nt].next){
            if (  min(edges[nt].d, dist[now]) > dist[edges[nt].y] ) {
                dist[edges[nt].y] =  min(edges[nt].d, dist[now]);
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

int main (void)
{
    int n,t,m;
    while(cin >> t ){
        for (int cc=0; cc<t; cc++){
            cin >> n >> m;
            init(n);
            int x,y;
            int d;
            for (int i=0;i<m;i++){
                cin >> x >> y >> d;
                add_edge(x,y,d);
                add_edge(y,x,d);
            }
            spfa(1);
            cout << "Scenario #" << cc+1 << ":" << endl;
            cout << dist[n] << endl << endl;
        }
    }
}
