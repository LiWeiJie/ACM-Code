//poj 3855 Blast the Enemy!
//http://poj.org/problem?id=3855
//求重心，直接上模板

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#define exp 1E-7
using namespace std;

struct  point { double  x, y; };


point bcenter(point pnt[], int  n){
  point p, s;
  double  tp, area = 0, tpx = 0, tpy = 0;
  p.x = pnt[0].x; p.y = pnt[0].y;
  for  (int  i = 1; i <= n; ++i) {    // point: 0 ~ n-1
    s.x = pnt[(i == n) ? 0 : i].x;
    s.y = pnt[(i == n) ? 0 : i].y;
    tp = (p.x * s.y - s.x * p.y); area += tp / 2;
    tpx += (p.x + s.x) * tp; tpy += (p.y + s.y) * tp;
    p.x = s.x; p.y = s.y;
 }
  s.x = tpx / (6 * area); s.y = tpy / (6 * area);
  return  s;
}


point points[110];

int main()
{
    int n;
    int cc = 0;
    while(cin >> n){
        if (n==0) break;
        for (int i=0;i<n;i++){
            cin >> points[i].x >> points[i].y;
        }
        point tmp;
        if (n>1){
            tmp = bcenter(points,n);
        } else {
            if (n==2){
                tmp.x = (points[0].x+points[1].x)/2;
                tmp.y = (points[0].y+points[1].y)/2;
            } else
                tmp = points[0];
        }

        cout << "Stage #" << ++cc << ": ";
        cout << setiosflags(ios::fixed);
        cout.precision(6);
        if (tmp.x==0||(fabs(tmp.x-exp)<0&&fabs(tmp.x+exp)>0)) {
            tmp.x = 0;
        }
        if (tmp.y==0||(fabs(tmp.y-exp)<0&&fabs(tmp.y+exp)>0)) {
            tmp.y = 0;
        }
        cout <<tmp.x << " " << tmp.y<< endl;

    }
    return 0;
}
