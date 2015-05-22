#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1000001;
bool a[N];
int p[N];
int maxn;
int pro_ans[N];
int forout[N];
struct ct
{
    int x;
    bool
    operator<(ct b) const
    {
        return x>b.x;
    }
}tmp;





void Prime2() {
    memset(a, 0, N*sizeof(a[0]));
    int num = 0, i, j;
    for(i = 2; i < N; ++i) {
        if(!(a[i])) p[num++] = i;
        for(j = 0; (j<num && i*p[j]<N); ++j) {
            a[i*p[j]] = 1;
            if(!(i%p[j])) break;
        }
    }
}

struct NT
{
    int num;
    int index;
//    long weight;
}list[N];




int mj(int x,int ind)
{
    if (a[x])
    {
        if (pro_ans[x]!=0)
        {
            return pro_ans[x];
        }
        else
        {
            if (forout[x])
            {
                pro_ans[x] = mj(forout[x],ind)+ mj(x / forout[x] ,ind);
                return pro_ans[x];
            }
            else
            {
                for (int i=2 ; i<= x/2 ; i++)
                if ((x % i) == 0 )
                {
                    forout[x] = i;
                    pro_ans[x] = mj(i,ind)+ mj(x / i ,ind);
                    return pro_ans[x];
                }
            }

        }
    }
    else
    {
//        list[ind].weight *=x;
        pro_ans[x] = 1;
        return 1;
    }
}

bool cmp(const NT &a,const NT &b)
{
    return ((a.num<b.num)||(a.num == b.num && a.index< b.index));
}


void out (int x,priority_queue<ct> &ans)
{
    if (!a[x])
    {
        tmp.x = x;
        ans.push(tmp);
    }
    else
    {
        out(forout[x],ans);
        out(x / forout[x],ans);
    }
}


int main()
{
    memset(forout,0,sizeof(forout));
    Prime2();
    for (int i=2;i<=N;i++)
    {
        pro_ans[i] = 0;
//            list[i-a].num = 1;
//            list[i-a].weight = 1;
        pro_ans[i] += mj(i,i);
    }
    int t;
    scanf("%d",&t);
    for (int nm=0;nm<t;nm++)
    {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);

        for (int i=a;i<=b;i++)
        {
            list[i-a].num = pro_ans[i];
            list[i-a].index = i;
//            list[i-a].num = 1;
//            list[i-a].weight = 1;
        }
        priority_queue<ct> ans;
            if (!ans.empty()) ans.pop();
        sort(list,list+b-a+1,cmp);
        printf("Case %d:",nm+1);
        out(list[k-1].index,ans);
        while (ans.size())
        {
            tmp = ans.top();
            ans.pop();
            printf(" %d",tmp.x);
        }
        printf("\n");

    }
}
