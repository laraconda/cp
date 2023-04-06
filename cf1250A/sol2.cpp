#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> pos(n+1); iota(all(pos), 0);
    vector<int> seq(n+1); iota(all(seq), 0);
    vector<int> hs(n+1); iota(all(hs), 0);
    vector<int> ls(n+1); iota(all(ls), 0);

    for (int i=0; i<m; i++) {
        int ai;
        cin >> ai;
        if (pos[ai] > 1) {
            pos[ai]--;
            int bi = seq[pos[ai]];
            seq[pos[ai]] = ai;
            seq[pos[ai] + 1] = bi;
            pos[bi]++;

            hs[ai] = min(hs[ai], pos[ai]);
            ls[ai] = max(ls[ai], pos[ai]);
            
            hs[bi] = min(hs[bi], pos[bi]);
            ls[bi] = max(ls[bi], pos[bi]);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << hs[i] << " " << ls[i] << endl;
    } 
    
}
