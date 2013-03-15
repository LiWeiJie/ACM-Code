//Runaround Numbers
/*
PROG:runround
LANG:C++
ID:apprent2

*/


#include <iostream>
#include <cstdio>

using namespace std;

long long n;

long long checklist[] = {1,1E1,1E2,1E3,1E4,1E5,1E6,1E7,1E8,1E9,1E10};
bool checkenum[10];

bool check(long long c)
{
    int i=0;
    int renum[10],num[10];
    for (int j=0;j<10;j++) renum[j] = 0;
    while (c/checklist[i]!=0){
        num[i] = c/checklist[i]%10;
        renum[num[i]]++;
        i++;
    }
    if (renum[0]!=0) return false;
    for (int j=1;j<10;j++) {
        checkenum[j]=true;
        if (renum[j]>1 ) return false;
    }
    int pos = i-1;
    for (int j=0;j<i;j++){
        pos = pos-num[pos];
        while (pos<0) pos+=i;
        if (checkenum[num[pos]]==false){
            return false;
        }
        checkenum[num[pos]]=false;
    }
    return true;
}

int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    scanf("%lld",&n);
    while (1) {
        if (check(++n)){
            printf("%lld\n",n);
            break;
        }
    }
    return 0;
}
