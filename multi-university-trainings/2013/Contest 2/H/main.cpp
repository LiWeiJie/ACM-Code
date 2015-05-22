////http://acm.hdu.edu.cn/showproblem.php?pid=4618
////找出最大的回文子矩阵，令每一行，每一列都是回文的。输出规模
//#include <iostream>
//#include <cstdio>
//#include <string>
//
//#define N 305
//using namespace std;
//
//int n,m;
//int s[N][N];
//
//bool check(int x,int y,int len)
//{
//    int xl = x+len-1;
//    int yl = y+len-1;
//    int mid = len /2;
//    for (int i=0;i<len;i++){
//        for (int j=0;j<mid;j++){
//            if (s[x+i][y+j]!=s[x+i][yl-j])
//                return false;
//        }
//    }
//    for (int i=0;i<len;i++){
//        for (int j=0;j<mid;j++){
//            if (s[x+j][y+i]!=s[xl-j][y+i])
//                return false;
//        }
//    }
//    return true;
//}
//
//int solve()
//{
//    int len = n>m?m:n;
//    while(len!=1){
//        for (int i=0;i<n-len+1;i++){
//            for (int j=0;j<m-len+1;j++)
//                if (check(i,j,len))
//                    return len;
//        }
//        len--;
//    }
//    return len;
//}
//
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    while(T--){
//        scanf("%d %d",&n,&m);
//        for (int i=0;i<n;i++){
//            for (int j=0;j<m;j++){
//                scanf("%d",&s[i][j]);
//            }
//        }
//        int ans = solve();
//        printf("%d\n",ans);
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>

using namespace std;

int t,m,n;
int dos;
bool flag;
int s[330][330];

int main()
{
//    freopen("F:\in.txt","r",stdin);
//    freopen("F:\in0.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                scanf("%d",&s[i][j]);
            }
        }
        dos = (n<m)?n:m;
        do{
            for (int i=0;i+dos-1<n;i++){
                for (int j=0;j+dos-1<m;j++){
                    //检查行列
                    flag = true;
                    int mid = dos/2;
                    for (int x=0;x<dos;x++){
                        for (int k=0;k<dos;k++){
                            if (s[i+x][j+k]!=s[i+x][j+dos-1-k]){
                                flag = false;
                                break;
                            }
                            if (s[i+k][j+x]!=s[i+dos-1-k][j+x]){
                                flag = false;
                                break;
                            }
                        }
                        if (flag == false)
                            break;
                    }


                    if (flag == true)break;
                }
                if (flag == true)break;
            }
            if (flag == true)break;
            dos--;
        }while(dos>1);
        printf("%d\n",dos);
    }
    return 0;
}

