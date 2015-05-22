//usaco 2.4 comehome
/*
PROG:comehome
ID:apprent2
LANG:C++
Executing...
   Test 1: TEST OK [0.000 secs, 3244 KB]
   Test 2: TEST OK [0.000 secs, 3244 KB]
   Test 3: TEST OK [0.000 secs, 3244 KB]
   Test 4: TEST OK [0.000 secs, 3244 KB]
   Test 5: TEST OK [0.000 secs, 3244 KB]
   Test 6: TEST OK [0.000 secs, 3244 KB]
   Test 7: TEST OK [0.000 secs, 3244 KB]
   Test 8: TEST OK [0.000 secs, 3244 KB]
   Test 9: TEST OK [0.000 secs, 3244 KB]

All tests OK.
通过Floyd-Warshall计算出每个结点间的距离，最后输出A-Y到Z即谷仓的最小值就可以了
*/
#include <iostream>
#include <cstdio>

using namespace std;

int s[60][60];

int main()
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int m;
    scanf("%d",&m);
    for (int i=0;i<60;i++)
    for (int j=0;j<60;j++)
        s[i][j] = 99999;
    for (int i=0;i<m;i++)
    {
        getchar();
        char a,b;
        int dis;
        scanf("%c %c %d",&a,&b,&dis);
        if (a==b) continue;
        if (dis<s[a-'A'][b-'A'])
        {
            s[a-'A'][b-'A'] = dis;
            s[b-'A'][a-'A'] = dis;
        }
    }
    for (int k=0;k<='z'-'A';k++)
    {
        for (int i=0;i<='z'-'A';i++)
        {
            for (int j=0;j<='z'-'A';j++)
            {
                if (s[i][k]+s[k][j]<s[i][j])
                {
                    s[i][j] = s[i][k]+s[k][j];
                }
            }
        }
    }
    int mini = 0;
    for (int i=0;i<'Z'-'A';i++)
    {
        if (s['Z'-'A'][i]<s['Z'-'A'][mini])
            mini = i;
    }
    printf("%c %d\n",'A'+mini,s['Z'-'A'][mini]);
    return 0;
}
