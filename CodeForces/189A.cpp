//CF 189A Cut Ribbon
/*
STATUS:AC
简单动态规划
d[i]记录满足要求地处理i长度后的最大块数
s[]记录允许的三个切割长度
d[i] = max(d[i-s[j]]]) +1  (j:s[])
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int d[4040];
int s[3],n;

void swap(int &a,int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b =tmp;
}

int main()
{
    while(scanf("%d %d %d %d",&n,&s[0],&s[1],&s[2])==4)
    {
        int tmp;
        if (s[0]>s[1])swap(s[0],s[1]);
        if (s[0]>s[2])swap(s[0],s[2]);
        if (s[1]>s[2])swap(s[2],s[1]);
        memset(d,0,sizeof(d));
        d[0] = 1;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (i-s[j]>=0&&d[i-s[j]]!=0)
                {
                    if (d[i]<d[i-s[j]]+1)
                        d[i] = d[i-s[j]]+1;
                }
            }
        }
        printf("%d\n",d[n]-1);
    }
    return 0;
}
