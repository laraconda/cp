#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e5 + 2;
int colors[MAXN];
int count_[MAXN];

int main() {
    int n;
    cin >> n;

    int mx = 0;
    int mxc = 0;

    bool allone = true;
    bool allsame = true;
    bool one_rest = false;
    bool rest_plusone = false;

    int ui;
    int maxx = 1;
    int dist = 0;
    for (int i=1; i<=n; i++) {
        cin >> ui;

        count_[colors[ui]]--;
        colors[ui] += 1;
        count_[colors[ui]]++;

        if (colors[ui] == 1)
            dist++;
        
        if (colors[ui] != 1)
            allone = false;

        if (colors[ui] != i)
            allsame = false;

        if (colors[ui] > mx) {
            mx = colors[ui];
            mxc = 1;
        } else if (colors[ui] == mx)
            mxc++; 

        one_rest = (count_[1] == 1) && (mxc == dist - 1);
        rest_plusone = (count_[mx - 1] == dist - 1 && mxc == 1);
 
        if (allone || allsame || one_rest || rest_plusone)
            maxx = i;
    }

    cout << maxx << endl;
}
