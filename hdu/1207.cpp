//hdu 1207 汉诺塔II
//http://acm.hdu.edu.cn/showproblem.php?pid=1207
/*
 * 题意:
 * 中文自己看着办
 * 算了，还是说一下吧，就是一个四柱汉诺塔，问x个盘子搬到C柱最小多少步
 * 思路:
 * 额，找规律。
 * 1个是1次，2个是3次，3个是5次，4个时8次
 * 递增关系为1,2,2,4,4,4,8,8,8,8.....
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#define N 70
using namespace std;

int ans[N];
int bina[31] ;
int n;

int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);


    ans[0] = 0;
    int tmp = 1;
    bina[0] = tmp;
    for (int i=1;i<15;i++){
        bina[i] = bina[i-1]<<1;
    }
    int i = 1;
    while(i<=64){
        for (int j=0;j<tmp;j++){
            ans[i] = ans[i-1] + bina[tmp-1];
//            printf("%d %d\n",tmp ,ans[i]);
            i++;
        }
        tmp++;
    }
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",ans[n]);
    }
	return 0;
}
