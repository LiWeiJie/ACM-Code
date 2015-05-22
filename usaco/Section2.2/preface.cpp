//Preface Numbering序言页码
/*
PROG:preface
LANG:C++
ID:apprent2
把每个位数上的0-9种可能预先存放在数组上。
然后遍历每一位计算就可以了
*/

#include <iostream>
#include <cstdio>

using namespace std;

string roma[][10] = { {"" , "I" , "II" ,"III" ,"IV" ," V","VI","VII","VIII","IX"},
                    {"" ,  "X","XX"  ,"XXX" ,"XL" , "L","LX","LXX","LXXX","XC"},
                    {"" , "C" ,"CC"  ,"CCC" ,"CD" , "D","DC","DCC","DCCC","CM"},
                    {"" , "M" ,"MM"  ,"MMM" }
                  };

int result[7];
char sresult[] = {'I','V','X','L','C','D','M'};

void to_result(string m)
{
    for (int i=0;i<m.size();i++){
        for (int j=0;j<7;j++){
            if (sresult[j]==m[i]){
                result[j]++;
                break;
            }
        }
    }
}

void to_string(int m)
{
    int i=0;
    int r;
    do
    {
        r = m%10;
        if (r!=0) {
            to_result(roma[i][r]);
        }
        i++;
        m/=10;
    }while (m!=0);
}
int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        to_string(i);
    }
    for (int i=0;i<7;i++){
        if (result[i]!=0)
            printf("%c %d\n",sresult[i],result[i]);
    }
    return 0;
}

