//ural 1939 First Seal
//http://acm.timus.ru/problem.aspx?space=1&num=1939
/*
 * 题意:
 * 小车车长l，高h，从远处以v速度驶来，此处有一闸门，高H，可以随时以x的加速度下降，当闸门开始下降时，小车可选择并仅可此时选择开始以a加速度减速，或者不降速。
 * 若无论小车如何变化，闸门肯定可以砸到小车，则输出Crash，否则输出Safe
 * 思路:
 * 考虑两种情况：
 * 1.小车不减速，则在小车距离闸门s1 = (H-h)*v/x - l的地方及其更远处的区域时开始放下闸门可以砸到小车
 * 2.小车减速。则小车停在门口
 *   此时应该是v*v = 2*a*s，即s2=v*v/2/a；则若s2>s1，则必定可以砸到小车
 * 3.值得注意的是，其实还有第三种情况，就是减速后仍被闸门砸中，但可知此区域必定在s2的左边，所以可以不用考虑
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#define LL long long
#define exp 10e-9
using namespace std;


int main()
{
	LL l,H,h,v,x,a;
    while(cin >> l >> h >> H >> v >> x >> a){
        //不刹车边界
        double unl = (double)(H-h)*v /x -l ;
        //刹车 停止边界
        double stopr = (double)v*v / 2/a;

        if ( unl < stopr+exp){
            cout << "Crash" << endl;
        } else {
            cout << "Safe" << endl;
        }

    }

	return 0;
}
