#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int lastr = -1;
        int maxd = 0;
        for (int i=0; i<(int)s.size(); i++) {
            if (s[i] == 'R') {
                maxd = max(maxd, i - lastr);
                lastr = i;
            }
        }
        maxd = max(maxd, (int)s.size() - lastr);
        cout << maxd << endl;
    }
}
