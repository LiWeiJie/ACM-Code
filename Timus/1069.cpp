//URAL timus 1069 Prufer Code
//http://acm.timus.ru/problem.aspx?space=1&num=1069
/*
题意：
一道prufer 序列的题目
一棵带N个结点的树，给出prufer code ，输出每个结点连接的结点
prufer code 的构造规则为，每次移除序号最小的叶子结点，并输出与其连接的结点序号
题解：
从prufer code可以得出，每个结点的edge数为该结点出现次数+1，那么每一个prufer code，对应删除的就是序号最小的edge为1的结点，把这两个结点关联起来就可以了
由于对序列要求有序，所以使用了set记录
author liweijie
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

#define N 7550

int ans[N];
int ct[N];
int cans = 0;
set<int> s;
set<int>::iterator it;
set<int> slist[N];

int main()
{
    memset(ans,0,sizeof(ans));
    memset(ct,0,sizeof(ans));
    int tmp;
    //输入并计算每个结点的edge数
    while(scanf("%d",&tmp)!=EOF)
    {
        ans[cans++] = tmp;
        ct[tmp]++;
    }
    //如果ct[i]为0，则表示仅与一个节点连接，i为可删节点
    for (int i=1;i<=cans+1;i++)
    {
        if (ct[i]==0) s.insert(i);
    }
    for (int i=0;i<cans;i++)
    {
        it = s.begin();
        int sss = *it;
        slist[ans[i]].insert(*it);
        slist[*it].insert(ans[i]);
        s.erase(*it);
        ct[ans[i]]--;
        if (ct[ans[i]]==0) s.insert(ans[i]);
    }
    for (int i=1;i<=cans+1;i++)
    {
        printf("%d:",i);
        for (it = slist[i].begin();it!=slist[i].end();it++)
        {
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}
