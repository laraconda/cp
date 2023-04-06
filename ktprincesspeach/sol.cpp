#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;
    vector<int> obs(n);
    for (int i=0; i<y; i++) {
        int yi;
        cin >> yi;
        obs[yi]++;
    }

    int found = 0;
    for (int i=0; i<n; i++) {
        if (obs[i] == 0) cout << i << endl;
        if (obs[i] > 0) found++;
    }
    cout << "Mario got " << found << " of the dangerous obstacles." << endl;
}
