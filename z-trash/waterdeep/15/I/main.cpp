#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

#define N 2200

using namespace std;

int a[N][N];
int maxn,maxm;

int LCS(const char *s1, const char *s2)
{// s1:0...m, s2:0...n
    int m = strlen(s1), n = strlen(s2);
    int i, j;
    a[0][0] = 0;
    maxn = 0;
    maxm = 0;
    for( i=1; i <= m; ++i ) a[i][0] = 0;
    for( i=1; i <= n; ++i ) a[0][i] = 0;
    for( i=1; i <= m; ++i )
    for( j=1; j <= n; ++j ){
    if(s1[i-1]==s2[j-1])
    {
        a[i][j] = a[i-1][j-1]+1;
        if (a[i][j]>maxn)
        {
            maxn = a[i][j];
            maxm = j;
        }
    }
    else
    {
        if(a[i-1][j]>a[i][j-1]) a[i][j]= a[i-1][j];
        else a[i][j] = a[i][j-1];
    }
    }
    return a[m][n];
}



int main()
{
    int t;
    char aa[N],bb[N];

    while (scanf("%s\n%s",&aa,&bb)!=EOF)
    {
		LCS(aa,bb);
		int tmp = a[strlen(aa)][strlen(bb)];
		printf("%d\n",tmp);
		for (int i=maxm-maxn;i<maxm;i++)
		{
		    printf("%c",bb[i]);
		}
		printf("\n");
    }
    return 0;
}
