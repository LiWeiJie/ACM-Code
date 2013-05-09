//zoj 2734 Exchange Cards
/*
很简单很简单的dfs，直接暴力dfs就可以了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 10000

struct Card
{
    int value;
    int num;
};


 Card cards[MAXN];
int n,m;
int sum;

bool cmp(const Card&a ,const Card&b){
    return a.value>b.value;
}

void dfs(int pos,int target)
{
    if (target<0) return;
    if (target==0){
        sum++;
        return;
    }
    if (pos>=m) return;
    int dec = target-cards[pos].value*cards[pos].num;
    for (int i=cards[pos].num;i>=0;i--){
        dfs(pos+1,dec);
        dec += cards[pos].value;
    }
}

int main()
{
    int ct =0;
    while(scanf("%d %d",&n,&m)!=EOF){
        if (ct==0)
            ct++;
        else
            printf("\n");
        for (int i=0;i<m;i++){
            scanf("%d %d",&cards[i].value,&cards[i].num);
        }
        sort(cards,cards+m,cmp);
        sum = 0;
        dfs(0,n);
        printf("%d\n",sum);
    }
    return 0;
}
