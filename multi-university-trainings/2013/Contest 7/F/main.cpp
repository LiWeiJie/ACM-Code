//Backup Plan
//http://acm.hdu.edu.cn/showproblem.php?pid=4671
/*
 * 暴力+STL
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

int s[101][101];

void print(int x,int y)
{
    for (int i=0;i<x;i++){
        printf("%d",s[i][0]);
        for (int j=1;j<y;j++)
            printf(" %d",s[i][j]);
        printf("\n");
    }
}

struct nt
{
    int x,num;
    bool operator<(const nt &rhs)const{
        if (num==rhs.num)
            return x<rhs.x;
        else
            return num<rhs.num;
    }
};

set<nt> st[101];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){

        for (int i=0;i<101;i++)
            st[i].clear();
        for (int i=1;i<=m%n;i++){
            nt tmp;
            tmp.x = i;
            tmp.num = 1+m/n;
            for (int j=1;j<=n;j++){
                if (j!=i)
                    st[j].insert(tmp);
            }

        }
        for (int i=m%n+1;i<=n;i++){
            nt tmp;
            tmp.x = i;
            tmp.num = m/n;
            for (int j=1;j<=n;j++){
                if (j!=i)
                    st[j].insert(tmp);
            }
        }
        s[0][0] = 1;
        for (int i=1;i<m;i++){
            s[i][0] = (s[i-1][0]%n)+1;
        }
        set<nt>::iterator it;

        for (int j=0;j<m;j++){
            it = st[s[j][0]].begin();
            while(it!=st[s[j][0]].end()){
                s[j][1] = it->x;
                nt tmp;
                tmp.x = it->x;
                tmp.num = it->num+1;
                st[s[j][0]].erase(it);
                st[s[j][0]].insert(tmp);
                break;
            }
        }

        bool visit[102];

        for (int i=0;i<m;i++){
            memset(visit,0,sizeof(visit));
            int ct = 2;
            visit[s[i][0]] = true;
            visit[s[i][1]] = true;
            for (int j=1;j<=n;j++){
                if (!visit[j])
                    s[i][ct++] = j;
            }
        }

		print(m,n);
	}
	return 0;
}

