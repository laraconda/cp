#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int mx = 0;
    int c = 0;
    char last = '0';
    for (int i=0; i<s.size(); i++) {
        if (last == '0' || s[i] == last) {
            c++;
        } else {
            c = 1;
        }
        last = s[i];
        mx = max(mx, c);
    }

    cout << mx << endl;
}
