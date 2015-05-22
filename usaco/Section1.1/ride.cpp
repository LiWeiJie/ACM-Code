/*
ID: apprent2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
const int maxn = 99;
using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char a[maxn] = {""},b[maxn]={""};
    fin >> a >> b;
    int sa=1 , sb = 1;
    int i=0;
    while (a[i]!='\0')
    {
        sa *= a[i++]-'A'+1;
    }
    i = 0;
    while (b[i]!='\0')
    {
        sb *= b[i++]-'A'+1;
    }
    sa = sa % 47;
    sb = sb % 47;
    if (sa==sb)
    fout << "GO" << endl;
    else fout << "STAY" <<endl;
    return 0;
}

