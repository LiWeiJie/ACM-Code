/*
    ID:apprent2
    PROG:packrec
    LANG:C++
*/


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
    nt.q = max(b.q,c.q) ;
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
    int l, r;
    r = b.q+d.q;
    l = a.q+c.q;
    nt.q = max(r,l);
    r = max(b.p,d.p);
    l = max(a.p,c.p);
    nt.p = l+r;
    if ( c.p<a.p && b.p<d.p)
    {
        int tmp;
        if (a.q<b.q)
        {
            tmp = a.p-c.p;
            tmp = min(tmp,d.p-b.p);
            nt.p =nt.p-2*tmp;
        }
    }

    if (nt.q<nt.p) swap(nt.p,nt.q);
    ans.push(nt);

}




int main()
{
//    freopen("packrec.in","r",stdin);
//    freopen("packrec.out","w",stdout);
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
        for (int ap=0;ap<2;ap++)
        {
            swap(g[i].p,g[i].q);

            for (int j=0;j<4;j++)
            {
                while(f[j]) j++;
                if (j>3) break;
                f[j] = true;
                for (int bp=0;bp<2;bp++)
                {
                    swap(g[j].p,g[j].q);
                    for (int x=0;x<4;x++)
                    {
                        while(f[x]) x++;
                        if (x>3) break;
                        f[x] = true;
                        for (int cp=0;cp<2;cp++)
                        {
                            swap(g[x].p,g[x].q);
                            for (int y=0;y<4;y++)
                            {
                                while(f[y]) y++;
                                if (y>3) break;
                                for (int dp=0;dp<2;dp++)
                                {
                                    swap(g[y].p,g[y].q);
                                    ty1(g[i],g[j],g[x],g[y]);
                //                    NT no = ans.top();
                                    ty2(g[i],g[j],g[x],g[y]);
                //                    no = ans.top();
                                    ty3(g[i],g[j],g[x],g[y]);
                //                    no = ans.top();
                                    ty4(g[i],g[j],g[x],g[y]);

                //                    ty5(g[i],g[j],g[x],g[y]);
                                    ty5(g[i],g[j],g[x],g[y]);
                //                    if (ans.size())
                //                    {
                //
                //                        if (no.p==5 && no.q == 9)
                //                        {
                //                            no.p = 0;
                //                            no.q = 0;
                //                        }
                //                    }
                                }



                            }
                        }
                        f[x] = false;
                    }

                }
                f[j] = false;
            }
        }

		f[i] = false;
    }
    int maxn;
    NT tmp = ans.top();
    maxn = tmp.p*tmp.q;
    printf("%d\n",maxn);
    printf("%d %d\n",tmp.p,tmp.q);
    NT temp = ans.top();
//    while(ans.size())
//    {
//        NT temp = ans.top();
//        printf("%d %d\n",temp.p,temp.q);
//        ans.pop();
//    }
    while(temp.p*temp.q == maxn)
    {

        if (temp.p!=tmp.p||temp.q!=tmp.q)
        {
            tmp = ans.top();
            printf("%d %d\n",tmp.p,tmp.q);
        }

        ans.pop();
        if (ans.size()>0)
        {
            temp = ans.top();
        }
        else
            break;
    }
    return 0;
}
