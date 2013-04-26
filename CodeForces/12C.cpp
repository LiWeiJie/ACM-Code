//cf 12C Fruits
/*
题目给出n个价格对应不同种类的水果和m个要买的水果(不保证水果种类不一致)
利用map把对应的水果名字转化为一个累加的整数，代表此水果在s[]中的记录下标，用s[]来记录对应下标要买的数量。
将s[]和价格数组price[]升序排序之后，no表示s数组的末位置+1，因为s[0]被弃用，所以s[]从1开始有意义
max_price = sum(price[n-i]*s[no-i])
min_price = sum(price[i-1]*s[no-i])
i=1->no-1
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
#include <algorithm>
#define N 110

using namespace std;

int price[N];
map<string,int> v;
int s[N];
char tmp[N];
int n,m,no,ctoi;


int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%d",&price[i]);
    for (int i=0;i<N;i++)
        s[i] = 0;
    no = 1;
    for (int i=0;i<m;i++)
    {
        scanf("%s",tmp);
        ctoi = v[tmp];
        if (ctoi==0)
        {
            v[tmp] = no;
            ctoi = no;
            no++;
        }
        s[ctoi]++;
    }
    sort(s+1,s+no);
    sort(price,price+n);
    int max_price=0,min_price=0;
    for (int i=1;i<no;i++)
    {
        max_price += price[n-i]*s[no-i];
        min_price += price[i-1]*s[no-i];
    }
    printf("%d %d\n",min_price,max_price);
    return 0;
}
