/*
其实EK的思路十分简单，就是无数次的BFS直到能够找到我们目标的最大流。 
该方法luogu70，除了三个TLE之外都是0ms。该方法非常容易写，足够应付一些数据比较小的题。 
考虑一下复杂度，据说是O(VE2)，显然不能接受。怎么来的？希腊奶。
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100003
struct node{
    int fr, to, va; //从fr到to有一条权值为v的边
    int nxt;
}edge[MAXN];
int cnt, head[MAXN];
inline void read(int &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
} 
inline void add_edge(int u, int v, int w) { //邻接表存边
    edge[cnt].fr = u, edge[cnt].to = v, edge[cnt].va = w;
    edge[cnt].nxt = head[u], head[u] = cnt++;
    edge[cnt].fr = v, edge[cnt].to = u, edge[cnt].va = 0; 
    edge[cnt].nxt = head[v], head[v] = cnt++; 
} 
int pre[MAXN];
bool vis[MAXN];
int st, ed, n, m;
bool BFS (int S, int T) {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    q.push(S);  vis[S] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].nxt) {
            int tmp = edge[i].to;
            if(edge[i].va <= 0 || vis[tmp]) continue;
            pre[tmp] = i; //记录路径
            vis[tmp] = 1;
            if(tmp == T) return 1;
            q.push(tmp);
        }
    }
    return false;
}
int ans;
int EK() {
    int sub;
    while(BFS(st, ed)) {
        sub = 0x3fffff;
        int i = pre[ed];
        while(i != -1) {
            sub = min(sub, edge[i].va);
            i = pre[edge[i].fr];
        }
        i = pre[ed];
        while(i != -1) {
            edge[i].va -= sub; 
            edge[i ^ 1].va += sub;
            i = pre[edge[i].fr];
            /*
            我们要求剩余权值
            而如果每次将边权减去更新部分之后
            求个最小值 即可得到路径上的最小剩余
            反边就对应的加上这个最小剩余
            由于反边和当前边的编号一定相差1，
            所以可以直接^得到
            */
        }
        ans += sub;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    read(n), read(m), read(st), read(ed);
    int x, y, z;
    memset(head, -1, sizeof head);
    for(int i = 1; i <= m; ++i) {
        read(x), read(y), read(z);
        add_edge(x, y, z);
    }
    cout<<EK()<<endl;
    return 0;
}
