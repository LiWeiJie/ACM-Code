//ZOJ 1204 Additive equations
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 33
int s[MAXN];
int visit[MAXN];
int ct;
int n;
bool is_out;
//td目标因子数，cd现在因子数，pos现在位置，sum现在总和
void dfs(int td,int cd,int pos,int sum)
{
   if (td==cd){
       for (int i=pos;i<n;i++){
           if (sum==s[i]){
               is_out=true;
               printf("%d", visit[0]);
               for (int j=1;j<ct;j++){
                   printf("+%d", visit[j]);
               }
               printf("=%d\n", s[i]);
               //很诡异的一个剪枝，我注释掉之后竟然还快乐10ms，估计是服务器问题
               break;
           }
       }
       return;
   }
   for (int i=pos;i<n+cd-td;i++){
       //最关键的一个剪枝，从10001ms超时变成70ms
       if (sum+s[i]>s[n-1]) return;
       visit[ct++] = s[i];
       dfs(td,cd+1,i+1,sum+s[i]);
       ct--;
   }
   return;
}

int main()
{
   int t;
   scanf("%d",&t);
   while(t--){
       scanf("%d",&n);
       is_out=false;
       ct = 0;
       for (int i=0;i<n;i++){
           scanf("%d",&s[i]);
       }
       sort(s,s+n);
       //目的因子数
       for (int i=2;i<n;i++){
           dfs(i,0,0,0);
       }
       if (is_out==false)
           printf("Can't find any equations.\n");
       printf("\n");
   }
}