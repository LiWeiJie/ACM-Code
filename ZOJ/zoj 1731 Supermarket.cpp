//1731 Supermarket
/*
优先队列或者排序，所有prod里面profit高的排在前面，profit相等的则deadtime小的优先。
然后从前面往后面去检查，对于每一个products，从其deadtime开始往前寻找没有被标记过的时间点直至时间0点或者找到没有被标记的，然后标记，并把这个profit加起来。
最后输出sum就可以了。
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct Schedule
{
    int profit;
    int dt;
    //先处理高利润的
    bool operator<(const Schedule &rhs)const {
        return profit<rhs.profit;

    }
};

bool used[10001];
priority_queue<Schedule> que;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        while(!que.empty())que.pop();
        int max = 0;
        for (int i=0;i<n;i++){
            Schedule prod;
            scanf("%d %d",&prod.profit,&prod.dt);
            if (prod.dt>max) max = prod.dt;
            que.push(prod);
        }
        memset(used,false,sizeof(bool)*(max+1));
        long long sum =0;
        int current = 0;
        //从前面往后面去检查，对于每一个products，从其deadtime开始往前寻找没有被标记过的时间点直至时间0点或者找到没有被标记的，然后标记，并把这个profit加起来。
        while(!que.empty()){
            Schedule prod = que.top();
            que.pop();
            while(prod.dt--){
                if (!used[prod.dt]){
                    used[prod.dt] = true;
                    sum+=prod.profit;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
