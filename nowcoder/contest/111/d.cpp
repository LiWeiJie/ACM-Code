#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define ll long long int

const int MAX_N = 201;
const int MAX_M = 1201;

const int MAX_EDGE = MAX_M*MAX_N;
const int MAX_V = MAX_M+MAX_N;

struct node {
    int fr, to, va;
    int nxt;
} edges[MAX_EDGE];

int head[MAX_V];
int cnt;
int deep[MAX_V];

inline static void add_edge(int u, int v, int w) 
{
    edges[cnt].fr = u; edges[cnt].to = v; edges[cnt].va = w;
    edges[cnt].nxt = head[u]; head[u] = cnt++;

    edges[cnt].fr = v; edges[cnt].to = u; edges[cnt].va = 0;
    edges[cnt].nxt = head[v]; head[v] = cnt++;
}

int cost;
int ed;

int promo[MAX_V];

int bfs(int st, int ed) 
{
    memset(deep, 0, sizeof deep);
    deep[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty()) 
    {
        int tmp = q.front();
        q.pop();
        int i;

        // cout << "logging node [" << tmp << "] : "; 

        for (i=head[tmp]; i != -1; i=edges[i].nxt)
        {
            int v = edges[i].to;
            if (edges[i].va>0 && deep[v]==0)
            {
                // cout << "\t" << edges[i].to;
                deep[v] = deep[tmp]+1;
                q.push(v);
            }
        }

        // cout << endl;

    }

    // cout << "found a path to destination: ";
    // for (int i=head[ed]; i != -1; i=edges[i].nxt)
    //     cout << "\t" << i;
    // cout << endl;

    return deep[ed];
}

int dfs(int u, int flow) 
{
    // cout  << u << ":" << flow << ":" << head[u] << endl;
    if (u==ed)
    {
        return flow;
    } else {
        int i;
        int add = 0;
        for (i=head[u]; i != -1 && add<flow; i=edges[i].nxt)
        {
            int v = edges[i].to;
            if (deep[v]!=deep[u]+1) continue;
            int tmp_add = dfs(v, min(flow-add, edges[i].va));
            edges[i].va -= tmp_add;
            edges[ i ^ 1].va += tmp_add;
            add += tmp_add;
        }
        return add;
    }
}

int dinic() 
{
    int ans = 0;
    while(bfs(0,ed)) 
    {
        ans += dfs(0, 0x3ffff);
    }
    return ans;
}

int main() 
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        cost = 0;
        cnt = 0;
        memset(head, -1, sizeof head);

        cin >> n >> m;
        ed = n+m+1;
        int i,j;
        for (i=0; i<n; i++) 
        {
            cin >> j;
            cost += j;
            add_edge(0, i+1, j);
        }
        for (i=0; i<m; i++)
        {
            cin >> promo[i];
            add_edge(n+i+1, ed, promo[i]);
        }
        for (i=0; i<m; i++)
        {
            int k;
            cin >> k;
            for (j=0; j < k; j++) {
                int tmp;
                cin >> tmp;
                add_edge(tmp, n+i+1, promo[i]);
            }
        }
        int flow = dinic();
        cout << cost-flow << endl;
    }
}