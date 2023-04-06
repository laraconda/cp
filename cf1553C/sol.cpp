#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        pair<int, int> a;
        pair<int, int> b;
        int l;
        for (int i=0; i<s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '?') a.second++;
                else if (s[i] == '1') a.first++;
            } else {
                if (s[i] == '?') b.second++;
                else if (s[i] == '1') b.first++;
            }
            int ap = (9 - i) / 2;
            int bp = ceil(((float)(9 - i)) / 2);
            l = i;
            if (a.first + a.second > b.first + bp) break;
            if (b.first + b.second > a.first + ap) break;
        }
        cout << l + 1 << endl;
    }
}
