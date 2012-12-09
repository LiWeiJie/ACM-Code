#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100000
#define COLORNUMS 36
struct seg_tree
{
    int color;
    int mark;
};
seg_tree segtree[4*MAXN];
bool colors[COLORNUMS];
void init(int n)
{
    n = n*2+2;
    for (int i = 0 ; i<=n;i++){
        segtree[i].color =1;
        segtree[i].mark =0;
    }
}

void modify(int pos,int l,int r,int tl,int tr,int color){
    if (l>r) return;
    if (tl<=l&&r<=tr){
        segtree[pos].color = color;
        segtree[pos].mark = color;
    }else {
        segtree[pos].color = 0;
        int mid = (l+r)/2;
        if (segtree[pos].mark!=0){
            segtree[pos*2+1].color = segtree[pos].mark;
            segtree[pos*2+1].mark = segtree[pos].mark;
            segtree[pos*2+2].color = segtree[pos].mark;
            segtree[pos*2+2].mark = segtree[pos].mark;
            segtree[pos].mark = 0;
        }
        if (mid>=tl){
            modify(pos*2+1,l,mid,tl,tr,color);
        }
        if (mid+1<=tr){
            modify(pos*2+2,mid+1,r,tl,tr,color);
        }
    }
}

void query(int pos,int l,int r,int tl,int tr){
    if (l>r) return;
    if (segtree[pos].color!=0||l==r){
        colors[segtree[pos].color] = true;
        return;
    }else{
        int mid = (l+r)/2;
        if (segtree[pos].mark!=0){
            segtree[pos*2+1].color = segtree[pos].mark;
            segtree[pos*2+1].mark = segtree[pos].mark;
            segtree[pos*2+2].color = segtree[pos].mark;
            segtree[pos*2+2].mark = segtree[pos].mark;
            segtree[pos].mark = 0;
        }
        if (mid>=tl){
            query(pos*2+1,l,mid,tl,tr);
        }
        if (mid+1<=tr){
            query(pos*2+2,mid+1,r,tl,tr);
        }
    }
    return;
}

int main()
{
    int l,t,o;
    while(scanf("%d %d %d",&l,&t,&o)!=EOF){
        char command;
        int a,b,c;
        init(l);
        memset(colors,false,sizeof(colors));
        int diff ;
        while(o--){
            do{scanf("%c",&command);}while(command=='\n');
            if (command=='C') {
                scanf("%d %d %d",&a,&b,&c);
                modify(0,1,l,a,b,c);
            }else{
                scanf("%d %d",&a,&b);
                query(0,1,l,a,b);
                diff = 0;
                for (int i=1;i<=t;i++)
                    if (colors[i]) diff++;
                printf("%d\n",diff);
                memset(colors,false,sizeof(colors));
            }
        }
    }
    return 0;
}

