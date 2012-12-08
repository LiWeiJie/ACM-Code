//zoj 1003 Crashing Balloon 
// 没什么好说的，dfs分解分数。
#include<iostream>
using namespace std;
//z是2-100的可使用数，x,y是选手分数，看最后是否能都分解到1
bool backup(int x,int y,int z)
{
	if (x==1 && y==1) return true;
	if (z>100 || (z>x && z>y)) return false;
	if (x%z==0) if (backup(x/z,y,z+1)) return true;
	if (y%z==0) if (backup(x,y/z,z+1)) return true;
	if (backup(x,y,z+1)) return true;
	else return false;
}
int main()
{
	int a,b,winner;
	while (cin >> a >>b)
	{
	
		int z;
		if (b>a) 
		{
			z=a;
			a=b;
			b=z;
		}
		//先判断分数小的是否合法，再去质疑分数高的合法
		if (backup(b,1,2) )
		if (backup(a,b,2)) winner = a ;
		else winner = b ;
		else winner = a ;

		cout << winner <<endl;

   
	}
	return 0;
}