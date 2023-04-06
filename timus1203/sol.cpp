#include <bits/stdc++.h>
using namespace std;

bool mc(pair<int, int> e1, pair<int, int> e2) {
    return (e1.second < e2.second);
}

vector<pair <int, int> > a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int si, ei;
    for (int i=0; i<n; i++) {
        cin >> si >> ei;
        a.push_back(make_pair(si, ei));
    }

    sort(a.begin(), a.end(), mc);
    
    int res = 1;
    int c = 0;
    for (int i=0; i<n; i++) {
        if (a[i].first > a[c].second) {
            res++;
            c = i;
        }
    }
    cout << res << endl;
}
