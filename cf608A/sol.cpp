#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    int s;

    cin >> n >> s;

    int fi, ti;
    while(n--) {
        cin >> fi >> ti;
        if (f[fi] < ti)
            f[fi] = ti;
    }

    int total = 0;
    for (int i=s; i > 0; i--) {
        if (total < f[i])
            total = f[i];
        total++;
    }

    cout << total << endl;


}
