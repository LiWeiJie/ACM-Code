/*
    ID:apprent2
    PROG:palsquare
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

string Convest(int n,int k)
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
    freopen ("palsquare.in","r",stdin);
    freopen ("palsquare.out","w",stdout);
    int k;
    cin>>k;
    for (int i=1;i<=300;i++)
    {
        string base,bbase;
        base = Convest (i,k);
        bbase = Convest (i*i,k);
        if (IsPal(bbase)) cout << base <<" "<< bbase <<endl;
    }
        //cout<< i*i << "  " << Convest (i*i,k)<<endl;

    return 0;
}
