//zoj 2724 Windows Message Queue
/*
 *���⣬ʹ��stl�����ȶ��У�
 *��Ҫ�Լ���д�ȽϺ�����������ȼ�һ�����ͱȽ���queue��ʱ�����
 *
 */


#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;


struct node
{
    char msg[33];
    int parm;
    int value;
    int ind;


};

bool
operator<(const node & lhs,const node & rhs)
{
    return (lhs.value>rhs.value)||(lhs.value==rhs.value&&lhs.ind>rhs.ind);
}

int main()
{
    char  command[10];
    priority_queue<node> result;
    while(!result.empty()) result.pop();
    int sum=0;
    while(scanf("%s",command)==1)
    {
        if (strcmp(command,"GET")==0)
        {
            if (result.empty())
            {
                printf("EMPTY QUEUE!\n");
            }
            else
            {
                node answer = result.top();
                printf("%s %d\n",answer.msg,answer.parm);
                result.pop();

            }
        }
        else
        {
            node tmp;
            scanf("%s %d %d",tmp.msg,&tmp.parm,&tmp.value);
            tmp.ind = sum++;
            result.push(tmp);
        }
    }
    return 0;
}
