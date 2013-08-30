//poj 3860 Fruit Weights
//http://poj.org/problem?id=3860
/*
 *  输入n个形如a X b Y，表示a X <= b Y，第n+1个a X b Y表示询问a X 与 b Y的关系 *“<=”,“>=”,“==”,“UNAVAILABLE”,“INCONSISTENT”
 *  将a X b Y视为X->Y的有向边，权值为b/a,用Floyd扩张路径，cp[x][y] = min(cp[x][y],cp[x][k]*cp[k][y]),最后根据cp[x][y],cp[y][x]判断x,y关系，注意当存在cp[x][y]*cp[y][x]<1 ,则表示存在矛盾
 */

#include <iostream>
#include <map>
#include <cstring>
#include <cmath>
#define N 105
#define WN 55
#define exp 1E-9
using namespace std;

map<string,int> mp;
int ct;
int n;
char X[WN],Y[WN];
double cp[N][N];

void init(){
    ct = 0;

    memset(cp,0,sizeof(cp));
    int a,na,b,nb;
    double val = 0;
    mp.clear();
    for (int i=0;i<n;i++){
        cin >> a >> X >> b >> Y;
        val = (double)b/a;
        if ((na=mp[X])==0){
            mp[X] = ++ct;
            na = ct;
        }

        if ((nb=mp[Y])==0){
            mp[Y] = ++ct;
            nb = ct;
        }

        if (cp[na][nb]==0||cp[na][nb]<val){
            cp[na][nb] = val;
        }
    }
}

void floyd(){
    for (int k=1;k<=ct;k++){
        for (int i=1;i<=ct;i++){
            if (cp[i][k]==0) continue;
            for (int j=1;j<=ct;j++){
                if (cp[k][j]==0) continue;
                if (cp[i][j]==0||cp[i][k]*cp[k][j]<cp[i][j]){
                    cp[i][j] = cp[i][k]*cp[k][j];
                }
            }
        }
    }
}

void query(){

    bool incon = false;
    for (int i=1;i<=ct;i++){
        for (int j=i+1;j<=ct;j++){
            if (cp[i][j]==0||cp[j][i]==0)
                continue;
            if (cp[i][j]*cp[j][i]<1-exp){
                incon = true;
                break;
            }
        }
        if (incon) break;
    }

    int a,na,b,nb;

    cin >> a >> X >> b >> Y;
    if (incon){
        cout << "INCONSISTENT" << endl;
        return;
    }

    if ((na=mp[X])==0){
        mp[X] = ++ct;
        na = ct;
    }

    if ((nb=mp[Y])==0){
        mp[Y] = ++ct;
        nb = ct;
    }

    for (int i=1;i<=ct;i++){
        cp[i][i] = 1;
    }

    double vala = cp[na][nb],valb = cp[nb][na];
    if (vala==0&&valb==0){
        cout << "UNAVAILABLE" << endl;
        return;
    }

    vala *= a;
    valb *= b;
    if (fabs(b-vala)<exp && fabs(a-valb)<exp){
        cout << "==" << endl;
        return;
    }

    if (fabs(vala)>exp&&(vala<b||fabs(vala-b)<exp)){
        cout<<"<="<<endl;
        return;
    }
    if (fabs(valb)>exp&&(valb<a||fabs(valb-a)<exp)){
        cout << ">=" << endl;
        return;
    }
    cout << "UNAVAILABLE" << endl;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);

    while(cin>>n){
        if (n==0) break;
        init();
        floyd();
        query();
    }
    return 0;
}
