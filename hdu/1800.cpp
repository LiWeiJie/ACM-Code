//HDU 1800 Flying to the Mars
//http://acm.hdu.edu.cn/showproblem.php?pid=1800
/*
题意：
飞去火星o(╯□╰)o
PPF帝国需要殖民火星，决定用magic broomsticks飞去火星。。。（这什么设定啊）
这需要学习。。。每位士兵有个能力值，能力值高得可以教导能力值低的并乘坐同一magic broomsticks，为了节省资金，需要最少多少把magic broomsticks
题解：
看起来很复杂，但需要注意的只有一种情况，能力值相等时，就不能同坐一把magic broomsticks
所以统计同等能力值的同等度，最大的一个同等度就系所需数
author liweijie
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

map<__int64,int> mp;

string re;
__int64 s;

int n;
int j;
int maxi = 0;
int tmp;


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        maxi = 0;
        mp.clear();
        for (int i=0;i<n;i++)
        {
            scanf("%I64d",&s);
            tmp = ++mp[s];
            if (tmp>maxi) maxi = tmp;
        }
        printf("%d\n",maxi);
    }
    return 0;
}
