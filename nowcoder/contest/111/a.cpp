#include <iostream>
#include <cstring>
using namespace std;

long long int black_area;

const int sz = 400001;
int height[sz];
int width[sz];

int dfs(string &c, int &pos, int ed, int depth) {
    // cout << c << st << ed << depth<< endl;
    // int lbrace, rbrace;
    // lbrace = rbrace = 0;
    int subtraction = 0;
    int box_width = 0;
    int box_height = 0;
    int sub_box_counter = 0;
    // if (st==ed) {
    //     box_height = 1;
    //     return 1;
    // }
    int next_depth = depth + 1;
    while(pos<ed && c[pos]=='(') {
        pos++;
        dfs(c, pos, ed, next_depth);
        int sub_height = 0;
        int sub_width = 0;
        sub_height = height[next_depth];
        sub_width = width[next_depth];
        sub_box_counter++;
        subtraction += sub_height * sub_width;        
        if (sub_height > box_height) {
            box_height = sub_height;
        }
        box_width += sub_width;
    }
    if (pos<ed && c[pos]==')')
        pos++;
    box_width += sub_box_counter + 1;
    box_height += 1;
    if (depth%2==1) {
        black_area += box_width * box_height - subtraction;
    }
    height[depth] = box_height;
    width[depth] = box_width;
    return 0;
}

int main() {
    int T;
    string c;
    
    while (cin >> T) {
        for (int i=0; i<T; i++) {
            fill(height, height + sz, 0);
            fill(width, width + sz, 0);
            cin >> c;
            black_area = 0;
            int pos = 0;
            int ed = 0;
            dfs(c, pos, c.size(), ed);
            cout << black_area << endl;
        }
    }
}