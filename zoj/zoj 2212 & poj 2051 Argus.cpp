//zoj 2212 || poj 2051 Argus
//又是一道水题,应用优先队列很简单。题目要求输出前K个发送的目标.那么构造一个结构，存储period，Q_num和下一次的发送时间next就可以轻松搞定了
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct Argus
{
    int Q_num;
    int period;
    int next;
    bool operator<(const Argus& rhs)const{
        if (next>rhs.next) return true;
        if (next==rhs.next)
            return Q_num>rhs.Q_num;
        return false;
    }
};

priority_queue<Argus> que;
int main()
{
    char s[255];
    while(!que.empty()) que.pop();
    while(scanf("%s",s)){
        if (s[0]=='#'){
            int k;
            scanf("%d",&k);
            //询问k次
            for (int i=0;i<k;i++){
                Argus ask;
                ask = que.top();
                que.pop();
                printf("%d\n",ask.Q_num);
                ask.next = ask.next+ask.period;
                que.push(ask);
            }
            return 0;
        }else{
            Argus command;
            scanf("%d %d",&command.Q_num,&command.period);
            command.next = command.period;
            que.push(command);
        }
    }
    return 0;
}
