//ural 1740 Deer is Better!
//http://acm.timus.ru/problem.aspx?space=1&num=1740
/*
 * 题意:
 * 略
 * 思路:
 * l/k之后的结果，向上取整*h得到maximal time ， 向下取整*h得minimal time
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    int l,k,h;

	while(cin >> l >> k>> h){
        int maxi = 0,mini = 0;
        if (l%k==0){
            maxi = l/k*h;
            mini = l/k*h;
        } else {
            maxi = (l/k +1 ) *h;
            mini = (l/k) *h;
        }
        cout << mini << ".000000 " << maxi << ".000000 " << endl;
	}

	return 0;
}
