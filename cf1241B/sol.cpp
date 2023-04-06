#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        string s;
        string t;

        cin >> s >> t;

        map<char, bool> ms;
        for (int i=0; i<s.size(); i++) {
            ms[s[i]] = true;
        }
        
        bool pos = false;
        for (int i=0; i<s.size(); i++) {
            if (ms.count(t[i]) == 1)
                pos = true;
        }

        if (pos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
