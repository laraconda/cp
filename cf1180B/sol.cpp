#include <bits/stdc++.h>
using namespace std;


vector< pair<int, int>> v;

bool msort(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    int ai;
    for (int i=0; i<n; i++) {
        cin >> ai;
        if (ai < 0)
            ai = -ai - 1;
        v.push_back(make_pair(ai, i));
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n-1; i++) {
        v[i].first = -v[i].first - 1;
    }
    if (n % 2 == 0) {
        v[n-1].first = -v[n-1].first - 1;
    }

    sort(v.begin(), v.end(), msort);
    
    for (int i=0; i<n-1; i++) {
        cout << v[i].first << " ";
    }
    cout << v[n-1].first << endl;
}
