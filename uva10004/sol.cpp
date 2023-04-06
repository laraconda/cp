#include <bits/stdc++.h>
using namespace std;

const int MXN = 204;
vector<int> g[MXN];
int gv[MXN];

bool bip(int n) {
    bool bipb = true;
    queue<int> q;
    q.push(0);
    gv[0] = 1;
    while (!q.empty() && bipb) {
        int v = q.front(); q.pop();
        for (int ne : g[v]) {
            if (gv[ne] == gv[v]) {
                bipb = false;
                break;
            } else if (gv[ne] == 0) {
                q.push(ne);
                gv[ne] = gv[v] * -1;
            }
        }
    }
    return bipb;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    int m;

    int ai, bi;
    cin >> n;
    while(n != 0) {
        cin >> m;
        for (int i=0; i<m; i++) {
            cin >> ai >> bi;
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }

        if (bip(n))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
        
        for (int i=0; i<n; i++) {
            g[i].clear();
            gv[i] = 0;
        }
        cin >> n;
    }
}
