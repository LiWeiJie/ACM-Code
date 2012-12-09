//zoj 1037 Gridland 水题，只有行和列都是单数时才需要走斜线
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	int a,b;
	double sum;
	int no;
	while (cin >> no )
	{
		for (int i=0; i<no ; i++)
		{
			cin >> a >> b ;
			sum = a*b;
			if (a%2!=0 && b%2!=0) 
				sum = sum - 1 +sqrt(2);
			cout << "Scenario #" << i+1 << ":" << endl;
			cout << setiosflags(ios::fixed) << setprecision(2) << (double)sum << endl;
			cout << endl;
		}
	}
	return 0;
}
