//usaco 2.3 zerosum
/*
PROG:zerosum
ID:apprent2
LANG:C++
本来在纠结着怎么在dfs里面处理空格和+，-运算符对数值的影响的。
最后发现，既然枚举时难以处理，就用字符串记录，最后统一处理就可以了
所以，就这样子暴力过了
*/
#include <iostream>
#include <cstdio>

using namespace std;

int s[12];
int n;

void check(string cal)
{
    int i=0;
    int tmp=0,result=0;
    char last=' ';
    while(i<cal.size())
    {
        switch (cal[i])
        {
            case '+':
            {
                if (last==' ')
                {
                    result = tmp;
                }else if (last=='+')
                {
                    result += tmp;
                }else if (last=='-')
                {
                    result -= tmp;
                }
                last = '+';
                tmp = 0 ;
                break;
            }

            case '-':
            {
                if (last==' ')
                {
                    result = tmp;
                }else if (last=='+')
                {
                    result += tmp;
                }else if (last=='-')
                {
                    result -= tmp;
                }
                last = '-';
                tmp = 0 ;
                break;
            }
            default:
            {
                tmp = tmp*10 + cal[i]-48;
            }
        }
        i++;
    }
    if (last==' ')
    {
        result = tmp;
    }else if (last=='+')
    {
        result += tmp;
    }else if (last=='-')
    {
        result -= tmp;
    }
    if (result==0)
    {
        cout << cal[0];
        for (int i=1;i<cal.size();i++)
        {
            if (cal[i]<='9'&&cal[i]>='0'&&cal[i-1]<='9'&&cal[i-1]>='0')
                cout <<" "<< cal[i];
            else
                cout << cal[i];
        }
        cout << endl;
    }
}

void dfs(string cal,int pos)
{
    if (pos>=n)
        check(cal);
    else
    {
        dfs(cal+char(s[pos]+48),pos+1);
        dfs(cal+"+"+char(s[pos]+48),pos+1);
        dfs(cal+"-"+char(s[pos]+48),pos+1);
    }
}

int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        s[i] = i+1;
    }
    dfs("1",1);
    return 0;
}
