//scnucpc 2013 final 1010 Insertion Sort
/*
找出最长不下降子序列的长度
也就是不需要改动的数字数
那么剩下的数字都是需要进行操作的，数量即所求
*/
#include <iostream>
#include <cstdio>
#define MAXN 500050
using namespace std;

int f[MAXN],a[MAXN];
int t,n;

int bsearch(int *f,int size,int des)
{
    int l = 0,r = size-1;
    int mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if (des>=f[mid-1]&&des<f[mid])
        {
            return mid;
        }else
        {
            if (des>=f[mid])
                l = mid+1;
            else
                r = mid-1;
        }
    }

}

int lis(int *a,int n)
{
    int size = 1;
    f[size-1] = a[0];
    int sw;
    for (int i=1;i<n;i++)
    {
        if (a[i]<f[0])
            sw = 0;
        else
        {
            if (a[i]>=f[size-1])
                sw = size++;
            else
            {
                sw = bsearch(f,size,a[i]);
            }
        }
        f[sw] = a[i];
    }
    return size;
}

int main()
{
//    freopen("in","r",stdin);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",n-lis(a,n));
    }

    return 0;
}
