//298A Snow Footprints
/*
很简单的归纳题，若是存在R或者L，则必定左边为R，右边卫L，开始地点随意定在存在L或者R的位置，结束地点定在L和R的交界处任一边就可以了。
若只有L的情况下，开始位置存在L的最右边位置，结束位置为L的最左边-1
若只有R的情况下，开始位置存在R的最左边位置，结束位置为R的最右边+1
*/
#include <iostream>
#include <cstdio>

using namespace std;

int n;
char s[1080];
int lst,rst,led,red;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        lst = -1;
        rst = -1;
        led = -1;
        red = -1;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='R')
                red = i;
            if (s[i]=='L')
                led = i;
            if (rst==-1&&s[i]=='R')
            {
                rst = i;
            }
            if (lst==-1 &&s[i]=='L')
            {
                lst = i;
            }

        }
        if (led==-1)//L不存在
        {
            printf("%d %d\n",rst+1,red+1+1);
        }else
        {
            if (red==-1)//R不存在
            {
                printf("%d %d\n",led+1,lst-1+1);
            }
            else
            {
                printf("%d %d\n",rst+1,red+1);
            }
        }
    }
    return 0;
}
