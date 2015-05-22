//#include <stdio.h>
//#include <algorithm>
//#include <iomanip>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <list>
//
//using namespace std;
////
////const int N = 2001;
////int data[N][N],B[N];
////void NGetM(int m,int n)
////{
////    int min,i,j;
////    data[0][0] = 1;
////    for (i = 1;i<=m; ++i) data[i][0] = 0;
////    for (i=0;i<=m;++i) data[i][i+1] = 0;
////    for( i = 1; i <= m; ++i ){
////    if( i < n ) min = i;
////    else min = n;
////    for( j = 1; j <= min; ++j ){
////    data[i][j] = (j*data[i-1][j] + data[i-1][j-1]);
////}
////}
////}
////void compute(int m){// b[i]:Bell 数
////NGetM(m, m);
////memset(B, 0, sizeof(B));
////int i, j;
////for( i=1; i <= m; ++i )
////for( j=0; j <= i; ++j ) B[i] += data[i][j];
////}
//
//#define N 50000
//
//int main()
//{
//    int g[N][11];
//
//    int n,k;
//
//
//    while (scanf("%d %d",&n,&k)!=EOF)
//    {
//        memset(g,0,sizeof(g));
//        for (int i=0;i<11;i++)
//        {
//            g[i][i] = 1;
//        }
//		for (int i=1;i<=k;i++)
//            for (int j=1;j<=i;j++)
//                g[i][j] = (g[i-1][j-1]%2007 + (j* g[i-1][j])%2007)%2007;
//        int x = k+1;
//        for (int i=k+1;i<=n;i++)
//        {
//            if (x>=N)
//            {
//                if (k-2>=0)
//                g[0][k-2] = g[x-1][k-2];
//                g[0][k-1] = g[x-1][k-1];
//                g[0][k]= g[x-1][k];
//                x=1;
//            }
//            if (k==1) g[x][k-1]=0;
//            else  g[x][k-1] = (g[x-1][k-2]%2007 + ((k-1) * g[x-1][k-1])%2007)%2007 ;
//            g[x][k] = (g[x-1][k-1]%2007 + (k*g[x-1][k])%2007)%2007;
//            x++;
//        }
//        printf("%d\n",g[x-1][k]);
//    }
//    return 0;
//}
//

#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;


#define big long long
big c;
big com(int n,int r)
{
    if(n-r>r ) r = n-r;
    int i,j,s = 1;
    for (i = 0,j=1;i<r;++i)
    {
        s*=(n-i);
        for (;j<=r && s%j==0;++j) s/=j;
    }
    return s;
}


#define LL long long
LL mul(LL a,LL b,LL c)  //计算a*b%c,将b按二进制分解
{
	LL res=0;
	for(;b;b>>=1)
	{
		if(b&1)  //末位为1
		{
			res+=a;
			while(res>=c)
			res-=c;
		}
		a<<=1;
		while(a>=c)
		a-=c;
	}
	return res;
}
LL qmod(LL a,LL b,LL c) //幂乘,将b分解为2进制
{
	LL res=1;
	for(;b;b>>=1)
	{
		if(b&1)
		res=mul(a,res,c);
		a=mul(a,a,c);
	}
	return res;
}


LL Cal(LL x,LL y)
{
	LL ans=1,t=y;
	while(t--)
	{
		ans*=x,x--;
		while((ans%y==0)&&y>1)
			ans/=y,y--;
	}
	return ans;
}



int main()
{

    int n,k;


    while (scanf("%d %d",&n,&k)!=EOF)
    {
        big jie=1;
        int i;
		for(i=1;i<=k;i++)
			jie*=i;
        c = jie*2007;
		big ans=0;
		int f=1;
		for(i=0;i<=k-1;i++)
		{
		    big tmp = qmod(k-i,n,c);
			ans+=f*com(k,i)*tmp;
			ans =  (ans%c+c)%c;
			f=-f;
		}
		ans = ans/jie;
        printf("%lld\n",ans);
    }
    return 0;
}

