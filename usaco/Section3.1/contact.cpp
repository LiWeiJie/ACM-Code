//usaco 3.1 Contact
/*
ID:apprent2
PROG:contact
LANG:C++
由于1<=A,B<=12
所以二进制字符串转换为十进制也就是0-4048而已
由于0 和 00 等不同0值转换出来的十进制是一样的，所以在所有字符串子串的头部加上1之后再转换
即原子串000，1011和00.看做1000,11011和100来看待
转换为十进制后作为下标映射到整型数组上累加
liweijie
2013/4/11
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct point
{
    int no;
    int num;
    bool operator<(const point &rhs)const
    {
        if (num>rhs.num) return true;
        else
        if (num==rhs.num) return no<rhs.no;
        return false;
    }
};

int a,b,n;
int weight[] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
int f[13];
point ans[10000];
char s[200020],tmp[100];

int main()
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    scanf("%d %d %d",&a,&b,&n);
    getchar();
    while(scanf("%s",tmp)==1)
    {
        strcat(s,tmp);
    }
    f[0] = 0;
    int cha = b-a,len = strlen(s);
    for (int i=0;i<a;i++)
        f[0] = f[0]*2+s[i]-48;
    for (int i=0;i<10000;i++)
        ans[i].no=i,ans[i].num=0;
    ans[f[0]+weight[a+1]].num++;
    for (int j=1;j<=cha;j++)
    {
        if (a-1+j<len)
        {
            f[j] = f[j-1]*2+s[a-1+j]-48;
            ans[f[j]+weight[a+j+1]].num++;
        }else break;
    }
    for (int i=a;i<len;i++)
    {
        for (int j=0;j<=cha;j++)
        {
            if (i+j<len)
            {
                if (s[i-a]=='1')
                    f[j] -= weight[a+j];
                f[j] = f[j]*2+s[i+j]-48;
                ans[f[j]+weight[a+j+1]].num++;
            }else break;
        }
    }
    sort(ans,ans+10000);
    int bi[15];
    int bp,num,last = 0,ct=0,cst = 0;
    for (int i=0;i<10000;i++)
    {
        if (ans[i].num!=0)
        {
            bp = 0;
            num = ans[i].no;
            while(num>0)
            {
                bi[bp++] = num%2;
                num /= 2;
            }
            cst++;
            if (ans[i].num!=last)
            {
                cst = 1;
                ct++;
                if (ct>n) break;
                if (last!=0) printf("\n");
                printf("%d\n",ans[i].num);
                last = ans[i].num;
            }else
            {
                if (cst>6) printf("\n"),cst=1;
                else printf(" ");
            }

            for(int j=bp-2;j>=0;j--)
                printf("%d",bi[j]);
        }
        else
            break;
    }
    printf("\n");
    return 0;
}
