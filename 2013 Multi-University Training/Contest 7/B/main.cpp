//Building Fence
//http://acm.hdu.edu.cn/showproblem.php?pid=4667
/*
 *
 * author licatweijie
 * licatweijie@gmail.com
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

///////////////////////////////////////define///////////////////////////////////////////
#define LL long long
#define N 500000
////////////////////////////////////////////////////////////////////////////////////////
struct point
{
    double x, y;
};
bool mult(point sp, point ep, point op)
{
    return (sp.x - op.x) * (ep.y - op.y)
           >= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[], int n, point res[])
{
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0;
    res[0] = pnt[0];
    if (n == 1) return 1;
    res[1] = pnt[1];
    if (n == 2) return 2;
    res[2] = pnt[2];
    for (i = 2; i < n; i++)
    {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--)
    {

        while (top!=len && mult(pnt[i], res[top],
                                res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top;
// 返回凸包中点的个数
}


point raw[N],ret[N];
const double pi = 2*acos(-1.0);

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int n,m;

	while(scanf("%d %d",&n,&m)!=EOF){

        double x,y,r;
        int ct = 0;
        memset(raw,0,sizeof(raw));
        for (int i=0;i<n;i++){
            scanf("%lf %lf %lf",&x,&y,&r);
            for (double j=0;j<pi;j+=0.003){
                raw[ct].x=x+r*cos(j);
                raw[ct++].y=y+r*sin(j);
            }
        }
        double x0,y0,x1,x2,y1,y2;
        for (int i=0;i<m;i++){
            scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2);
            raw[ct].x = x0;
            raw[ct++].y = y0;
            raw[ct].x = x1;
            raw[ct++].y = y1;
            raw[ct].x = x2;
            raw[ct++].y = y2;
            //原来是以下这种方式读写的，被坑死了，一直WA
//            scanf("%lf%lf",&raw[ct].x,&raw[ct++].y);
//            scanf("%lf%lf",&raw[ct].x,&raw[ct++].y);
//            scanf("%lf%lf",&raw[ct].x,&raw[ct++].y);
        }
//        printf("#%d\n",ct);
        double ans=0;
        memset(ret,0,sizeof(ret));
        int re = graham(raw,ct,ret);
//        re--;
        for (int i=0;i<re;i++){
            ans+= dist(ret[i],ret[i+1]);
        }
        ans += dist(ret[0],ret[re]);
//        printf("%lf   %lf\n",ret[re-1].x,ret[re-1].y);
//        printf("%lf   %lf\n",ret[re].x,ret[re].y);


		printf("%.5lf\n",ans);
	}
	return 0;
}
