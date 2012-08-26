#include <stdio.h>
//#include <algorithm>
//#include <iomanip>
#include <cstring>
//#include <vector>
//#include <queue>
//#include <list>

using namespace std;

int main()
{
    int l,w;
    while (scanf("%d %d",&l,&w)!=EOF)
    {
        int ans = 0,tmp;

            int ori[1000][1000];
        //    int group[1000][1000];
            int fin[1000][1000];
        //    memset(group,0,sizeof(group));
            memset(fin,0,sizeof(fin));
            for (int i=0;i<l;i++)
            {
                for (int j=0;j<w;j++)
                {
                    scanf("%d",&ori[i][j]);
                }
            }
            int a,b;
            scanf("%d %d",&a,&b);
            int sum = 0;
            for (int i=0;i<l;i++)
            {
                for (int j=0;j<b;j++)
                    fin[i][0] +=ori[i][j];
                sum += fin[i][0];
                if (i>=a-1)
                {
                    if (ans < sum) ans =sum;
                    sum -= fin[i-a+1][0];
                }
            }

            for (int i=1;i<w-b+1;i++)
            {
                sum = 0;
                for (int j=0;j<l;j++)
                {
                    fin[j][i] = fin[j][i-1] - ori[j][i-1] + ori[j][i+b-1];
                    sum += fin[j][i];
                    if (j>=a-1)
                    {
                        if (ans < sum) ans =sum;
                        sum -= fin[j-a+1][i];
                    }
                }
            }


        //    for (int i=0;i<a;i++)
        //            group[0][0] += fin[i][0];
        //    ans = group[0][0];
        //    for (int i=1;i<l-a+1;i++)
        //    {
        //        group[i][0] = group[i-1][0] - fin[i-1][0] + fin [i+a-1][0];
        //        if (ans < group[i][0]) ans = group[i][0];
        //    }
        ////
        //    for (int i=0;i<w-b+1;i++)
        //    {
        //        for (int j=0;j<b;j++)
        //            group[0][i]+=fin[j][i];
        //        if (ans < group[0][i]) ans = group[0][i];
        //    }
        //
        //
        //    for (int i=1;i<l-a+1;i++)
        //    {
        //        for (int j=0;j<w-b+1;j++)
        //        {
        //            group[i][j] = group[i-1][j] - fin[i-1][j] + fin[i+a-1][j];
        //            if (ans < group[i][j]) ans = group[i][j];
        //        }
        //    }
//            for (int i=0;i<l-a+1;i++)
//            {
//                for (int j=0;j<w-b+1;j++)
//                {
//                    tmp = 0;
//                    for (int k=i;k<i+a;k++)
//                    tmp+= fin[k][j];
//                    if (tmp>ans) ans =tmp;
//                }
//            }


            printf("%d\n",ans);
    }


    return 0;
}
