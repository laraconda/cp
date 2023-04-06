#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();

        vector<int> v(4);
        int i=0;
        int j=-1;
        int md = 1e9;
        while (true) {
            if (!v[1] || !v[2] || !v[3]) {
                j++;
                if (j < n) {
                    int x = s[j] - '0';
                    v[x]++;
                    if (v[1] && v[2] && v[3] && j - i + 1 < md) md = j - i + 1;
                } else break;
            } else {
                if (v[1] && v[2] && v[3] && j - i + 1 < md) md = j - i + 1;
                int x = s[i] - '0';
                if (v[x] - 1 == 0) {
                    j++;
                    if (j < n) {
                        int x = s[j] - '0';
                        v[x]++;
                    } else break;
                } else {
                    v[x]--;
                    i++;
                }
                if (v[1] && v[2] && v[3] && j - i + 1 < md) md = j - i + 1;
            }
        }
        if (md == 1e9) md = 0;
        cout << md << endl;
    }
}
