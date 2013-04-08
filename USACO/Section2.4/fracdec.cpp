//usaco 2.4 fracdec
/*
PROG:fracdec
ID:apprent2
LANG:C++
Executing...
   Test 1: TEST OK [0.011 secs, 11044 KB]
   Test 2: TEST OK [0.011 secs, 11044 KB]
   Test 3: TEST OK [0.000 secs, 11044 KB]
   Test 4: TEST OK [0.011 secs, 11044 KB]
   Test 5: TEST OK [0.011 secs, 11044 KB]
   Test 6: TEST OK [0.011 secs, 11044 KB]
   Test 7: TEST OK [0.022 secs, 11044 KB]
   Test 8: TEST OK [0.043 secs, 11044 KB]
   Test 9: TEST OK [0.011 secs, 11044 KB]

All tests OK.

结果是否循环小数，可以由是否有重复余数被除来判断。
用r[]来记录每一个余数是否被计算过，-1即没有被计算过，否则表示由此计算出来的商的位置。循环节开始。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000100

using namespace std;

int r[N];
unsigned int result[N],pos;

int a,b,flag;

int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    scanf("%d %d",&a,&b);
    int ct = 0;
    int z = a/b;
    printf("%d.",z);
    if (z==0) ct = 1;
    while (z!=0) ct++,z/=10;
    ct++;
    for (int i=0;i<N;i++)
    {
        r[i] = -1;
    }
    pos = 0;
    flag = -1;
    a = a%b*10;
    while(a!=0)
    {
        if (r[a]==-1)
        {
            r[a] = pos;
            result[pos++] = a/b;
        }else
        {
            flag = r[a];
            break;
        }
        a = a%b*10;
    }
    if (pos==0) printf("0\n");
    else
    {
        for (int i=0;i<pos;i++)
        {
            if (ct==76) printf("\n"),ct=0;
            if (i==flag)
                printf("("),ct++;
            if (ct==76) printf("\n"),ct=0;
            printf("%d",result[i]),ct++;
        }
        if (flag!=-1)
        {
            if (ct==76) printf("\n"),ct=0;
            printf(")");
        }
        if (ct!=0)
            printf("\n");
    }
    return 0;
}
