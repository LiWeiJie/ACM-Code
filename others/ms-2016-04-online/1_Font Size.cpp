// 1. Font Size
#include <iostream>
#include <cmath>

using namespace std;

#define ll long long int

const int MAXN = 1001;

int a[MAXN];


int cal_page(int s, int W, int H, int N){
	int ct = 0;
	int perline = W/s;
	for (int i=0; i<N; i++)
	{
		int line = a[i]/perline + (a[i] % perline !=0);
		ct += line;
	}
	int perp = H/s;
	ct = ct/perp + ( ct % perp != 0);
	return ct;
}


int main() {
	
	int Task;

	ll P, H, W, N;
	int sum;

	while(cin >> Task)
	{
		while(Task--) 
		{
			sum = 0;
			cin >> N >> P >> W >> H;
			for (int i=0; i<N; i++)
			{
				cin >> a[i];
			}
			int mid = min(W,H);
			while( cal_page(mid, W, H, N) > P) mid--;
			cout << mid << endl;
		}
	}
}