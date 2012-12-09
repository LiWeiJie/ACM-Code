//zoj 1002 Fire Net 每一个落子都会占用其可见范围内的行和列空间，那么这个空间就是此落子的花费。所以贪心，计算占用空间最小的格，take it
#include<iostream>
const int maxn=5;
char map[maxn][maxn] = { 0 };
bool canput[maxn][maxn] ={ true };
int row[maxn][maxn]={ 0 },col[maxn][maxn]={0};
using namespace std;

int calu(int i,int j,int n);

int job(int n)
{
	bool f=true;
	int min,x=0,y=0,best=0;
	while (f)
	{
		f=false;
		min=999;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (row[i][j]+col[i][j] < min && canput[i][j])
				{
					min=row[i][j]+col[i][j];
					x=i;y=j;
					f=true;
				} 
		best++;
		calu(x,y,n);
	}
	cout << best-1 <<endl;
	return 0;
}

int calu(int i,int j,int n)
{
	bool f1=true,f2=true,f3=true,f4=true;
	for (int z=0;f1 || f2|| f3||f4;z++)
	{
		if ((i+z)<n && map[i+z][j]!='X' && f1)  canput[i+z][j]=false;
		else f1=false;
		if ((i-z)>=0 && map[i-z][j]!='X' && f2)  canput[i-z][j]=false;
		else f2=false;
		if ((j+z)<n && map[i][j+z]!='X' && f3)  canput[i][j+z]=false;
		else f3=false;
		if ((j-z)>=0 && map[i][j-z]!='X' && f4)  canput[i][j-z]=false;
		else f4=false;
	}
	return 0;
}


int main()
{
	int n,sum,i;
	while (cin >> n )
	{
		if (n==0) break;
		for (i=0; i<n ; i++)
		{
			sum=0;
			map[i][n]='X';
			map[n][i]='X';
			for (int j=0; j<=n ; j++)
			{	
				if (j!=n) cin>>map[i][j];
				if (map[i][j]=='X') 
				{
					canput[i][j]=false;
					for (int z=j-1;map[i][z]!='X' && z>=0 ;  z--)
						row[i][z]=sum;
				}
				else {sum++;canput[i][j]=true;}	
			}
		}
		for (i=0;i<n ; i++)
			for (int j=0; j<n ; j++)
			{
				if (map[j][i]=='X') 
				{
					for (int z=j-1;map[z][i]!='X' && z>=0 ;  z--)
						col[z][i]=sum;
					sum=0;
				}
				else sum++;
			}
		job(n);
	}
	return 0;
}
