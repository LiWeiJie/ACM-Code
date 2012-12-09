/*
    四分树的题目
    利用dfs建立一棵四分树。
    然后bfs遍历四分树。
    最后把遍历结果转换为十六进制输出。
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf

using namespace std;

#define N 550

struct quad_tree
{
    char value[3];
    quad_tree* child[4];
};

int store[N][N];

bool cmp(quad_tree* lhs,quad_tree *rhs)
{
    if (lhs->value[0]=='1'||rhs->value[0]=='1') return false;
    FOR(i,0,2)
        if(lhs->value[i]!=rhs->value[i])
            return false;
    return true;
}

quad_tree* dfs(int r,int c,int s)
{
    quad_tree* current = new quad_tree();
    if (s==1)
    {
        current->value[0] = '0';
        current->value[1] = '0'+store[r][c];
        current->value[2] = '\0';
        return current;
    }
    s /=2;
    current->child[0] = dfs(r,c,s);
    current->child[1] = dfs(r,c+s,s);
    current->child[2] = dfs(r+s,c,s);
    current->child[3] = dfs(r+s,c+s,s);
    bool f = true;
    FOR(i,1,4)
    {
        if (!cmp(current->child[0],current->child[i]))
        {
            f =false;
            break;
        }
    }
    if (f) {
        current->value[0] = '0';
        current->value[1] = current->child[0]->value[1];
        current->value[2] = '\0';
        FOR(i,0,4)
        {
            delete current->child[i];
            current->child[i]=0;
        }
    }
    else
    {
        current->value[0] = '1';
        current->value[1] = '\0';
    }
    return current;
}

queue<quad_tree*> bfslist;
char result[N*N];
int ct;
char hexout[N*N];

void bfs(quad_tree* root)
{
    bfslist.push(root);
    quad_tree *tmp;
    while(!bfslist.empty())
    {
        tmp = bfslist.front();
        bfslist.pop();
        if (tmp->value[0]=='1')
        {
            result[ct++] = '1';
            FOR(i,0,4)
            {
                bfslist.push(tmp->child[i]);
            }
        }
        else
        {
            result[ct++] = '0';
            result[ct++] = tmp->value[1];
        }
    }
}

int main()
{
    int n,m;
    char hex []= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    sf("%d",&n);
    while(n--)
    {
        sf("%d",&m);
        FOR(i,0,m)
            FOR(j,0,m)
            {
                sf("%d",&store[i][j]);
            }
        quad_tree *root;
        root=dfs(0,0,m);
        while(!bfslist.empty()) bfslist.pop();
        ct = 0;
        bfs(root);
        //四位二进制数为一个十六进制，记录能否组成一个十六进制
        int chex = 0;
        //记录二进制转十进制累计值
        int dec = 0;
        //记录十六进制输出的数组规模
        int ch = 0;

        for(int i=ct-1;i>=0;i--)
        {
            chex++;
            dec = dec+ ((result[i]-'0') <<(chex-1));
            if (chex==4)
            {
                hexout[ch++] = hex[dec];
                dec = 0 ;
                chex = 0 ;
            }
        }
        if (chex>0)
        {
            hexout[ch++] = hex[dec];
        }
        for(int i=ch-1;i>=0;i--)
        {
            pf("%c",hexout[i]);
        }
        pf("\n");
    }
    return 0;
}
