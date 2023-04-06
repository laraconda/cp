#include <bits/stdc++.h>
using namespace std;

const int msize = 101;
vector<int> g[msize];

void connect(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

void disc(int a, int b) {
    auto ra = find(g[a].begin(), g[a].end(), b);
    auto rb = find(g[b].begin(), g[b].end(), a);
    if (ra != g[a].end()) {
        g[a].erase(find(g[a].begin(), g[a].end(), b));
        g[b].erase(find(g[b].begin(), g[b].end(), a));
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        connect(a, b);
    }

    int groups = 0;
    bool one;
    vector <pair <int,int> > untie;
    while (true) {
        one = false;
        for (int i=1; i <= n; i++) {
            if (g[i].size() == 1) {
                one = true;
                untie.push_back(make_pair(i, g[i][0]));
            }
        }
        if (one)
            groups++;
        else
            break;
        for (int i=0; i<untie.size(); i++) {
            disc(untie[i].first, untie[i].second);
        }
        untie.clear();
    }

    cout << groups << endl;
}
