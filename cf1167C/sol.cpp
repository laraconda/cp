#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 2;

vector<int> g[N];
bitset<N> visited;
int sizen[N];

int main() {
    int n, m;
    cin >> n >> m;

    int ki;
    vector <int> group;
    while(m--) {
        cin >> ki;
        
        int ai;
        for (int i=0; i<ki; i++) {
            cin >> ai;
            group.push_back(ai);
        }

        if (ki > 1) {
            for (int i=0; i<ki - 1; i++) {
                g[group[i]].push_back(group[i+1]);
                g[group[i+1]].push_back(group[i]);
            }
        }
        group.clear();
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            int reach = 0;

            queue<int> q;
            queue<int> qback;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                reach++;
                int e = q.front();
                q.pop();
                
                qback.push(e);

                for (int ne : g[e]) {
                    if (!visited[ne]) {
                        q.push(ne);
                        visited[ne] = 1;
                    }
                }
            }
            
            while (!qback.empty()) {
                int e = qback.front();
                qback.pop();
                sizen[e] = reach;
            }
        }
    }

    for (int i=1; i<n; i++) {
        cout << sizen[i] << " ";
    }
    cout << sizen[n] << endl;
}
