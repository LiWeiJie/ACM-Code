/*
���鼯��Ŀ
����N���˺�M������
����M��
M a b ��ʾa��b�������
Q a  ��ʾ��ѯ���a��������
���ѹ�ϵ�ǿɴ��ݵ�
����һ��ʼÿ����Ϊһ��Ȧ��
treeId��¼����Ȧ�Ӻţ���������Ѿ͸�Ϊͬһ��Ȧ�ӡ�Ȧ�ӵ����ȱ�Ϊ-x��x��ʾȦ�ӵ�������������������������Ѱ���¼��
��ʼʱ��ÿһ��find(x)�������¶��ϣ�û�ж�Ѱ��������Ż������TLE�ˣ������Ż���Ѱ�溯����ֱ�Ӽ�¼���ȡ�320ms
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define N 100005

int treeId[N];

inline void init(int i)
{
    treeId[i] = -1;
}



int find(int x)
{
    if (treeId[x]>=0)
    {
        return treeId[x]=find(treeId[x]);
    }
    return x;
}

int main()
{
    int n,m;
    int index = 0;
    while (scanf("%d %d\n",&n,&m)==2)
    {
        index++;
        if (index==1)   printf("Case %d:\n",index);
        else printf("\nCase %d:\n",index);
        for (int i=0;i<n;i++)
        {
            init(i);
        }
        while(m--)
        {
            char choice;
            scanf("%c",&choice);
            if (choice=='M')
            {
                int a,b;
                scanf("%d %d\n",&a,&b);
                int fa,fb;
                fa = find(a-1);
                fb = find(b-1);
                if(fa != fb)
                {
                    treeId[fa] += treeId[fb];
                    treeId[fb] = fa;
                }
            }
            else
            {
                int x;
                scanf("%d\n",&x);
                x--;
                printf("%d\n",-treeId[find(x)]);
            }
        }
    }
    return 0;
}
