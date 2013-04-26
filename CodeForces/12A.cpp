//cf 12A Super Agent
/*
题意要求检查输入的3*3矩阵是否关于中心对称
把3行累加到char a[]里面去，然后从中心a[4]开始向两面搜，如果a[4-i]!=a[4+i](i=1->4)则说明不对称，输出NO,否则输出YES
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[18],b[18];

int main()
{
    memset(a,0,sizeof(a));
    for (int i=0;i<3;i++)
    {
        scanf("%s",b);
        strcat(a,b);
    }
    bool flag = true;
    for (int i=1;i<=4;i++)
    {
        if (a[4-i]!=a[4+i])
        {
            flag = false;
            break;
        }
    }
    if (flag==true)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
