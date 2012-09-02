/*
ID: apprent2
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int maxn = 999;
int search(string  s[] ,string ss,int n)
{
    for (int i=0 ; i < n ;i++)
        if (s[i]==ss) return i;
    return -1;
}
int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    fin >> n;
    string name[maxn] = {""};
    int keep [maxn] = {0};
    for (int i = 0;i <n ;i++ )
    fin >> name [i];
    for (int i = 0 ;i< n ;i++)
    {
        string na="";
        fin >> na;
        int zz = search(name,na,n);
        int money , m ,give ;
        fin >> money >>m;
        if (m!=0)
        give = money /m;
        keep[zz] -= give *m;
        for (int j=0; j< m ;j++)
        {
            string given = "";
            fin >> given ;
            keep [search(name ,given,n)] +=give;
        }

    }
    for (int i=0 ; i <n ;i++)
    {
        fout<< name [i] << " " << keep[i] <<endl;
    }

    return 0;
}
