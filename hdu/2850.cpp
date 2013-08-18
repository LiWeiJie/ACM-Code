//hdu 2850 Load Balancing
//http://acm.hdu.edu.cn/showproblem.php?pid=2850
/*
 * 题意:
 * 有n个job和m个服务器，每个job有占用时间，给每个job分配服务器，得到各个服务器的使用时间TMi，Minimize (max {TMi} - min {TMj})
 * 思路:
 * 先按照占用时间逆序排序n个job，然后按照贪心分配服务器，每个job分配给当前使用时间最小的服务器
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct nt{
    int server;
    int cost;
    bool operator<(const nt&rhs)const{
        return cost>rhs.cost;
    }
};

priority_queue<nt> pq;
int maxi,n,m;
nt tmp;
nt nodes[100010];
int ctmp;
int ct[100010];
int t;
int ans[100010];


int main()
{
//    freopen("/home/licatweijie/in","r",stdin);
    scanf("%d",&t);
    for (int cc=0;cc<t;cc++){
        while(!pq.empty())
            pq.pop();
        scanf("%d %d",&n,&m);
        for (int i=0;i<m;i++){
            tmp.server = i;
            tmp.cost = 0;
            pq.push(tmp);
        }

        printf("%d\n",n);
        for (int i=0;i<n;i++){
            scanf("%d",&nodes[i].cost);
            nodes[i].server = i;
        }
        sort(nodes,nodes+n);
        for (int i=0;i<n;i++){
            tmp = pq.top();
            pq.pop();
            ans[nodes[i].server] = tmp.server;
            tmp.cost+=nodes[i].cost;
            pq.push(tmp);
        }

        bool first = true;
        for (int i=0;i<n;i++){
            if (first) first = false;
            else printf(" ");
            printf("%d",ans[i]);
        }

        printf("\n");
    }
	return 0;
}
