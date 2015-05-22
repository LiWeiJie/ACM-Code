//usaco 3.1 Shaping Regions
/*
ID:apprent2
PROG:rect1
LANG:C++
开始先试用了暴力灌水法。开了一个10000*10000的数组来标记各个方块的颜色
暴力染色。本地测试通过了
提交上去缺爆空间了，USACO给的空间太少了
然后看到了题目给出的Hint1 (use them carefully!) ：An array of all 'points' is too big; 16MB maximum.
Keep track of the rectangles' coordinates; split the rectangle when an overlap occurs.
于是就使用了这个分割法。从后面开始列举矩形因为后面一旦确定就位置就是最终颜色了
对于每一个矩形，检查与后面的矩形有无重复，若有重复，则切割开来，将无重复的区域继续递归
liweijie
08/04/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define N 1010
struct rect
{
    int l;//left border
    int r;//right border
    int t;//top border
    int b;//bottom border
    int col;//color
};

int a,b,n;
rect s[N];
int count_col[2501];

using namespace std;

void init()
{
    memset(count_col,0,sizeof(count_col));
}

void cover(int l,int r,int t,int b,int no,int col)
{
    while( no<n && (l>=s[no].r || r<=s[no].l || t<=s[no].b || b>=s[no].t) )
        no++;
    if (no==n)
    {
        count_col[col] += (r-l)*(t-b);
        return;
    }
    //判断左边界
    if (l<s[no].l)
    {
        cover(l,s[no].l,t,b,no+1,col);
        l = s[no].l;
    }
    //判断右边界
    if (r>s[no].r)
    {
        cover(s[no].r,r,t,b,no+1,col);
        r = s[no].r;
    }
    //判断上边界
    if (t>s[no].t)
    {
        cover(l,r,t,s[no].t,no+1,col);
        t = s[no].t;
    }
    //判断下边界
    if (b<s[no].b)
    {
        cover(l,r,s[no].b,b,no+1,col);
    }
    return;
}

int main()
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    init();
    scanf("%d %d %d",&a,&b,&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d",&s[i].l,&s[i].b,&s[i].r,&s[i].t,&s[i].col);
    }
    for (int i=n-1;i>=0;i--)
    {
        cover(s[i].l,s[i].r,s[i].t,s[i].b,i+1,s[i].col);
    }
    count_col[1] = a*b;
    for (int i=2;i<=2500;i++)
        count_col[1] -= count_col[i];
    for (int i=1;i<=2500;i++)
        if (count_col[i]!=0)printf("%d %d\n",i,count_col[i]);
    return 0;
}
