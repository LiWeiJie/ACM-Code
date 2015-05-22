//URAL 1732 Ministry of Truth
//http://acm.timus.ru/problem.aspx?space=1&num=1732
/*
 * 题意:
 * 输入两个字符串A和B，问能否通过删去A的部分字符令A变为B，删去的字符会变成空格，超过一个的空格会合并为一个，若能，输出A，删去的部分用_代替，若不能，输出I HAVE FAILED!!!
 * 思路:
 * 把B通过空格分割出来，匹配每一个word能否在A中找到子串，若能，令其下一个位置修改不为空格则置为_，继续在该子串后找下一个word。最后除了这些子串外全部单词标为_
 * author:licatweijie
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010

using namespace std;
char name[2][N];
char temp[N];
int ff[N];

void getFail(char *P,int *f){
    int m =strlen(P);
    f[0] = 0;f[1] = 0;
    for (int i=1;i<m;i++){
        int j= f[i];
        while(j && P[i]!=P[j] ) j=f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }

}


int find (char * T,char * P ,int *f){
    int n = strlen(T),m  = strlen(P);
    getFail(P,f);
    int j  = 0;
    for (int i=0; i< n;i++){
        while ( j && P[j]!=T[i]) j = f[j];
        if (P[j] == T[i] ) j++;
        if (j==m) return i-m+1;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);

    while(gets(name[0]))
    {
        gets(name[1]);

        int i=0;
        int len1 = strlen(name[1]);
        int len0 = strlen(name[0]);
        int ctmp = 0;
        std::size_t pre=0;

        while(name[1][ctmp]!=' ' && ctmp<len1)ctmp++;
        strncpy(temp,name[1],ctmp);
        temp[ctmp] = '\0';

        std::size_t found = find(name[0],temp,ff);

        if(found!=-1)
        {
            for(int j=pre; j<found; j++)
                if(name[0][j]!=' ')
                    name[0][j]='_';
        }
        else
        {
            cout << "I HAVE FAILED!!!" << endl;
            continue;
        }
        found+=strlen(temp);
        if(found<len0&&name[0][found]!=' ')
        {
            name[0][found]='_';
        }
        found++;
        pre = found;
        bool flag=true;
        int pre2 = ctmp;
        int foundtmp = found;
        while(true)
        {

            if(ctmp==len1)
                break;

            while(name[1][ctmp]==' ' && ctmp<len1)ctmp++;
            pre2 = ctmp;
            while(name[1][ctmp]!=' ' && ctmp<len1)ctmp++;
            strncpy(temp,name[1]+pre2,ctmp-pre2);
            temp[ctmp-pre2] = '\0';

            found = find(name[0]+pre,temp,ff);
            if(found!=-1)
            {
                found += pre;
                for(int j=pre; j<found; j++)
                    if(name[0][j]!=' ')
                        name[0][j]='_';
            }
            else
            {
                flag=false;
                break;
            }
            found+=strlen(temp);
            if(len0>found&&name[0][found]!=' ')
            {
                name[0][found]='_';
            }
            found++;
            pre = found;
        }
        if(flag)
        {
            for(int j=pre; j<len0; j++)
                if(name[0][j]!=' ')
                    name[0][j]='_';
            cout << name[0] << endl;
        }
        else
        {
            cout << "I HAVE FAILED!!!" << endl;
        }
    }
    return 0;
}



