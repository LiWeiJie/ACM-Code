//subset
/*
PROG:subset
LANG:C++
ID:apprent2
这里用了动态规划的一些思想，每一个式子都会有一个值。对于后来的数字，不需要关心前面值的参与数字。而加上这个后来数字能产生的新值就是已有的值加上它本身。
所以s[i+j] += s[j](i=1->n,j=max->0) ,i为后来者数字，j则是前面等式值。
为了数字不重复参与等式值运算，对于每一个i。从后面最大值开始干涉算式运算值结果。
*/
#include <iostream>
#include <cstdio>

using namespace std;

long long s[785];
int maxi;
int n;

int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<785;i++)
        s[i] = 0;
    s[0] = 1;
    maxi = 0;
    int e = (n+1)*n/2;
    if (e%2==0){
        e /=2;
        for (int i=1;i<=n;i++){
            for (int j=maxi;j>=0;j--){
                s[j+i] += s[j];
            }
            maxi +=i;
        }
        printf("%d\n",s[e]/2);
    }else {
        printf("%d\n",0);
    }
    return 0;
}
