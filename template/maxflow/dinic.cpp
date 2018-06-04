/* 
考虑一下我们刚才的EK算法，我们首先BFS出了一个可行的最短路，然后以这个最短路为基准转移的。 
…求豆麻袋。 
为什么我们要增广一次就BFS一次啊，刚才我们在一次BFS中，求出了一条最短路，但是，考虑一棵最短路树，这个最短路只是这棵树一个小小的枝儿。既然如此，何不继续在这个树上搞呢？ 
首先，我们先BFS出从st到ed的路径距离，然后构造一棵最短路树，然后，我们对这棵最短路树进行DFS操作，最后把得到的结果加起来。完成。
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXE 1000003
struct node{
    int fr, to, va;
    int nxt;
}edge[MAXE];
int head[MAXV], n, m, cnt, st, ed;
inline void read(int &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
inline void add_edge(int u, int v, int w) {
    edge[cnt].fr = u, edge[cnt].to = v, edge[cnt].va = w;
    edge[cnt].nxt = head[u], head[u] = cnt++;
    edge[cnt].fr = v, edge[cnt].to = u, edge[cnt].va = 0;
    edge[cnt].nxt = head[v], head[v] = cnt++;
} 
int deep[MAXV];
bool BFS() {
    memset(deep, 0, sizeof deep);
    queue<int> q;
    q.push(st);
    deep[st] = 1;
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        for(int i = head[tmp]; i != -1; i = edge[i].nxt) {
            int v = edge[i].to;
            if( deep[v] || edge[i].va <= 0) continue;
            deep[v] = deep[tmp] + 1;
            q.push(v);
        }
    }
    return deep[ed];
}
int dfs(int u, int flow) { 
    //flow为到达终点最多能增广的值
    if(u == ed) return flow;
    int add = 0; 
    //u点的最大增广量
    for(int i = head[u]; i != -1 && add < flow; i = edge[i].nxt) {
        int v = edge[i].to;
        if(deep[v] != deep[u] + 1) continue;
        if(!edge[i].va) continue;
        int tmpadd = dfs(v, min(edge[i].va, flow - add));
        edge[i].va -= tmpadd;
        edge[i ^ 1].va += tmpadd;
        add += tmpadd;
    }
    return add;
}
int Dinic() {
    int ans = 0; 
    while(BFS()) 
        ans += dfs(st, 0x3fffff);
    return ans;
}
int main() {
    memset(head, -1, sizeof head);
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        read(x), read(y), read(z);
        add_edge(x, y, z);
    }
    cout<<Dinic()<<endl;
    return 0;
}
