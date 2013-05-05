//zoj 2511 & hdu 1031 Design T-Shirt
/*
水题
考排序而已，应用sort和优先队列很容易就过了
计算前面k个最大值时，当score相同时，序号前的优先
当输出k个数时，则用降序输出
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Scores
{
    double sum;
    int id;
    bool operator<(const Scores& rhs)const{
        if (sum>rhs.sum) return true;
        if (sum==rhs.sum)
            return id<rhs.id;
        return false;
    }
};
//design score
Scores score[10000];
//给xka的设计编号
priority_queue<int> xka;
int main()
{
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF){
        while(!xka.empty()) xka.pop();
        for (int i=0;i<m;i++){
            score[i].sum = 0;
            score[i].id = i+1;
        }
        for (int i=0;i<n;i++){
            double tmp;
            for (int j=0;j<m;j++){
                scanf("%lf",&tmp);
                score[j].sum += tmp;
            }
        }
        sort(score,score+m);
        //把k个最大值放进xka里面对序号排序输出
        for (int i=0;i<k;i++){
            xka.push(score[i].id);
        }
        printf("%d",xka.top());
        xka.pop();
        for (int i=1;i<k;i++){
            printf(" %d",xka.top());
            xka.pop();
        }
        printf("\n");
    }
    return 0;
}
