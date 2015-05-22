//Mutiples on a circle
//http://acm.hdu.edu.cn/showproblem.php?pid=4669
/*
 * 动态规划，dp[i][j],记录以第i个字符结尾的，模k得到j的数字的数量
 * author licatweijie
 * licatweijie@gmail.com
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

///////////////////////////////////////define///////////////////////////////////////////
#define LL long long
////////////////////////////////////////////////////////////////////////////////////////

int n,k;
int s[50010];
int le[50010];
int dp[2][202];
int pow[260002];
int ans,now,len;

int get_len(int x)
{
    int ct = 1;
    while(x/10)
        x/=10,ct++;
    return ct;
}

void init()
{
    memset(dp,0,sizeof(dp));
    now = 0;
    pow[0] = 1;
    ans=0;
    len = 0;
    int lim = n*4;
    for (int i=1;i<=lim;i++)
        pow[i] = pow[i-1]*10%k;
    for (int i=n;i>0;i--){
        now = (now+ pow[len]*s[i])%k;
        dp[0][now]++;
        len +=le[i];
    }
    ans += dp[0][0];
}

void solve()
{
    int t1 = 0,t2=1;
    for (int i=1;i<n;i++){
        memset(dp[t2],0,sizeof(dp[t2]));
        for (int j=0;j<k;j++){
            dp[t2][(j*pow[le[i]]%k+s[i])%k] += dp[t1][j];
        }
        //删去最长串
        //变换后位置
        now = (now*pow[le[i]]+s[i])%k;
        dp[t2][now]--;
        dp[t2][s[i]%k]++;

        //消除最高位
        now= ((now-pow[len]*s[i])%k+k)%k;
        ans += dp[t2][0];
        swap(t1,t2);
    }
}

int main()
{
	while(scanf("%d %d",&n,&k)!=EOF){
        for (int i=0;i<n;i++){
            scanf("%d",&s[i]);
            le[i] = get_len(s[i]);
        }

        s[n] = s[0];
        le[n] = le[0];
        init();
        solve();
		printf("%d\n",ans);
	}
	return 0;
}

