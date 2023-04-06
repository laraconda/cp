#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            m[ai]++;
        }
        int g = 0;
        ll r = 0;
        for (auto& x : m) {
            int e = x.first;
            int c = x.second;

            g += c / e;
            r += c % e;
            if (r >= e) {
                g += r / e;
                r = r % e;
            }
        }
        cout << g << endl;
    }
}

