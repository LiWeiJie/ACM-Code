#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int list[501];
        int ans=0;
        int n;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> list[i];
            ans += abs(list[i]-i);
        }
        ans %= n;
        if (ans % 8 == 0)
        {
            cout << "possible" << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }

    }
//    cout << "Hello world!" << endl;
    return 0;
}
