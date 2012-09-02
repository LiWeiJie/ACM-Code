/*
	ID: apprent2
	PROG: milk2
	LANG: C++
*/

#include <iostream>
#include <fstream>

const int maxn = 5000;

struct node
{
    int x;
    int y;
};


void swap(node *a,node *b)
{
    int xx,yy;
    xx = a->x;
    yy = a->y;
    a->x = b->x;
    a->y = b->y;
    b->x = xx;
    b->y = yy;
}



void QuickSort(node *d,int low,int high)
{
	if (low < high)
	{
		int down = low , up = high;
		int x = d[down].x,y = d[down].y;
		while (down < up)
		{
			while (d[up].x>=x &&(down < up)) up--;
			if ((down < up))
				swap(&d[up],&d[down++]);
			while (d[down].x<=x && (down < up) ) down++;
			if (down < up)
				swap(&d[down],&d[up--]);
		}
		QuickSort(d,low,down-1);
		QuickSort(d,down+1,high);
	}


}


using namespace std;

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n;
    cin >> n ;
    node s[maxn] ;
    for (int i=0 ; i< n ; i ++)
    {
        cin >> s[i].x >> s[i].y  ;
    }
    QuickSort(s,0,n-1);
    int min = 0,begin = s[0].x,end = s[0].y,max=end-begin;
    if (n>1) min =s[1].x-end;
    if (min<0)min = 0;
    for (int i=1 ; i<n ; i++)
    {
        if (s[i].x -end <= 0 ) {if(s[i].y>end)end = s[i].y;}
        else
        {
            if (max< (end-begin)) max = end-begin;
            if (min < (s[i].x-end) ) min = s[i].x-end;
            begin = s[i].x;
            end = s[i].y;
        }
    }
    if (max< (end-begin)) max = end-begin;
    cout << max <<" "<<min<<endl;
    return 0;
}
