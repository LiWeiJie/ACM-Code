//poj 3325 ICPC Score Totalizer Software
/*
水题一个
去掉一个最高分一个最低分
输出平均分就可以了
*/
#include <iostream>
#include <cstdio>

using namespace std;
#define MAXN 101

int score[MAXN];
int minScore;int maxScore;
int sum;

int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0){
        for(int i=0;i<n;i++){
            scanf("%d",&score[i]);
        }
        minScore=maxScore=score[0];
        sum = 0;
        for(int i=0;i<n;i++){
            sum+=score[i];
            if (score[i]>maxScore)
                maxScore=score[i];
            if (score[i]<minScore)
                minScore = score[i];
        }
        sum = sum - maxScore-minScore;
        printf("%d\n",sum/(n-2));
    }
    return 0;
}
