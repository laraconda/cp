#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int p = 0;
    int l = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'o')
            p++;
        else {
            l++;
        }
    }
    if (p == 0) {
        cout << "YES" << endl;
        return 0;
    }
    if (l % p == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        
    }
}
