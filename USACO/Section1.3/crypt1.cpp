/*
    ID:apprent2
    PROG:crypt1
    LANG:C++
*/

#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int g[10] ,n,tmp;
    scanf("%d",&n);
    memset(g,0,sizeof(g));
    while (n--)
    {
		scanf("%d",&tmp);
		g[tmp]++;
    }
    int ans = 0;
    for (int i=1;i<10;i++)
    {
        if (g[i])
        {
//            g[i]--;
            for (int j=1;j<10;j++)
            {
                if (g[j])
                {
//                    g[j]--;
                    for (int k=1;k<10;k++)
                    {
                        if (g[k])
                        {
//                            g[k]--;
                            for (int a=1;a<10;a++)
                            {
                                if (g[a])
                                {
//                                    g[a]--;
                                    tmp = k+j*10+i*100;
                                    tmp *=a;
                                    if (tmp>=1000||tmp<100) continue;
                                    while((tmp%10)&&g[tmp%10])
                                    {
                                        tmp /=10;
                                    }

                                    if (tmp==0)
                                    {
                                        tmp = k+j*10+i*100;
                                        tmp *=a;
                                        if (g[tmp%10])
                                        {
                                            for (int b=1;b<10;b++)
                                            {
                                                if (g[b])
                                                {
        //                                                g[b]--;
                                                    tmp = k+j*10+i*100;
                                                    tmp *=b;
                                                     if (tmp>=1000||tmp<100) continue;
                                                    while((tmp%10)&&g[tmp%10])
                                                    {
                                                        tmp /=10;
                                                    }
                                                    if (tmp == 0)
                                                    {
                                                        tmp = (k+j*10+i*100)*(a+b*10);

                                                        while((tmp%10)&&g[tmp%10])
                                                        {
                                                            tmp /=10;
                                                        }
                                                        if (tmp==0)
                                                        {
                                                            ans ++;
//                                                            printf(" %d%d%d\n  %d%d\n   ")
                                                        }
                                                    }




        //                                                g[b]++;
                                                }
                                            }
                                        }
                                    }


//                                    g[a]++;
                                }
                            }
//                            g[k]++;
                        }
                    }
//                    g[j]++;
                }
            }
//            g[i]++;
        }

    }
    printf("%d\n",ans);
    return 0;
}
