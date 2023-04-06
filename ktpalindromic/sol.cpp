#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        vector<long long> end(s.size());
        vector<long long> endlazy(s.size());

        for (int i=(int)s.size() - 1; i>= 0; i--) {
            long long sa = 0;
            for (int j=i+1; j<(int)s.size(); j++) {
                if (s[i] == s[j]) {
                    endlazy[j] += sa + 1;
                    endlazy[j] %= MOD;
                } 
                sa += end[j];
                sa %= MOD;
            }
            end[i] = 1;
            for (int j=i+1; j<(int)s.size(); j++) {
                end[j] += endlazy[j];
                endlazy[j] = 0;
            }
            
        }

        long long res = 0;
        for (int i=0; i<s.size(); i++) {
            res += end[i];
            res %= MOD;
        }
        cout << res << endl;
    }
}
