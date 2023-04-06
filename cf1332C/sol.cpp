#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        map<char, int> m;
        map<char, int> m1;
        map<char, int> m2;
        int res = 0;

        int lim = (k % 2 == 0) ? k/2: k/2+1;

        for (int j=0; j<lim; j++) {
            for (int i=j; i<n; i += k) {
                m1[s[i]]++;
                m[s[i]]++;
            }

            for (int i=k-j-1; i<n; i += k) {
                m[s[i]]++;
                m2[s[i]]++;
            }

            char maxm = 'a';
            for (auto& c_c : m) {
                if (c_c.second >= m[maxm])
                    maxm = c_c.first;
            }

            if (j == k - j - 1) {
                res += n/k - m1[maxm];
            } else {
                res += n/k - m2[maxm] + n/k - m1[maxm];
            }
            m.clear();
            m1.clear();
            m2.clear();
        }
        cout << res << endl;
    }
}
