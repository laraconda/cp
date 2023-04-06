#include <bits/stdc++.h>
using namespace std;

const int MXN = 56;
vector<int> graph[MXN];
bool loop[MXN];
int vis[MXN];


void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int ne : graph[v]) {
            if (vis[ne]) {
                loop[ne] = 1;
            } else {
                q.push(ne);
                vis[ne] = 1;
            }
        }
    }
}

void clean() {
    for (int i=0; i<MXN; i++) {
        loop[i] = false;
        vis[i] = 0;
        graph[i].clear();
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        clean();
        int p;
        int s;
        cin >> p >> s;
        vector<string> names;
        for (int i=1; i<=p; i++) {
            string name;
            cin >> name;
            names.push_back(name);
        }
        for (int i=1; i<=p; i++) {
            int m;
            cin >> m;
            while (m--) {
                int ci;
                cin >> ci;
                graph[i].push_back(ci);
            }
        }

        bfs(s);
        for (int i=1; i <= p; i++) {
            if (loop[i])
                cout << names[i-1] << " ";
        }
        cout << endl;
    }
}
