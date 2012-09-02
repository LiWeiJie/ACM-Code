#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
#include <list>


#define res 10E-6
using namespace std;

int main()
{
    double p,q;

    while (scanf("%lf %lf",&p,&q)!=EOF)
    {

        for (int i =1 ; ; i++)
        {
//            if ( floor(i*p/100)+1 <= ceil(i*q/100) -1   )
//            {
//                printf("%d\n",i);
//                break;
//            }

            double ca,cb;
            ca = i*p/100; cb = i*q/100;
            int ta,tb;
            ta = floor(ca);
            tb = ceil(cb);
            if ( abs (ca - ta -1) < res )  ta +=2;
            else ta += 1;
            if ( abs (tb - cb -1)<res ) tb -= 2;
            else tb -= 1;

            if ( ta<= tb   )
            {
                printf("%d\n",i);
                break;
            }
        }

    }
    return 0;
}
