#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n); iota(all(pos), 1);

    vector<int> seq(n); iota(all(seq), 1);
    vector<int> hs(n);  iota(all(hs), 1);
    vector<int> ls(n);  iota(all(ls), 1);
    for (int i=0; i<m; i++) {
        int ai;
        cin >> ai;
        if (pos[ai-1] > 1) {
            pos[ai-1]--;
            int bi = seq[pos[ai-1] - 1];
            seq[pos[ai-1] - 1] = ai;
            seq[pos[ai-1] - 1 + 1] = bi;
            pos[bi-1]++;

            hs[ai-1] = min(hs[ai-1], pos[ai - 1]);
            ls[ai-1] = max(ls[ai-1], pos[ai - 1]);
            
            hs[bi-1] = min(hs[bi-1], pos[bi - 1]);
            ls[bi-1] = max(ls[bi-1], pos[bi - 1]);
        }
    }

    for (int i=0; i<n; i++) {
        cout << hs[i] << " " << ls[i] << endl;
    }
}
