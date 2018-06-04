#include <iostream>
#include <set>
using namespace std;

struct node{int a,b;}no[101];

set<int> ct[1001];

int main() {
    int T;
    const int sz = 1001;
    while(cin >> T) {
        // ct.clear()
        for (int i=0; i<T; i++) {
            int a,b;
            cin >> no[i].a >> no[i].b;
            ct[no[i].b].insert(i);
        }
        int ans = 0;
        for (int i=0; i<T; i++) {
            if (ct[no[i].a].size() >1) 
                continue;
            if (ct[no[i].a].size() == 1 &&   *ct[no[i].a].begin() != i)
                continue; 
            ans ++;
        }
        cout << ans << endl;
    }
}