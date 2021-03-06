
/*
    ID:apprent2
    PROG:dualpal
    LANG:C++
*/

#include <iostream>
#include <fstream>

using namespace std;

bool IsPal(string s)
{


    for (int i=0;i<s.length()/2;i++)
        if(s[i]!=s[s.length()-1-i]) return false;
    return true;
}

string Convest(long n,int k)
{
    char s[255];
    int now=0;
    if (n==0) return "0";
    while(n!=0)
    {
        int con = 48+n%k;
        if (con>'9') con=con+'A'-'9'-1;
        s[now++] = con;
        n = n/k;
    }
    char tmp[256] = "";
    for (int i=0;i<now;i++)
        tmp[i] = s[now-1-i];
    return tmp;
}



int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,s;
    cin>>n>>s;
    int count = 0;
    long now = s;
    while(count<n)
    {
        ++now;
        int pcount=0;
        for (int i = 2; i<=10;i++)
        {
            if (IsPal(Convest(now,i))) pcount++;
            if (pcount>=2) break;
        }
        if (pcount>=2)
        {
            count++;
            cout << now <<endl;
        }
    }

    return 0;
}
