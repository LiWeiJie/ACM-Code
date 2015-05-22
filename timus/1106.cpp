//URAL timus 1106  Two Teams
//http://acm.timus.ru/problem.aspx?space=1&num=1106
/*
题意：
给出N人，以下N行表示所交朋友，0结束
把这些人划分为两个team，team成员必须至少有一个朋友在另一个team
题解：
每个人有两个标记量，记录是否有朋友在teamA，在teamB；
从头检索
若teamA为false，则把自己放到teamA，标记朋友圈的teamA为true，表示有朋友在teamA
否则
    若teamB为false，把自己放到teamB，标记朋友圈的teamB为true，表示有朋友在teamB
    否则
         说明teamA和teamB都为true，则该人放在teamA或teamB都可以，可不做处理
*/
#include <cstdio>

#define N 101

bool flag[N][2];
int fri[N][N];
int ans [N];
int ansc;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ansc = 0;
        for (int i=0;i<n;i++)
        {
            ans[i] = 0;
            flag[i][0] = false;
            flag[i][1] = false;
            int j=0;
            do
            {
                scanf("%d",&fri[i][j]);
                fri[i][j]--;
            }while(fri[i][j++]!=-1);
        }
        ans[n] = 0;
        for (int i=0;i<n;i++)
        {
            if (flag[i][0]==false)
            {
                ans[ansc++] = i+1;
                int j=0;
                do
                {
                    flag[fri[i][j]][0] = true;
                }while(fri[i][j++]!=-1);
            } else
            {
                if (flag[i][1]==false)
                {
                    int j=0;
                    do
                    {
                        flag[fri[i][j]][1] = true;
                    }while(fri[i][j++]!=-1);
                }
            }
        }
        printf("%d\n%d",ansc,ans[0]);
        for (int i=1;i<ansc;i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
