
/*
	ID: apprent2
	PROG: transform
	LANG: C++
*/

#include <iostream>
#include<fstream>


const int maxn = 10 ;
using namespace std;

void print(char init[maxn][maxn],int n,int k)
{
    cout << k <<endl;
    for (int i=0;i<n;i++)
    {


        for (int j=0;j<n;j++)
        {
            //init[i][j] = tmp[i][j];
            cout << init[i][j];
        }
        cout <<endl;
    }
}



bool Compare(char init[maxn][maxn],char fin[maxn][maxn],int n)
{
    for (int i=0 ; i<n ; i++)
        for (int j=0;j<n;j++)
        {
            if (init[i][j]!=fin[i][j]) return false ;
        }
    return true;
}



bool transform(char init[][maxn],char fin[][maxn],int k , int n)
{
    char tmp[maxn][maxn] = {""};
    if (k==4) transform(init,fin,3,n);

    for (int i = 0; i < n ; i++)
        for(int j=0 ; j < n ; j++ )
        {
            switch (k)
            {
                case 1:
                case 2:
                case 3: tmp [j][n-i-1] = init [i][j]; break;
                case 4: tmp [i][n-j-1] = init [i][j];break;
                case 5:
                {
                    for (int z=0;z<3;z++) if (transform(init,fin,3,n))return true;
                    return false;
                    break;
                }
                case 6: return (transform(init,fin,4,n));break;
                case 7:return true;break;
            }
        }
    for (int i=0;i<n;i++)
    {


        for (int j=0;j<n;j++)
        {
            init[i][j] = tmp[i][j];
            //cout << init[i][j];
        }
        //cout <<endl;
    }

    if (Compare(init,fin,n))return true;
    else return false ;
}



int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int n;
    cin >> n;
    char init[maxn][maxn] ={""} ,  fin [maxn][maxn] = {""};
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> init[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> fin[i][j];
    for (int i=1 ; i<=7 ; i ++ )
    {
        if (transform(init,fin,i,n))
        {
            cout << i <<endl;
            break;
        }
       // print (init,n,i);
    }

    return 0;
}
