//Hamming Codes
/*
从0开始枚举，跟之前存进的数字进行异或之后判断1的数量是否大于d，大于则可以存进数组，直到满足n个

PROG:hamming
LANG:C++
ID:apprent2

*/
#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

#define D 7
#define B 8
#define N 64

int d,b,n;
int bs[N];

int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    scanf("%d %d %d",&n,&b,&d);
    int ct=0;
    int s=-1,z;
    bool f ;
    while(ct<n){
        s++;
        f = true;
        for (int i=0;i<ct;i++){
            z = s^bs[i];
            bitset<8> test(z);
            if (test.count()<d){
                f = false;
                break;
            }
        }
        if (f){
            printf("%d",s);
            bs[ct++] = s;
            if (ct<n){
                if (ct%10==0) printf("\n");
                else printf(" ");
            }

        }
    }
    printf("\n");
    return 0;
}
