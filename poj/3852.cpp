//poj 3852 String LD
//http://poj.org/problem?id=3852
//模拟

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<string,bool>v;
char name[105][105];

int main()
{
//    cout << "Hello world!" << endl;
    int n;
    int len;
    std::ios::sync_with_stdio(false);
    while(cin >> n)
    {
        if (n==0)break;
        len = 0x3f3f3f3f;
        int ct = 0;
        for(int i=0; i<n; i++)
        {
            cin >> name[i];
            int llen = strlen(name[i]);
            if(len > llen)
                len = llen,ct=1;

            else if (len==llen){
                ct++;
            }
        }
        int ans = 0;
        for(int i=1; i<=len; i++)
        {
            v.clear();
            for (int j=0;j<n;j++){
                if (v[name[j]+i-1]++ ==1){
                    ans = i;
                    break;
                }
            }
            if (ans!=0)
                break;
        }
        if (ans==0)
            cout << len-1 << endl;
        else
            cout << ans-2 << endl;

    }
    return 0;
}
