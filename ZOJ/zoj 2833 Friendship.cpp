/*
并查集题目
给出N个人和M个操作
以下M行
M a b 表示a和b结成朋友
Q a  表示查询输出a的朋友数
朋友关系是可传递的
假设一开始每个人为一个圈子
treeId记录的是圈子号，如果是朋友就改为同一个圈子。圈子的祖先标为-x，x表示圈子的人数。负数用以区分其他的寻祖记录。
开始时，每一次find(x)都是由下而上，没有对寻祖过程作优化，结果TLE了，后来优化了寻祖函数，直接记录祖先。320ms
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define N 100005

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
    int index = 0;
    while (scanf("%d %d\n",&n,&m)==2)
    {
        index++;
        if (index==1)   printf("Case %d:\n",index);
        else printf("\nCase %d:\n",index);
        for (int i=0;i<n;i++)
        {
            init(i);
        }
        while(m--)
        {
            char choice;
            scanf("%c",&choice);
            if (choice=='M')
            {
                int a,b;
                scanf("%d %d\n",&a,&b);
                int fa,fb;
                fa = find(a-1);
                fb = find(b-1);
                if(fa != fb)
                {
                    treeId[fa] += treeId[fb];
                    treeId[fb] = fa;
                }
            }
            else
            {
                int x;
                scanf("%d\n",&x);
                x--;
                printf("%d\n",-treeId[find(x)]);
            }
        }
    }
    return 0;
}
