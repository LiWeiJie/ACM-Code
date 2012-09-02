//#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <iostream>
using namespace std;
#define maxsize 10000

struct hp
{
    int len;
    int s[maxsize+1];
};

void input(hp &a,string str)
{
    int i;
    while(str[0]=='0' && str.size()!=1)
       str.erase(0,1);
    a.len=(int)str.size();
    for(i=1;i<=a.len;++i)
       a.s[i]=str[a.len-i]-48;
    for (i=a.len+1;i<=maxsize;++i)
       a.s[i]=0;
}

void print(const hp &y)
{
int i;
for(i=y.len;i>=1;i--)
    cout<<y.s[i];
cout<<endl;
}

void pluss(const hp &a,const hp &b,hp &c)
{
int i,len;
for(i=1;i<=maxsize;i++) c.s[i]=0;
if(a.len>b.len) len=a.len;
else len=b.len;
for(i=1;i<=len;i++)
   {
   c.s[i]+=a.s[i]+b.s[i];
    if(c.s[i]>=10)
      {
      c.s[i]-=10;
      c.s[i+1]++;
      }
   }
if(c.s[len+1]>0) len++;
   c.len=len;
}

void multiply(const hp &a,int b,hp &c)
{
int i,len;
for(i=1;i<=maxsize;i++) c.s[i]=0;
len=a.len;
for(i=1;i<=len;i++)
   {
   c.s[i]+=a.s[i]*b;
   c.s[i+1]+=c.s[i]/10;
   c.s[i]%=10;
   }
len++;
while(c.s[len]>=10)
   {
   c.s[len+1]+=c.s[len]/10;
   c.s[len]%=10;
   len++;
   }
while(len>1&&c.s[len]==0) len--;
c.len=len;
}

int main()
{
    int n,m;
//    string n,m;

    while (cin >> n >> m)
    {
		hp cn,cm,tmp,tmpcn,tmpcm;
		cn.len = 1;
		cn.s[1] = 1;
		cm.len = 1;
		cm.s[1] = 0;

		for (int i=1;i<m;i++)
		{
		    tmp.len = cm.len;
		    for (int j=1;j<=tmp.len;j++)
		    {
		        tmp.s[j] = cm.s[j];
		    }
//            tmp = cm;
		    multiply(cn,n,tmpcn);
		    multiply(cm,2,tmpcm);
		    pluss(tmpcm,tmpcn,cm);
		    cn.len = tmp.len;
		    for (int j=1;j<=cn.len;j++)
		    {
		        cn.s[j] = tmp.s[j];
		    }
//            cn = tmp;
		}
//        input(cn,n);
//        multiply(cn,9,tmpcn);

//		cout << cm.len<< endl;
        if (m==0) cout << 1<< endl;
        else
		print(cm);
    }
    return 0;
}
