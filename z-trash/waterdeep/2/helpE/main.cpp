#include <iostream>

using namespace std;

int main()
{
    int ans[100];

    int n;
    cin >> n;
    for (int i=0;i<=n;i++)
        ans [i] = i;
    int op = 0;
    do
    {
        int ans = 0;

        if (op!=0&&op<=n)
        {
            int tmp;
            int ch;
            tmp = ans[op];
            ch = op+3;
            if (ch>n) ch-=n;
            ans[op] = ans[ch];
            ans[ch] = tmp;
            op++;
            if (op>n) op-=n;
            tmp = ans[op];
            ch = op+1;
            if (ch>n) ch-=n;
            ans[op] = ans[ch];
            ans[ch] = tmp;
        }
        for (int i=1;i<=n;i++)
            cout << ans [i] << " ";
            cout << endl;
        for (int i=1;i<=n;i++)
            ans +=
        cin >> op;
    }while(op!=-1);

    return 0;
}
