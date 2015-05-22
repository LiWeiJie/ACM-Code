//hdu 4607 Park Visit
//http://acm.hdu.edu.cn/showproblem.php?pid=4607
/*
 * 题意:
 * n个节点的公园，有n-1条路相通，路的路径长固定为1，询问m次，问游览p个节点，最少走多远，开始点任意
 * 思路:
 * 首先找出树的直径r，那么可以轻易推出，
 * 对于每个询问q，若q<=r+1，则路长为q-1,若q>r+1,则对于不在直径上的任意一个节点都需要付出两倍的路径长度代价，所以路长为r+（q-r-1）*2
 * 计算树的直径的方法为两次dfs，从任意一个点出发dfs得到最远的点，再从该点dfs得到最远的距离即为其直径长度
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define N 100010
using namespace std;

int n,m;
int degree[N];
vector<int> v[N];
int ret;

void dfs(int p,int fa,int d){
    degree[p] = d;
    for (int i=0;i<v[p].size();i++){
        if (v[p][i]!=fa)
            dfs(v[p][i],p,d+1);
    }
}

void query(){
    while(m--){
        int q;
        cin >> q;
        if (q<=ret+1)
            q--;
        else
            q = ret+(q-ret-1)*2;
        cout << q << endl;
    }
}

void work(){
    ret = 1;
    dfs(ret,0,0);
    for (int i=1;i<=n;i++){
        if (degree[i]>degree[ret]) ret = i;
    }
    dfs(ret,0,0);
    for (int i=1;i<=n;i++){
        if (degree[i]>degree[ret]) ret = i;
    }
    ret = degree[ret];
    query();
}



int main()
{
	std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i=1;i<=n;i++)
            v[i].clear();
        memset(degree,0,sizeof(degree));
        for (int i=0;i<n-1;i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        work();
    }

	return 0;
}
