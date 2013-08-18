//hdu 4608 I-number
//http://acm.hdu.edu.cn/showproblem.php?pid=4608
/*
 * 题意:
 * 给出长度不超过10^5的整数x
 * 输出比x大的，且十进制下所有位数和为10的整数倍的最小一个整数y
 * 思路:
 * 直接暴力模拟，从x开始，每次+1之后检查是否符合条件
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010
using namespace std;

int t;
char x[N];

bool check(char z[]){
    int sum = 0;
    int len = strlen(z);
    for (int i=0;i<len;i++){
        sum += z[i]-48;
    }
    return (sum%10==0)?true:false;
}

void add(char z[]){
    int len = strlen(z);
    int i;
    for (i=len-1;i>=0;i--){
        if (z[i]=='9'){
            z[i] = '0';
        } else {
            z[i]++;
            break;
        }
    }
    if (i<0) {
        z[len+1] = '\0';
        for (i=len;i>=1;i--){
            z[i] = z[i-1];
        }
        z[0] = '1';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> x;
        add(x);
        while(check(x)==false)
            add(x);
        cout << x<< endl;
    }

	return 0;
}
