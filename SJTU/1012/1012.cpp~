#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>


using namespace std;

struct NT
{
    int no;
    int num;
};

#define N 200001
int main()
{
    int s,t;
    long group[N];

    while(scanf("%d %d",&s,&t)!=EOF)
    {
        memset(group,0,sizeof(group));
        int tmp;
        int base;
        NT ans;
        ans.no = 0;
        ans.num = 0;
        for (int i=s;i<=t;i++)
        {
            base = 100;
            for (int j=1;j<=100;j++)
                if (j*i % 100 == 0)
                {
    //                base = j;
                    if (i*j/100+i > t) break;
                    if (group[i*j/100+i]<(group[i]+1))
                    {

                        group[i*j/100+i]= group[i]+1;
//                        if (i*j/100+i == 200000 && group[i*j/100+i]==49)
//                            printf("%d\n",i);
//                        if (group[i*j/100+i]==ans.no) ans.num++;
//                        else
//                        {
//                            if (group[i*j/100+i]>ans.no)
//                            {
//                                ans.no = group[i*j/100+i];
//                                ans.num = 1;
//                            }
//                        }
                    }
                }
            int k=1;
        }
//        printf("\n");
        for (int i=s;i<=t;i++)
        {
//            if (group[i]==49)
//                printf("%d ",i);
            if (group[i]==ans.no) ans.num++;
            else
            {
                if (group[i]>ans.no)
                {
                    ans.no = group[i];
                    ans.num = 1;
                }
            }
        }

        printf("%d\n%d\n",ans.no+1,ans.num);
    }



    return 0;
}
