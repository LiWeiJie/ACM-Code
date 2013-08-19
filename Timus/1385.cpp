//URAL 1385 Interesting Number
//http://acm.timus.ru/problem.aspx?space=1&num=1385
/*
 * 题意:
 * 2*N位数，前N位组成X，后N位组成Y，令X*10^N+Y能被X和Y整除
 * 给出N，输出符合条件的数的数量
 * 思路:
 * X | X*10^N+Y 和 Y | X*10^N+Y
 * 即 Y | X*10^N 和 X | Y,令Y = K*X
 * 则 K*X | X*10^N  => K | 10^N ,即能整除10^N的K的数量
 * 由于X和Y的位数相同的，所以还要限制K*X不会导致X高位进位。
 * 当n=2时，
 *  X在10-19有{1，2，4，5}满足，在20-24有{1，2，4}满足，在25-49有{1，2}满足，在50-49有{1}满足
 * 当n>=3时，
 *  100-124有{1,2,4,5,8}，125-199有{1,2,4,5},200-249有{1,2,4},250-499有{1,2},500-999有{1},
 *  最后输出n-3个0
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#define N 100000
#include <cstring>
using namespace std;



int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    long long ans;
    while(cin >> n){
        if (n==1){
            ans = 14;
            cout << ans << endl;
        } else if (n==2){
            //考虑1，2，4，5的情况
            ans = 10*4 + 5*3 + 25*2 + 50;
            cout << ans << endl;
        } else {
            //考虑1，2，4，5，8的情况
            ans = 25*5+75*4 +50*3 + 250*2 + 500;
            cout << ans ;
            for (int i=3;i<n;i++){
                cout << 0;
            }
            cout << endl;
        }

    }
	return 0;
}

