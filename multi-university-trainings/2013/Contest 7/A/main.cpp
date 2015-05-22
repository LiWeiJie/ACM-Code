//Hyperspace
//http://acm.hdu.edu.cn/showproblem.php?pid=4666
/*
 * 考虑二维空间(x1,y1),(x2,y2)+...(xn,yn)
 * 有 ans = max(|xi-xj|+|yi-yj|) 化为具体式
 * author licatweijie
 * licatweijie@gmail.com
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

///////////////////////////////////////define///////////////////////////////////////////
#define LL long long
////////////////////////////////////////////////////////////////////////////////////////

int s[60010][8];
multiset<int> ms[32];
multiset<int>::iterator it;
int sum[32];

int main()
{
	int q,k,x;
	while(scanf("%d %d",&q,&k)!=EOF){
		int ans=0;
		int od;
		int lim = 1<<k;
		for (int i=0;i<lim;i++)
            ms[i].clear();
		for (int i=1;i<=q;i++){
            scanf("%d",&od);
            if (od){
            //删点
                scanf("%d",&x);
                memset(sum,0,sizeof(sum));
                for (int j=0;j<k;j++){
                    for (int z=0;z<lim;z++){
                        if (z&(1<<j))
                            sum[z] += s[x][j];
                        else
                            sum[z] -= s[x][j];
                    }
                }
                for (int z=0;z<lim;z++){
                    it = ms[z].find(sum[z]);
                    ms[z].erase(it);
                }
            }else {
            //加点
                memset(sum,0,sizeof(sum));
                for (int j=0;j<k;j++){
                    scanf("%d",&s[i][j]);
                    for (int z=0;z<lim;z++){
                        if (z&(1<<j))
                            sum[z] += s[i][j];
                        else
                            sum[z] -= s[i][j];
                    }
                }
                for (int z=0;z<lim;z++){
                    ms[z].insert(sum[z]);
                }
            }
            ans = -200000001;
            int tmp;
            int tmp_b;
            for (int z=0;z<lim;z++){
                it = ms[z].begin();
                tmp = *it;
                it = ms[z].end();
                it--;
                tmp_b = *it;
                if ((tmp_b-tmp)>ans)
                    ans = tmp_b-tmp;
            }
            printf("%d\n",ans);
		}


	}
	return 0;
}

