//codeforces 96D Volleyball
//http://codeforces.com/problemset/problem/96/D
/*
 * 题意：
 * Petya 搭taxi赶着去看volleyball match
 * 有n个街口，m条路
 * 街口由1--n标识
 * x，y标志开始街口和目的街口
 * 接下来m行，
 * 每行有ui,vi,wi，分别表示ui到vi有wi长
 * 接下来n行
 * ti，ci，表示每一个街道等待的taxi  的最长驾驶距离和收费
 * 如果不能到达y，则输出-1，否则输出最小费用
 * 解法：
 * 首先扩展每个点使用其本身的taxi能到达的点
 * 然后从起点开始bfs，每次选择一个代价最小的点继续扩展，直至发现目的点
 * 由于1000*1000的数据规模会导致mle，所以每次bfs时才扩展对应的点
 * author:licatweijie
 */
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define N 1001

using namespace std;

struct node{
    int id;
    __int64 value;
    bool operator<(const node & rhs)const {
        return value>rhs.value;
    }
};

struct edge{
    int length;
    int st,ed;
    bool operator<(const edge & rhs)const {
        return length<rhs.length;
    }
};

struct road{
    int cost;
    int dest;
};

int visted[N];
//记录是否已经搜查
bool sed[N];
//判断是否有必要搜查
int shortest[N];
//记录原边
vector<edge> edges[N];
vector<edge>::iterator ited;
//记录扩展后路径
vector<road> roads;
vector<road>::iterator itro;

int dl[N],ct[N];
priority_queue<node> pq;
int x,y,n,m;
edge etmp;
node ntmp;
road rtmp;
node new_node;


void spread(int source,int now,int rest){
    vector<edge>::iterator itedtmp;
    itedtmp = edges[now].begin();
    for (;itedtmp!=edges[now].end();itedtmp++){
        if (rest-itedtmp->length>=visted[itedtmp->ed]){
            visted[itedtmp->ed]=rest-itedtmp->length;
            rtmp.cost = ct[source];
            rtmp.dest = itedtmp->ed;
            roads.push_back(rtmp);
            spread(source,itedtmp->ed,rest-itedtmp->length);
        }
    }
}


int main(){

//    freopen("~/in","r",stdin);

    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);


    for (int i=0;i<m;i++){
        scanf("%d %d %d",&etmp.st,&etmp.ed,&etmp.length);
        edges[etmp.st].push_back(etmp);
        swap(etmp.st,etmp.ed);
        edges[etmp.st].push_back(etmp);
    }
    for (int i=1;i<=n;i++){
        scanf("%d %d",&dl[i],&ct[i]);
    }



    while(!pq.empty()){
        pq.pop();
    }
    memset(visted,0,sizeof(int)*(n+1));
    memset(shortest,0,sizeof(int)*(n+1));
    memset(sed,0,sizeof(sed));
    shortest[x] = -1;
    ntmp.value = 0;
    ntmp.id = x;
    pq.push(ntmp);
    bool flag = false;
    //bfs
    while(!pq.empty()){
        ntmp = pq.top();
        pq.pop();
        if (ntmp.id==y){
            printf("%I64d\n",ntmp.value);
            flag = true;
            break;
        }
        if (sed[ntmp.id] == true)  continue;
        sed[ntmp.id] = true;

        //扩展路径

        memset(visted,0,sizeof(int)*(n+1));
        roads.clear();
        visted[ntmp.id] = 2000000000;
        spread(ntmp.id,ntmp.id,dl[ntmp.id]);
        itro = roads.begin();
        for (;itro!=roads.end();itro++){
            new_node.id = itro->dest;
            if (new_node.id==ntmp.id) continue;
            new_node.value = itro->cost+ntmp.value;
            if (shortest[new_node.id]==0||new_node.value<shortest[new_node.id]){
                shortest[new_node.id] = new_node.value;
                pq.push(new_node);
            }
        }

    }
    if (flag==false)
        printf("-1\n");
    return 0;
}
