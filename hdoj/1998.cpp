//hdu 1998 奇数阶魔方
//http://acm.hdu.edu.cn/showproblem.php?pid=1998
/*
 * 题意:
 * 给出奇数n，用右上法构造一个n阶魔方
 * 思路:
 * 由题目给出的示例中可以知道，右上法构造方法如下
 * 从第一行的中间数开始为1，然后这个位置的上一行右边为这个数+1，如果新位置已被使用，则新位置改为旧位置的正下方
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 22
using namespace std;

int n,t;
int s[N][N];

void next(int &x,int &y,int now){
    x-=1;
    if (x<0)x+=n;
    y+=1;
    y%=n;
    if (s[x][y]!=0&&s[x][y]<now){
        x+=2;
        x%=n;
        y-=1;
        if (y<0)y+=n;
    }
}

int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            int x = 0;
            int y = n/2;
            int dest = n*n;
            memset(s,0,sizeof(s));
            for (int i=1;i<=dest;i++){
                s[x][y] = i;
                next(x,y,i);
            }
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    printf("%4d",s[i][j]);
                }
                printf("\n");
            }

        }

    }
	return 0;
}

