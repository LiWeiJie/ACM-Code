#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
//#include <iostream>
//#include <fstream>

using namespace std;

#define N 512020

//int next[256]   ;
//
//void getnext(string s)
//{
//    int len = s.size();
//    int i,j;
//    i=0;j=-1;next[0]=-1;
//    while(i<len)
//    {
//    if(j==-1||s[i]==s[j])
//    {
//    i++;j++;
//    if(s[i]==s[j]) next[i]=next[j];
//    else next[i]=j;
//    }
//    else j=next[j];
//    }
//}
//
//int kmp(string t,string s,int i)
//{
//    int len1 = t.size();
//    int j;
//    j=0;
//    while(i<len1)
//    {
//        if(j==-1||t[i]==s[j])
//        {
//        i++;j++;
//        if(j>=len2) return i-1;
//        }
//        else j=next[j];
//    }
//    return -1;
//}

char a[500],b[N],cp[N];

int main()
{
//    freopen("/home/ymwm/1","r",stdin);
    while(scanf("%s%s",a,b)!=EOF)
    {
        long long ma=0,mb = 0;

		int f=0;
		int ans =0;
		long long contant = 1;
//		getnext(a);
		int len2,len1;
		len1 = strlen(a);
//		len2 = strlen(b);
		int l=1;
		for (int i=0;b[i]!=0;i++)
		{
		    cp[l-1] = b[i];
            if(l>=len1)
            {
                cp[l] = 0;
                if(strcmp(cp+l-len1,a)==0)
                {
                    l -= len1;
                    ans++;
                }
            }
            l++;
		}
		printf("%d\n",ans);
    }
    return 0;
}
