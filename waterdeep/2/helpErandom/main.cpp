#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int ans[100];

    int n;
srand(time(NULL));
    int op = 0;
    int opp = 0;
    do
    {

        int count = 0;
        n = rand()%30 + 8;
        cout << n << endl;
        for (int i=0;i<n;i++)
            ans [i] = i+1;
        int re = rand()+1;
        for (int i=0;i<re;i++)
        {
            op = rand();
            if (op>=0)
            {
                if (op>=n) op %=n;
                int tmp;
                int ch;
                tmp = ans[op];
                ch = op+3;
                if (ch>=n) ch%=n;
                ans[op] = ans[ch];
                ans[ch] = tmp;
                op++;
                if (op>=n) op%=n;
                tmp = ans[op];
                ch = op+1;
                if (ch>=n) ch%=n;
                ans[op] = ans[ch];
                ans[ch] = tmp;
            }w
        }

        for (int i=0;i<n;i++)
            cout << ans [i] << " ";
            cout << endl;
//        for (int i=0;i<n;i++)
//            count += abs(ans[i]-i-1);
//        cout << "TOT:" << count << "  N:" << n<< endl;
//        cout << "div 8:" << count /8 << "   mod 8 :" << count % 8 << endl;
        if (opp==0)cin >> opp;
    }while(opp--!=-1);

    return 0;
}
