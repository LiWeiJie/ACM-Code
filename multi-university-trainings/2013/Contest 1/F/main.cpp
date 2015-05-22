//hdu 4605 Magic Ball Game
//http://acm.hdu.edu.cn/showproblem.php?pid=4605
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stdio.h>


#define N 100010
using namespace std;

//树状数组
#define typev int // type of res
typev ar[N<<1][2]; // index: 1 ~ N
int lowb(int t) { return t & (-t) ; }
void add(int i, typev v ,int t) {
    for ( ; i < N; ar[i][t] += v, i += lowb(i));
}
typev sum(int i,int t) {
    typev s = 0;
    for ( ; i > 0; s += ar[i][t], i -= lowb(i));
    return s;
}

int rank[N<<1]; //from lower to large
int family[N][2];  //ralation of nodes
int v[N];  //value of node
int ans[N][2];   //for the querys answer
int ct;  //count the lenth of rank
int cend;  //the tail of rank

vector<pair<int,int> >query[N];

//vector<pair<int, int> >query[MAXN];


void dfs(int x)
{
    int len = query[x].size();
    while(len--){
        int ls,ll,rs,rl,l_all,r_all;
        int weight = query[x][len].second;
        //必须+1因为如果后面的ls,rs的-1
        int pos = lower_bound(rank,rank+cend,weight)-rank+1;
        ls = sum(pos-1,0);
        rs = sum(pos-1,1);
        l_all = sum(cend,0);
        r_all = sum(cend,1);
        ll = l_all-sum(pos,0);
        rl = r_all-sum(pos,1);
        int id = query[x][len].first;
        if (ls+rs+ll+rl-l_all-r_all==0){
            ans[id][0] = rs;
            ans[id][1] = ll+rl+3*(ls+rs);
        } else {
            ans[id][0] = -1;
        }
    }

    for (int i=0;i<2;i++){
        int weight = v[x];
        int pos = lower_bound(rank,rank+cend,weight)-rank+1;
        int next = family[x][i];
        if (next!=0){
            add(pos,1,i);
            dfs(next);
            add(pos,-1,i);
        }

    }

}

int main()
{
    int T;
    scanf("%d",&T);
    int n,m,u,a,b,q;
    while(T--){
        ct = 0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            rank[ct++] = v[i];
        }
        memset(family,0,sizeof(family));
        memset(ar,0,sizeof(ar));

        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&u,&a,&b);
            family[u][0] = a;
            family[u][1] = b;
        }
        scanf("%d",&q);
        for (int i=1;i<=n;i++){
            query[i].clear();
        }
        for (int i=1;i<=q;i++){
            scanf("%d%d",&a,&b);
            rank[ct++] = b;
            query[a].push_back(make_pair(i,b));
        }

        sort(rank,rank+ct);
        cend = unique(rank,rank+ct)-rank;

        //应该要计算根节点才决定的
        dfs(1);

        for (int i=1;i<=q;i++){
            if (ans[i][0]==-1)
                puts("0");
            else
                printf("%d %d\n",ans[i][0],ans[i][1]);
        }

    }
    return 0;
}
