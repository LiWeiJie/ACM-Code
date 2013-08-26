//tral 1935 Tears of Drowned
//http://acm.timus.ru/problem.aspx?space=1&num=1935
/*
 * 题意:
 * 有n个皮毛，第i个皮毛两边至少需要Si个sheets隔绝，问最小需要多少个sheets？
 * 思路:
 * 直接需求最大的放置在中间，然后两旁依次放置需求递减的皮毛，则可能sheets得到最大的利用。
 * 即只需要满足所有皮毛一边sheets的需求，另一边由需求更大的提供。总计就系sum + max（Si）
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int s[101];

int main()
{
	int n;
	cin >> n;
	int ans = 0;
    for (int i=0;i<n;i++){
        cin >> s[i];
        ans += s[i];
    }
    sort(s,s+n);
    ans += s[n-1];
    cout << ans << endl;


	return 0;
}
