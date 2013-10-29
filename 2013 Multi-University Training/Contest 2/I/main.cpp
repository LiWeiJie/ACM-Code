//http://acm.hdu.edu.cn/showproblem.php?pid=4619
//通过拆点得到两个点，两个集合，每一个dominoes表示相邻的两个点存在关系，二分图最大匹配
#include <iostream>
#include <cstring>
#include <map>
#include <stdio.h>
using namespace std;

#define MAXN 10010


int uN, vN;
// u, v数目,要初始化!!!
bool g[5001][5001];
// g[i][j] 表示xi与yj相连
int xM[MAXN], yM[MAXN]; // 输出量
bool chk[MAXN];
// 辅助量检查某轮y[v]是否被check
bool SearchPath(int u)
{
    int v;
    for(v = 1; v < vN; v++)
        if(g[u][v] && !chk[v])
        {
            chk[v] = true;
            if(yM[v] == -1 || SearchPath(yM[v]))
            {
                yM[v] = u;
                xM[u] = v;
                return true ;
            }
        }
    return false ;
}
int MaxMatch()
{
    int u, ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(u = 1; u < uN; u++)
        if(xM[u] == -1)
        {
            memset(chk, false, sizeof (chk));
            if(SearchPath(u)) ret++;
        }
    return ret;
}


int id[101][101];


int main()
{
    int n,m;
    while(cin >> n >>m)
    {
        if (n==0&&m==0) break;
        int a,b,cta = 1,ctb = 1;
        cta = 1;
        ctb = 1;
        memset(g,0,sizeof(g));
        memset(id,0,sizeof(id));
        for (int i=1; i<=n; i++)
        {
            cin >> a >> b;
            if ((a+b)%2)
            {
                if (!id[a][b])
                    id[a][b] = cta++;
                if (!id[a+1][b])
                    id[a+1][b] = ctb++;
                g[id[a][b]][id[a+1][b]] = true;
            }
            else
            {
                if (!id[a][b])
                    id[a][b] = ctb++;
                if (!id[a+1][b])
                    id[a+1][b] = cta++;
                g[id[a+1][b]][id[a][b]] = true;
            }
        }
        for (int i=1; i<=m; i++)
        {
            cin >> a >> b;
            if ((a+b)%2)
            {
                if (!id[a][b])
                    id[a][b] = cta++;
                if (!id[a][b+1])
                    id[a][b+1] = ctb++;
                g[id[a][b]][id[a][b+1]] = true;
            }
            else
            {
                if (!id[a][b])
                    id[a][b] = ctb++;
                if (!id[a][b+1])
                    id[a][b+1] = cta++;
                g[id[a][b+1]][id[a][b]] = true;
            }
        }
        uN = cta;
        vN = ctb;
        int ans = MaxMatch();
        cout << ans <<endl;
    }
    return 0;
}
