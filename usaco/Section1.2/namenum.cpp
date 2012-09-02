
/*
	ID: apprent2
	PROG: namenum
	LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

string trans(string a, int now)
{
    if (now<a.length())
    {
        int nono=((int)a[now]);
        if (nono>=83) nono--;
        int n = (nono-65)/3+2;
        char t[256];
        string s;

        sprintf(t, "%d", n);
        s = t;

        return s+trans(a,now+1);
    }
    return "";
}


int main()
{
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    ifstream fin ("dict.txt");
    string n = "";
    cin >> n;
    string tmp("KRISTOPHER");
    bool f = true;
    while (fin>>tmp)
    {
        string ne = trans(tmp,0);
        if (ne==n)
        {
            f=false;
            cout<<tmp<<endl;
        }

    }
    if (f) cout << "NONE" <<endl;


    return 0;

}
