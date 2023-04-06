#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    int ai;

    priority_queue<int> pq;
    unordered_map<int, int> um;
    vector<int> v;
    int c = 0;
    while(cin >> ai) {
        if (ai != -1) {
            c++;
            pq.push(ai);
            um[ai]++;
            v.push_back(ai);
            if (c >= m) {
                int ri = c - m - 1;
                if (ri >= 0) {
                    um[v[ri]]--;
                }
                int ans = pq.top();
                while (um[ans] == 0) {
                    pq.pop();
                    ans = pq.top();
                }
                cout << ans << endl;
            }
        }
    }
}
