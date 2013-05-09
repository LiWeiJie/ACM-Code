//zoj 1789 The Suspects
/*
并查集
把所有的联通起来，然后查找0所在的圈子包含的数量就可以了
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define N 30010

int parent[N];
int treeId[N];

inline void init(int i)
{
    treeId[i] = -1;
}



int find(int x)
{
    if (treeId[x]>=0)
    {
        return treeId[x]=find(treeId[x]);
    }
    return x;
}

int main()
{
    int n,m;

    while (scanf("%d %d",&n,&m)==2)
    {
        if (n==0&&m==0) break;
        for (int i=0;i<n;i++)
        {
            init(i);
        }
        while(m--)
        {
            int nm;
            scanf("%d",&nm);
            int father;
            int fatherParent =0;
            if(nm>0)
            {
                scanf("%d",&father);
                nm--;
                fatherParent= find(father);
            }

            while(nm--)
            {
                int tmp;
                scanf("%d",&tmp);
                int tmpParent = find(tmp);
                if(tmpParent!=fatherParent)
                {
                    treeId[fatherParent] += treeId[tmpParent];
                    treeId[tmpParent] = fatherParent;
                }
            }
        }
        printf("%d\n",-treeId[find(0)]);
    }
    return 0;
}
