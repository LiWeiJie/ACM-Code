/*
ID: apprent2
PROG: friday
LANG: C++
*/

#include <string>
#include <fstream>
using namespace std;
const int maxn = 999;

bool IsLeap(int x)
{
    if (x%400 ==0) return 1;
    else
        if ( (x % 4 ==0) && (x %100 !=0)) return 1;
    return 0;

}

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31},weeks [7] = {0},n;
    fin >> n ;
    int sum = 13;
    for (int i = 1 ; i<=n ; i++)
    {
        if (IsLeap(1900+i-1)) months[2]++;
        for (int j = 1 ; j <=12 ;j++)
        {
            sum =(sum+ months[j-1])%7;
            weeks[sum ] ++;
        }
        sum =(sum+ months[12])%7;;
        months[2] = 28 ;
    }

    fout << weeks[6] << " " << weeks[0];
    for (int i = 1 ; i<=5 ; i++)
        fout << " " << weeks[i];
    fout <<endl;
    return 0;
}
