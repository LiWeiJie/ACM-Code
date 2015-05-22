//ural 1931 Excellent Team
//http://acm.timus.ru/problem.aspx?space=1&num=1931
/*
 * 题意:
 * 按照输入顺序进行比较，较小则保留。输出进行比较次数最多的数的序列号。从1开始计数
 * 思路:
 * 直接模拟即可
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
using namespace std;

int n;

int main()
{
	std::ios::sync_with_stdio(false);
	while(cin >> n){
        int tmp,top = 1000000007,ct = -1,ci = 1,ans,compare_ct = -1;;
        for (int i=1;i<=n;i++){
            cin >> tmp;
            ct++;
            if (tmp<top){
                if (ct>=compare_ct){
                    ans = ci;
                    compare_ct = ct;
                }
                ct = 0;
                top = tmp;
                ci = i;
            }
        }
        if (ct>=compare_ct){
            ans = ci;
            compare_ct = ct;
        }
        cout << ans << endl;

	}

	return 0;
}
