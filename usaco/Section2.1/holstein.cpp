//Healthy Holsteins
/*
通过bitset来枚举每一种饲料情况
  PROG:holstein
  LANG:C++
  ID:apprent2
*/
#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>

using namespace std;

#define N 16
#define M 26

int cow[M],vi[N][M];
int feed[M];
int v,g;

bitset<16> miniset(0);

int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    scanf("%d",&v);
    for (int i=0;i<v;i++){
        scanf("%d",&cow[i]);
    }
    scanf("%d",&g);
    for (int i=0;i<g;i++){
        for (int j=0;j<v;j++){
            scanf("%d",&vi[i][j]);
        }
    }

    //枚举每一种饲料喂养
    bool f;
    for (int i=0;i<(1<<(g));i++){
        bitset<16> tmp(i);
        for (int j=0;j<g;j++){
            if (tmp.test(j)==true){
                for (int z=0;z<v;z++){
                    feed[z] += vi[j][z];
                }
            }
        }
        f = true;
        for (int z=0;z<v;z++){
            if (feed[z]<cow[z]){
                f = false;
                break;
            }
        }
        memset(feed,0,sizeof(feed));
        //在个数相同的情况下，字典序小的优先，所以把bitset还原回数字之后小的优先
        if (f&&((miniset.count()==0||tmp.count()<miniset.count())||(tmp.count()==miniset.count()&&tmp.to_ulong()<miniset.to_ulong()))){
            miniset = tmp;
        }
    }
    printf("%d",miniset.count());
    for (int i=0;i<g;i++){
        if (miniset.test(i))
        printf(" %d",i+1);
    }
    printf("\n");
    return 0;
}
