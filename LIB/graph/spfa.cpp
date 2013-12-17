//spfa,small label first
/*
 * 每次调用spfa之前先init(V) v是顶点数
 * add_edge()加边
 * spfa(st) 之后有dist[]得到距离
 */
//licatweijei
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

int main (void)
{
    int n,st,ed;
    while(cin >> n >> st >> ed){
        init(n+1);
        for (int i=0;i<n;i++){
            int x,y,nn;
            bool first = true;
            x = i+1;
            cin >> nn;
            while(nn--){
                cin >> y;
                if (first) first = false,add_edge(x,y,0);
                else add_edge(x,y,1);
            }
        }
        spfa(st);
        if (dist[ed]==INF) cout << -1 << endl;
        else   cout << dist[ed] << endl;
    }
}
