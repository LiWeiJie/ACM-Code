//cf 298D Fish Weight
/*
首先对Alice和Bob钓到的鱼的序号进行升序排序。
然后从Alice和Bob的后面对照扫起，比较Alice和Bob对应的序号大小，大的则指针向前移，相等则一起向前移，并使用diff记录Alice和Bob的差值。
diff的初值为0，若是Alice指针对应值要比Bob指针对应值大，则diff++；若比Bob小，则diff--。
若途中发生了diff>0的情况，则可以不继续下去，认为Alice的钓鱼的总价值是有可能大于Bob的。
到了最后，若diff>0则输出YES，否则输出NO
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100010
using namespace std;

int alice[N],bob[N];
int n,m,k;

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;i++)
        scanf("%d",&alice[i]);
    for (int i=0;i<m;i++)
        scanf("%d",&bob[i]);
    sort(alice,alice+n);
    sort(bob,bob+m);
    int ca,cb;
    ca = n-1;
    cb = m-1;
    int diff = 0;
    while (ca!=-1&&cb!=-1)
    {
        if (alice[ca]<bob[cb])
        {
            diff--;
            cb--;
        }else
        {
            if (alice[ca]>bob[cb])
            {
                diff++;
                ca--;
            }else
            {
                ca--;
                cb--;
            }
        }
        if (diff>0) break;
    }
    if (diff<=0&&ca!=-1)
    {
        diff += ca+1;
    }
    if (diff>0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
