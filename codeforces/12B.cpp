//cf 12B Correct Solution?
/*
输入一个整数n(0 ≤ n ≤ 10^9)和m(0 ≤ m ≤ 10^9).保证n没有leading zero(前导零),判断m是否重组n的数字顺序之后的最小值
创建一个整型数组s[]，记录在n中0-9各个数字出现的次数，然后判断s[1--9]中出现的第一个出现次数大于0的数字是否等于m的头数字。
然后就在s[0--9]里面凡是大于0的都逐一跟m的下一位匹配，然后减一，直至扫完所有。
最后特判一下当n=0时的情况
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int s[12],m;
char a[12],b[12];
bool flag = true;
int chan;

int main()
{
    scanf("%s",a);
    scanf("%s",b);
    int len = strlen(a);
    for (int i=0;i<12;i++)
    {
        s[i] = 0;
    }
    for (int i=0;i<len;i++)
    {
        s[a[i]-48]++;
    }
    if (len!=strlen(b))//若字符长度不一致，绝对不可能满足要求
    {
        flag = false;

    }else
    {
        chan = 0;
        for (int i=1;i<10;i++)
            if (s[i]>0)
            {                
                if (i!=(b[0]-48))
                    flag = false;
                chan++;
                s[i]--;
                break;
            }
        m = 0;
        for (int i=1;i<len;i++)
        {
            while(s[m]==0)m++;
            if (m!=(b[i]-48))
            {
                flag = false;
                break;
            }
            chan++;
            s[m]--;
        }
    }
    if (len==1&&a[0]!=b[0]) flag = false;
    if (flag ==true)printf("OK\n");
    else printf("WRONG_ANSWER\n");
    return 0;
}
