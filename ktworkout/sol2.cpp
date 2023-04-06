#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector<int> start(N);
vector<pair<int, int>> ms(N);
vector<int> off(N);

bool freem(int m, int t, bool& beg) {
    int a = ms[m].first + ms[m].second;
    int moff = start[m] + off[m];
    t -= moff;
    if (t < 0) {
        beg = false;
        return true;
    }
    int b = t/a;
    if (t == b * a) beg = true;
    else beg = false;
    if (b * a <= t && t < b * a + ms[m].first)
        return false;
    return true;
}

int main() {
    vector<pair<int, int>> jim;

    for (int i=0; i<N; i++) {
        int u, r;
        cin >> u >> r;
        jim.push_back({u, r});
    }


    for (int i=0; i<N; i++) {
        int u, r, t;
        cin >> u >> r >> t;
        ms[i] = {u, r};
        start[i] = t;
    }

    int ans = -1;
    int t = 0;
    int lap = 1;
    int m = 0;
    bool occ = false;
    bool ready = true;
    int readyt = -1;
    int fin = -1;
    bool beg;
    while (lap < 4) {
        if (t == fin) occ = false;
        if (t == fin && lap == 3 && m == 9) {
            ans = t;
            break;
        }
        if (t == readyt) {
            ready = true;
            m++;
        }
        if (m == N) {
            m = 0;
            lap++;
        }
        bool free = freem(m, t, beg);
        int nextf = -1;
        int nextb = -1;
        if (beg) {
            nextb = t;
            nextf = t + ms[m].first;
        }

        if (beg && occ) {
            off[m] += fin - t;
            cout << "t: " << t << " off[" << m << "]: " << off[m] << " endw: " << fin << endl;
        }

        if (free && ready) {
            occ = true;
            ready = false;
            fin = t + jim[m].first;
            readyt = fin + jim[m].second;
        }
        // cout << " t: " << t  << " m: " << m << " free: " << free << " endw: " << fin << " readyt: " << readyt << endl;
        t++;
    }

    cout << ans << endl;
}

