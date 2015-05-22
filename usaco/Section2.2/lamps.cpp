//Party Lamps
/*
PROG:lamps
LANG:C++
ID:apprent2
这题略巧妙，通过分析按钮可以发现，每个按钮的按动可以抽象成按动一次或者不按，而按钮2,3,4的操作是互相不可替代的，而1则可以通过2,3的组合实现。并且1+2=3,1+3=2，2+3=1 ，每两个组合就变成第三个，所以这个变换可以用于对按钮操作数c的奇偶变换。这样子当c>=3的时候，2,3,4的操作任意组合就代表所有最终状态了。而当c==1时，则考虑各个按钮一次的效果，当c==2时，考虑什么都不做，只做2或3或4， 和2,3,4全做的效果。
*/
#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>

#define N 101

using namespace std;

int n,c,ct;

int check_yes[N],check_no[N];
bitset<N> o[4];
bitset<N> checked(0);
string ani[N];

//检查是否符合答案标准
bool check()
{
    int i=0;
    while (check_yes[i]!=-1){
        if (checked.test(check_yes[i]-1)==false){
            return false;
        }
        i++;
    }
    i=0;
    while (check_no[i]!=-1){
        if (checked.test(check_no[i]-1)==true){
            return false;
        }
        i++;
    }
    string tmp =checked.to_string().substr(N-n,n);
    reverse(tmp.begin(),tmp.end());
    //
    ani[ct++] = tmp;
    return true;
}

//初始化
void init()
{
    ct = 0;
    for (int i=0;i<4;i++){
        o[i].reset();
    }
    //第二个按钮
    for (int i=0;i<n;i+=2){
        o[1].set(i);
    }
    //第三个按钮
    for (int i=1;i<n;i+=2){
        o[2].set(i);
    }
    //第四个按钮
    for (int i=0;i<n;i+=3){
        o[3].set(i);
    }
}

void dfs(int op,int rc)
{
    if (op>3||rc<1) {
        check();
        return;
    }
    dfs(op+1,rc);
    checked ^= o[op];
    dfs(op+1,rc-1);
    checked ^= o[op];
}

int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&c);
    for (int i=0;i<n;i++){
        scanf("%d",&check_yes[i]);
        if (check_yes[i]==-1) break;
    }
    for (int i=0;i<n;i++){
        scanf("%d",&check_no[i]);
        if (check_no[i]==-1) break;
    }
    init();
    checked.set();
//    for (int i=0;i<N;i++)printf("%d",initi.test(i));

    dfs(1,c);
    if (c==1){
        checked.reset();
        check();
    }
    if (c==2){
        checked.reset();
        dfs(1,1);
    }
    sort(ani,ani+ct);

    for (int i=0;i<ct;i++){
        printf("%s\n",ani[i].c_str());
    }
    if (ct==0){
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
