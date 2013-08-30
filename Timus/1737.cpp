//ural 1737 Mnemonics and Palindromes 3
//http://acm.timus.ru/problem.aspx?space=1&num=1737
/*
 * 题意:
 * 由a,b,c组成长为n的字符串，令不存在回文，输入n，输出所有符合条件的字符串
 * 思路:
 * 演算一下可知，由于只有3个可用字符且不存在回文，所以只需要知道2个字符，则后面的所有字符都是固定的，而两个字符只能组合为6个，以3为循环节形式记录，则如s数组所示，注意特判n==1的情况
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
string s[] = {"abc","acb","bac","bca","cab","cba"};

int main()
{
	//	freopen("in","r",stdin);
	//	freopen("out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n;
	while(cin >> n){
		if (n==1){
			cout << "a\nb\nc\n";
			continue;
		}
		if (6*n>100000)
			cout << "TOO LONG" << endl;
		else {
			for (int i=0;i<6;i++){
				int cn = n;
				while(cn>=3){
					cout << s[i] ;
					cn-=3;
				}
				for (int j=0;j<cn;j++){
					cout << s[i][j];
				}
				cout << endl;
			}
		}

	}
	return 0;
}

