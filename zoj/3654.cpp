//zoj 3654 Letty's Math Class
/*
 *status:ac 
 *ZOJ Monthly, September 2012
 *简单地模拟即可
 *首先判断a，b两个分支是否存在9，若是存在则直接输出答案
 *否则就计算出expression的值式，再与a，b相匹配
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;

char exp[1010];
LL a,b;

LL calcu(int d,LL pa,LL pb)
{
    if (d==0)
        return pa+pb;
    else
        return pa-pb;
}

int main()
{
//    freopen("in","r",stdin);
    while(scanf("%s",exp)!=EOF)
    {
        scanf("%lld %lld",&a,&b);
        if (a==9)
        {
            printf("A\n");
            continue;
        }
        if (b==9)
        {
            printf("B\n");
            continue;
        }
        int d=0;
        LL tmp=0,cal=0;
        int len = strlen(exp);
        for (int i=0;i<len;i++)
        {
            if (exp[i]=='+')
            {
                cal = calcu(d,cal,tmp);
                tmp = 0;
                d = 0;
                continue;
            }
            if (exp[i]=='-')
            {
                cal = calcu(d,cal,tmp);
                tmp = 0;
                d = 1;
                continue;
            }
            tmp = tmp*10 + exp[i]-48;
        }
        cal = calcu(d,cal,tmp);
        if (a==cal)
            printf("B\n");
        if (b==cal)
            printf("A\n");
    }
    return 0;
}
