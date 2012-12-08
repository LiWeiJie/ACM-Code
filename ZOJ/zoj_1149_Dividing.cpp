#include <iostream>
#include <cstdio>

using namespace std;

int num[6] ;
int value[] = {1,2,3,4,5,6};
//int mods[] = {6,3,2,2,2,2};
int sums[6];
//target是需要填充的数值
bool dfs(int pos,int target)
{
    if (target<0) return false;
    if (target==0)  return true;
    //当dfs到最后一个位置时，只需要判断剩下的1的数量能否填充需要就可以了
    if (pos == 0)  return num[0]>=target;
    for (int i = num[pos];i>=0;i--)
    {
        //当剩下的数值不足填充target时，就没有必要进行下去了
        if (sums[pos-1]<target-i*value[pos]) return false;
        if (dfs(pos-1,target-i*value[pos]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n=0;
    while(1)
    {
        n++;
        int sum = 0;
        for(int i=0;i<6;i++) {
            scanf("%d",&num[i]);
            if (num[i]!=0){
                num[i] = num[i]%6;
                if (num[i]==0) num[i]=6;
            }
            sums[i] = num[i]*(i+1);
            sum += sums[i];
        }
        for(int i=1;i<6;i++) {
            sums[i] += sums[i-1] ;
        }
        if (sum==0) break;
        bool can_divide = false;
        if (sum %2 == 0)
        {
            can_divide = dfs(5,sum/2);
        }
        printf("Collection #%d:\n",n);
        if (can_divide) printf("Can be divided.\n");
        else
            printf("Can't be divided.\n");
        printf("\n");
    }
    return 0;
}
