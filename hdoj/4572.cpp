//hdu 4572 Bottles Arrangement
//http://acm.hdu.edu.cn/showproblem.php?pid=4572
/*
 * 题意:
 * 给出M,N，表示有n个（1，2，3.。。。m）。拍成n*m的矩阵，n行m列，令任意一行的相邻差值不大于1，每一列没有相同的数。输出所有行中的最大的一行值和，令其最小
 * 思路:
 * 构造m,m-1,m-2.。。2,1，2，3.。。m的式子序列之和即可
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
using namespace std;

int n,m,ans;


int main()
{
	while(cin >> n >> m)
	{
        ans = 0;
        int d = -1;
        int t = n;
        for (int i=0;i<m/2;i++){
            ans += 2*t;
            t += d;
            if (t<1){
                d = 1;
                t = 2;
            }
            if (t>n){
                d = -1;
                t = n-1;
            }
        }
        ans += t;
        cout << ans << endl;
	}
	return 0;
}
