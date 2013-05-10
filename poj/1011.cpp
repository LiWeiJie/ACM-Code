//poj 1011 Sticks
/*
很值得一做的搜索题。
经历了WA->TLE->WA->TLE->WA->AC的过程终于做出来了。
算法是dfs+剪枝+回溯。
最重要的就是剪枝了，dfs和回溯很快就可以写出来。
有以下几个点可以剪的：（原sticks，没有被cut时候称呼为木棒）
1.最小的原木棍长度>=sticks长度中的最大值
2.下一个尝试的木棍长度应当可以整除sticks长度之和。
3.dfs中当还有一组木棒需要配对，而当前一组已经配对完时就可以返回true了，因为假设可以配成n组，每组长度为k，k*n=sum(sticks)，那么配了n-1组k长度的木棒，剩下的sticks和必定等于k。
4.对sticks长度降序dfs，当发现sticks的当前长度和上一长度相等，而上一长度没有被使用，则当前长度也不需要递归使用进去。
5.当前sticks长度比剩余配对值还大，就直接返回false。
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 100

int sticks[N];
bool used[N];
int n;
int len;

bool dfs(int pos,int value, int res){
    if (value==0){
        //当前的value为0，肯定也组成一根木棒了，而剩下的数值肯定也组成一根木棒
        if (res==2)
            return true;
        pos = n;
        while(used[pos])pos--;
        if (pos>0){
            used[pos] = 1;
            if (dfs(pos-1,len-sticks[pos],res-1)){
                return true;
            }
            used[pos] = 0;
            return false;

        }
        return false;
    }
    else{
        for (;pos>0;pos--){
            if (used[pos]||sticks[pos]>value)continue;
            if (pos<n&&sticks[pos]==sticks[pos+1]&&(!used[pos+1])) continue;
            used[pos] = 1;

            if (dfs(pos,value-sticks[pos],res)){
                return true;
            }
            used[pos] = 0;

        }
        return false;
    }


}

int main()
{

    while(scanf("%d" ,&n)){
        if (n==0) break;
        int sum = 0;
        for (int i=1;i<=n;i++){
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
        }
        sort(sticks+1,sticks+1+n);
        len = sticks[n];
        bool f = true;
        int gro = sum/len;
        len = sum/gro;
        for (;len<=sum/2;len = sum/gro){
            gro--;
            if (sum%len==0) {
                used[n] = 1;
                if (dfs(n,len-sticks[n],sum/len)){
                    f = false;
                    break;
                }
            }

        }
        if (!f) printf("%d\n",len);
        else printf("%d\n",sum);
        memset(used,0,sizeof(used));
    }
    return 0;
}
