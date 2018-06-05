#include <iostream>
#include <string>

using namespace std;

const int MAX_N=  100;

int nt[MAX_N];

int build_next(string pattern) 
{
    nt[0] = -1;
    int max_length = 0;
    int len = pattern.length();
    int i, j=-1;
    for (i = 1; i<len; i++)
    {
        if (j==-1 || pattern[i]==pattern[j]) 
        {
            ++i;
            ++j;
            nt[i] = j;
        } else {
            j = nt[i];
        }
        // while( max_length>0 && pattern[i] != pattern[max_length] )
        // {
        //     max_length = nt[i-1];
        // }
        // if (pattern[i] == pattern[max_length])
        // {
        //     max_length++;
        // }
        // nt[i] = max_length;
    }
    return 0;
}

int kmp(string t, string p) 
{
    int i = 0; 
	int j = 0;

	while (i < t.length() && j < p.length())
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
           		j++;
		}
	 	else 
           		j = nt[j];
    	}

    if (j ==p.length())
       return i - j;
    else 
       return -1;
}



int main()
{
    string a,b;
    cin >> a >> b;
    build_next(b);
    cout << kmp(a,b) << endl;
    return 0;
}
