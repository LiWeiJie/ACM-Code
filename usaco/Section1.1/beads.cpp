/*
ID: apprent2
PROG: beads
LANG: C++
*/
//#include <iostream>
#include <fstream>


using namespace std;
const int maxn = 999;
int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    char s[maxn] ={""};
    int n;
    fin >> n ;
    for (int i=1; i <=n ; i++)
        fin >> s[i];
    for (int i=n+1; i <=2*n ; i++)
        s[i] = s[i-n];
    char a,b;
    int top=1,last,mid=1;
    while (s[mid] == 'w')  mid++;
    a = s[mid];
    while (s[mid] == a || s[mid] == 'w') mid++;
    int max;
    if (mid>2*n) max = n;
    else
    {
    b = s[mid] ;
    last = mid ;
    while ((s[last] == b || s[last] == 'w')&& last-n<=top) last++;
    max = last -top ;

    for (int i = 0; i< 2*n ; i++)
    {
        top = mid ; a = s[mid];
        while (s[top-1]=='w') top --;
        mid = last ; b = s[mid];
        while ((s[last] == b || s[last] == 'w')&& last-n<top) last++;
        if (top>n) break ;
        if (last-top > max ) max =last -top ;
    }
    }
    fout << max << endl;
    return 0;
}
