#include <iostream>

using namespace std;

const int MAX_N = 100001;
#define ll long long int

ll d[MAX_N];
ll add;

int main()
{
    int n,m;
    cin >> n >> m;
    int i,j;
    add = 0;
    for (i=0; i<n; i++) 
    {
        cin >> d[i];
    }
    for (i=0; i<m; i++) 
    {
        int t;
        cin >> t;
        if (t==1)
        {
            int v;
            ll x;
            cin >> v >> x;
            d[v-1] = x-add;
        } else if (t==2)
        {
            int y;
            cin >> y;
            add += y;
        } else if (t==3)
        {
            int q;
            cin >> q;
            cout << d[q-1]+add << endl;
        }
    }
}