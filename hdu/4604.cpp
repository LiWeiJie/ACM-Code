//hdu 4604 Deque
//http://acm.hdu.edu.cn/showproblem.php?pid=4604
/*
 * 题意:
 * 一个序列A，一个双端队列，从A的开头到结尾，可以选择放进队列的头或者尾或者抛弃，令双端队列内部元素为非递增的
 * 思路:
 * 从每一个位置Ai开始查找最长非递增子序列和最长非递减子序列，计算他们的和-Ai重复出现的次数 ，取最大值输出即可
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100001
using namespace std;

int t,n,s[N];
int c_up[N],w_up[N];
int c_down[N],w_down[N];

void LIS(int ct[],int weight[] ){
    vector<int> last;
    last.clear();
    last.push_back(s[n]);
    ct[n] = 1;
    weight[n] = 1;
    vector<int>::iterator iter;
    for (int i=n-1;i>=1;i--){
        int sz = last.size();
        if (last[sz-1]<s[i]){
            last.push_back(s[i]);
            ct[i] = sz+1;
            weight[i] = 1;
        } else {
            if (last[sz-1]==s[i]){
//                iter = upper_bound(last.begin(),last.end(),s[i]);
//                ct[i] = iter-last.begin()+1;
                ct[i] = sz+1;
                last.push_back(s[i]);
                pair<vector<int>::iterator , vector<int>::iterator > bound;
                bound = equal_range(last.begin(),last.end(),s[i]);
                weight[i] = bound.second-bound.first;
            } else {
                iter = upper_bound(last.begin(),last.end(),s[i]);
                ct[i] = iter-last.begin()+1;
                *iter = s[i];
                pair<vector<int>::iterator , vector<int>::iterator > bound;
                bound = equal_range(last.begin(),last.end(),s[i]);
                weight[i] = bound.second-bound.first;
            }
        }
    }
}




int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> s[i];
        }
        LIS(c_up,w_up);
        for (int i=1;i<=n;i++){
            s[i] *= -1;
        }
        LIS(c_down,w_down);
        int ans = 0;
        for (int i=1;i<=n;i++){
            ans = max(ans, c_down[i]+c_up[i]- min(w_up[i],w_down[i]));
        }
        cout << ans << endl;
    }
	return 0;
}
