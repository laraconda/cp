#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;

    vector<pair<int, int>> ts;
    for (int i=0; i<n; i++) {
        int ti, li;
        cin >> ti >> li;

        ts.push_back({ti, ti + li});
    }

    long long b = 0;
    if (n > 0)
        b += ts[0].first / a;
    for (int i=1; i<n; i++) {
        b += (ts[i].first - ts[i-1].second) / a;
    }
    int lastt = 0;
    if (n > 0)
        lastt = ts[n-1].second;
    b += (L - lastt) / a;

    cout << b << endl;
}
