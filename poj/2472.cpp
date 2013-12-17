//poj 2472 106 miles to Chicago
/*
 *  因为求安全性最大的路径，所以可以将dist[1]定位-1,再作spfa处理
 *  
 *
 * spfa(st) 之后有dist[]得到距离
 */
//licatweijei
#include<iostream>

using namespace std;

#define INF 1000000
#define MAXE 10100
#define MAXV 10100
#include <queue>
#include <cstring>
#include <iomanip>

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
        dist[i] = INF;
    }
    dist[st] = -1;
    visited[st] = true;
    pqu.push_front(st);
    while(!pqu.empty()){
        int now = pqu.front();
        pqu.pop_front();
        visited[now] = false;
        for (int nt = first[now];nt!=0;nt = edges[nt].next){
            if (edges[nt].d * dist[now] < dist[edges[nt].y] ) {
                dist[edges[nt].y] =  edges[nt].d * dist[now];
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
    int n,m;
    while(cin >> n ){
        if (n==0) break;
        cin >> m;
        init(n);
        int x,y;
        double d;
        for (int i=0;i<m;i++){
            cin >> x >> y >> d;
            d/=100;
            add_edge(x,y,d);
            add_edge(y,x,d);
        }
        spfa(1);
        cout << setiosflags(ios::fixed) << setprecision(6) << -dist[n]*100 << " percent" << endl;
    }
}

