/*
    ID:apprent2
    PROG:calfflac
    LANG:C++
*/
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
#include <fstream>
using namespace std;

#define N 22000



int dou(char cp[N],int mid, int x , int n)
{
    if (mid-x<0||mid+1+x>=n) return 0;
    if (cp[mid-x] == cp [mid+1+x] )
        return dou(cp,mid,x+1,n)+1;
    else return 0;
}

int sin(char cp[N],int mid,int x,int n)
{
    if (mid-x<0||mid+x>=n) return 0;

    if (cp[mid-x] == cp [mid+x] )
        return sin(cp,mid,x+1,n)+1;
    else return 0;
}


int main()
{
//    ofstream fout("~/1");
//    freopen("~/1","r",stdin);
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    char g[N] ,cp[N];
    int mk[N],lg,lc;
    char tmp;
    lg = 0;
    lc = 0;
    while (scanf("%c",&tmp)!=EOF)
    {
//        if (tmp=='\n') break;
        g[lg] = tmp;
        if ((tmp>='A'&&tmp<='Z')||(tmp>='a'&&tmp<='z'))
        {
            if (tmp>='A'&&tmp<='Z') tmp += 'a' - 'A';
            cp[lc] = tmp;
            mk[lc] = lg;
            lc++;
        }
        lg++;
    }
    int temp;
    int ans = 0 , ox,oy;
    for (int i = 0; i<lc;i++)
    {
        temp = sin(cp,i,0,lc);
        if (temp*2-1>ans)
        {
            ans = temp*2-1;
            ox = i-temp+1;
            oy = i+temp-1;
        }
        temp = dou(cp,i,0,lc);
        if (2*temp > ans )
        {
            ans = 2*temp;
            ox = i - temp+1;
            oy = i + temp;
        }
    }

    printf("%d\n",oy-ox+1);
    for (int i=mk[ox];i<=mk[oy];i++)
    {
        printf("%c",g[i]);
    }
    printf("\n");

    return 0;
}
