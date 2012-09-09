#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;







struct NT
{
    int p;
    int q;
    bool
    operator<(const NT &b)const
    {
        return(p*q>b.p*b.q)||((p*q==b.p*b.q)&&(p>b.p));
    }
};
priority_queue<NT> ans;
void ty1(NT a,NT b,NT c,NT d)
{
    NT nt;
    int tmp;
    tmp = max(a.q,b.q);
    tmp = max(tmp,c.q);
    tmp = max(tmp,d.q);
    nt.q = tmp;
    nt.p = a.p+b.p+c.p+d.p;
    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);
}

void ty2(NT a,NT b,NT c,NT d)
{
    NT nt;
    nt.p = b.p+c.p+d.p;
    nt.p = max(nt.p,a.q);
    nt.q = b.q ;
    nt.q = max(nt.q,c.q);
    nt.q = max(nt.q,d.q);
    nt.q += a.p;
    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);
}

void ty3(NT a,NT b,NT c,NT d)
{
    NT nt;
    nt.p = b.p+c.p;
    nt.p = max(nt.p,a.q);
    nt.p += d.p;
    nt.q = max(b.q,c.q);
    nt.q += a.p;
    nt.q = max(nt.q,d.q);
    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);
}

void ty4(NT a,NT b,NT c,NT d)
{
    NT nt;
    nt.p = a.p+max(b.p,c.p) +d.p;
    nt.q = b.q+c.q;
    nt.q = max(nt.q,a.q);
    nt.q = max(nt.q,d.q);
    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);
}

void ty5(NT a,NT b,NT c,NT d)
{
    NT nt;
    nt.p = max(a.p,b.p)+d.p;
    int cd = c.p+d.q,ab = a.q+b.q;
    if (ab>d.q)
    {
        nt.p = max(nt.p,c.q+a.p);
    }
    else
    {
        nt.p = max(nt.p,c.q);
    }
    nt.q = max(a.q+b.q,c.p+d.q);
    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);
}

void ty6(NT a,NT b,NT c,NT d)
{
    NT nt;
    nt.p = d.q;
    int cd = c.p+d.q,ab = a.p+max(b.q,c.p);
    nt.p = max(nt.p,ab);
    nt.q = max(c.q+b.p,a.q);
    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);
}

int main()
{
    NT g[4];
    bool f[5];
    memset(f,0,sizeof(f));
    f[4] = true;
    for (int i=0;i<4;i++)
    {
        scanf("%d %d",&g[i].p,&g[i].q);
        if (g[i].p>g[i].q)
            swap(g[i].p,g[i].q);
    }

    for (int i=0;i<4;i++)
    {
        while(f[i]) i++;
        if (i>3) break;
        f[i] = true;
		for (int j=0;j<4;j++)
		{
		    while(f[j]) j++;
            if (j>3) break;
            f[j] = true;
		    for (int x=0;x<4;x++)
		    {
		        while(f[x]) x++;
                if (x>3) break;
                f[x] = true;
		        for (int y=0;y<4;y++)
		        {
		            while(f[y]) y++;
                    if (y>3) break;


                    ty1(g[i],g[j],g[x],g[y]);
                    NT no = ans.top();
                    ty2(g[i],g[j],g[x],g[y]);
                    no = ans.top();
                    ty3(g[i],g[j],g[x],g[y]);
                    no = ans.top();
                    ty4(g[i],g[j],g[x],g[y]);
                    no = ans.top();
//                    ty5(g[i],g[j],g[x],g[y]);
                    ty6(g[i],g[j],g[x],g[y]);
                    if (ans.size())
                    {

                        if (no.p==5 && no.q == 9)
                        {
                            no.p = 0;
                            no.q = 0;
                        }
                    }


		        }
		        f[x] = false;
		    }
		    f[j] = false;
		}
		f[i] = false;
    }
    int maxn;
    NT tmp = ans.top();
    maxn = tmp.p*tmp.q;
    printf("%d\n",maxn);
    while(tmp.p*tmp.q == maxn)
    {
        printf("%d %d\n",tmp.p,tmp.q);
        ans.pop();
        if (ans.size()>0)
        {
            tmp = ans.top();
        }
        else
            break;
    }
    return 0;
}
