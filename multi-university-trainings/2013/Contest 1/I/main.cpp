#include <iostream>
#include <cstring>

using namespace std;

void inc(string &x,int sum){
    int tmp;
    int len = x.length();
    int fin = len*9;
    if (sum==fin){
        x = "1";
        tmp = len;
        while(tmp--){
            x += "0";
        }
    } else {
        for (int i=len-1;i>=0;i--){
            if (x[i]!='9'){
                x[i] += 1;
                break;
            } else {
                x[i] = '0';
            }
        }
    }

}

int check(string &x)
{
    int sum = 0;
    int len = x.length();
    int fin = len*9;
    int tmp = len;
    while(tmp--){
        sum+=x[tmp]-48;
    }
    if (sum%10==0) return 0;
    return sum;
}

int main()
{
    int T;
    cin >> T;
    string x;
    int sum;
    while(T--){
        sum = 0;
        cin >> x;
        int tmp = x.length();
        while(tmp--){
            sum+=x[tmp]-48;
        }
        inc(x,sum);
        while(sum=check(x)){
            inc(x,sum);
        }
        cout << x << endl;
    }
    return 0;
}

