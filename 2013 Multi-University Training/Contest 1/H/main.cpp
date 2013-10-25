//#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
#include <queue>

#define LIM 100010

using namespace std;

map<int,bool> mp[LIM];
queue<int> qu;
bool visited[LIM];
int dest[LIM];

int N,M;
int main()
{
    int T;
//    cin >> T;
    scanf("%d",&T);
    int a,b;
    while(T--){
        for (int i=0;i<LIM;i++)
            mp[i].clear();
//        cin >> N >> M;
        scanf("%d %d",&N,&M);
        int s;
        for (int i=0;i<N-1;i++){
            scanf("%d %d",&a,&b);
//            cin >> a >> b;
            mp[a][b] = true;
            mp[b][a] = true;
            s = b;
        }

        map<int,bool>::iterator it;
//        memset(visited,0,sizeof(visited));
        memset(dest,0,sizeof(dest));

        while(!qu.empty())qu.pop();
        qu.push(s);
        dest[s] = 1;
        int maxi = 1;
        int name = s;
        while(!qu.empty()){
            s = qu.front();
            qu.pop();
            it = mp[s].begin();
            while(it != mp[s].end()){
                if (!dest[it->first]){
                    dest[it->first] = dest[s] +1;
                    qu.push(it->first);
                    if (maxi<=dest[s]){
                        maxi = dest[s]+1;
                        name = it->first;
                    }
                }
                it++;
            }
        }

        s = name;
        memset(dest,0,sizeof(dest));
        while(!qu.empty())qu.pop();
        qu.push(s);
        dest[s] = 1;
        maxi = 1;
        while(!qu.empty()){
            s = qu.front();
            qu.pop();
            it = mp[s].begin();
            while(it != mp[s].end()){
                if (!dest[it->first]){
                    dest[it->first] = dest[s] +1;
                    qu.push(it->first);
                    if (maxi<=dest[s]){
                        maxi = dest[s]+1;
                        name = it->first;
                    }
                }
                it++;
            }
        }

        for (int i=0;i<M;i++){
//            cin >> s;
            scanf("%d",&s);
            if (s<=maxi)
//                cout << s-1 << endl;
                printf("%d\n",s-1);
            else
//                cout << (maxi-1)+(s-maxi)*2 << endl;
                printf("%d\n",(maxi-1)+(s-maxi)*2);
        }


    }
    return 0;
}
