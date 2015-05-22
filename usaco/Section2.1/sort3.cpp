//sort3
/*
因为有三个等级的奖牌，所以可以把整个数组分成三段.然后分别记录三段上存在的其他两段等级江牌的数量，例如e[0][1]=2说明第一段上有第二等级的奖牌,而e[1][0]=5,则可以交换较小值次，然后差值就是遗留的不和谐奖牌，依次计算后，还有k个遗留，则还要交换k*2/3次
PROG:sort3
LANG:C++
ID:apprent2
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define N  1000

int s[N];
int c[3];
int e[3][3];

int les(int a,int b){
    return a<b?a:b;
}


int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=0;i<3;i++)   c[i] = 0;
    for (int i=0;i<n;i++){
        scanf("%d",&s[i]);
        c[s[i]-1]++;
    }
    c[1] += c[0];
    c[2] += c[1];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            e[i][j]=0;
    for (int i=0;i<c[0];i++){
        switch (s[i]){
            case 2:e[0][1]++;break;
            case 3:e[0][2]++;break;
            default:break;
        }
    }

    for (int i=c[0];i<c[1];i++){
        switch (s[i]){
            case 1:e[1][0]++;break;
            case 3:e[1][2]++;break;
            default:break;
        }
    }

    for (int i=c[1];i<c[2];i++){
        switch (s[i]){
            case 2:e[2][1]++;break;
            case 1:e[2][0]++;break;
            default:break;
        }
    }

    int result = 0,err = 0;

    result = les(e[0][1],e[1][0])+les(e[0][2],e[2][0])+les(e[1][2],e[2][1]);
    err = abs(e[0][1]-e[1][0])+abs(e[0][2]-e[2][0])+abs(e[1][2]-e[2][1]);

    result += err*2/3;

    printf("%d\n",result);

    return 0;
}
