//cf 298C Parity Game
/*
两种操作可以看做把前面的1搬到后面，删除前面的数，或者在后面添加0
所以本题的关键是1的个数，设a串拥有1的个数为ca，b串拥有1的个数为cb。
若ca>=cb,则毫无疑问能把a串转化为b串
需要注意的是，因为ca为奇数的时候，可以直接在后面添加1，所以，若ca为奇数，可将ca+1补全至偶数
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1010
using namespace std;

char a[N],b[N];

int ca[N];
int cb[N];


int main()
{
    scanf("%s",a);
    scanf("%s",b);
    int lena = strlen(a);
    int lenb = strlen(b);
    if (a[0] == '1') ca[0] = 1;
    else ca[0] = 0;
    for (int i=1;i<lena;i++)
    {
        ca[i] = ca[i-1];
        if (a[i]=='1')
            ca[i]++;
    }
    if (b[0] == '1') cb[0] = 1;
    else cb[0] = 0;
    for (int i=1;i<lenb;i++)
    {
        cb[i] = cb[i-1];
        if (b[i]=='1')
            cb[i]++;
    }
    if (ca[lena-1]%2==1)
        ca[lena-1]++;
    if (ca[lena-1]>=cb[lenb-1])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
