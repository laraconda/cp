#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> seq(n);
        map<int, int> mm;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            seq[i] = ai;
            mm[ai]++;
        }

        if (mm.size() > k) {
            cout << -1 << endl;
        } else {
            vector<int> gen;
            for (auto x : mm) {
                gen.push_back(x.first);
            }
            while (gen.size() < k) {
                gen.push_back(gen.back());
            }

            int j = 0;
            for (int i=0; i<seq.size(); i++) {
                if (gen[j] != seq[i]) {
                    seq.insert(seq.begin() + i, gen[j]);
                }
                j++;
                j %= gen.size();
            }
            cout << seq.size() << endl;
            for (auto x : seq)
                cout << x << " ";
            cout << endl;
        }
    }
}
