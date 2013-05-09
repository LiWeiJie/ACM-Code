//poj 1011 Sticks
/*
��ֵ��һ���������⡣
������WA->TLE->WA->TLE->WA->AC�Ĺ��������������ˡ�
�㷨��dfs+��֦+���ݡ�
����Ҫ�ľ��Ǽ�֦�ˣ�dfs�ͻ��ݺܿ�Ϳ���д������
�����¼�������Լ��ģ���ԭsticks��û�б�cutʱ��ƺ�Ϊľ����
1.��С��ԭľ������>=sticks�����е����ֵ
2.��һ�����Ե�ľ������Ӧ����������sticks����֮�͡�
3.dfs�е�����һ��ľ����Ҫ��ԣ�����ǰһ���Ѿ������ʱ�Ϳ��Է���true�ˣ���Ϊ����������n�飬ÿ�鳤��Ϊk��k*n=sum(sticks)����ô����n-1��k���ȵ�ľ����ʣ�µ�sticks�ͱض�����k��
4.��sticks���Ƚ���dfs��������sticks�ĵ�ǰ���Ⱥ���һ������ȣ�����һ����û�б�ʹ�ã���ǰ����Ҳ����Ҫ�ݹ�ʹ�ý�ȥ��
5.��ǰsticks���ȱ�ʣ�����ֵ���󣬾�ֱ�ӷ���false��
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 100

int sticks[N];
bool used[N];
int n;
int len;

bool dfs(int pos,int value, int res){
    if (value==0){
        //��ǰ��valueΪ0���϶�Ҳ���һ��ľ���ˣ���ʣ�µ���ֵ�϶�Ҳ���һ��ľ��
        if (res==2)
            return true;
        pos = n;
        while(used[pos])pos--;
        if (pos>0){
            used[pos] = 1;
            if (dfs(pos-1,len-sticks[pos],res-1)){
                return true;
            }
            used[pos] = 0;
            return false;

        }
        return false;
    }
    else{
        for (;pos>0;pos--){
            if (used[pos]||sticks[pos]>value)continue;
            if (pos<n&&sticks[pos]==sticks[pos+1]&&(!used[pos+1])) continue;
            used[pos] = 1;

            if (dfs(pos,value-sticks[pos],res)){
                return true;
            }
            used[pos] = 0;

        }
        return false;
    }


}

int main()
{

    while(scanf("%d" ,&n)){
        if (n==0) break;
        int sum = 0;
        for (int i=1;i<=n;i++){
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
        }
        sort(sticks+1,sticks+1+n);
        len = sticks[n];
        bool f = true;
        int gro = sum/len;
        len = sum/gro;
        for (;len<=sum/2;len = sum/gro){
            gro--;
            if (sum%len==0) {
                used[n] = 1;
                if (dfs(n,len-sticks[n],sum/len)){
                    f = false;
                    break;
                }
            }

        }
        if (!f) printf("%d\n",len);
        else printf("%d\n",sum);
        memset(used,0,sizeof(used));
    }
    return 0;
}
