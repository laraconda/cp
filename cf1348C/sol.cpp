#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if (s[0] != s[k-1]) {
        cout << s[k-1] << endl;
        return;
    }

    cout << s[0];
    if (s[k] != s.back()) {
        for (int i=k; i<s.size(); i++)
            cout << s[i]; 
    } else {
        for (int i=0; i<ceil((double)(n - k)/k); i++) {
            cout << s[k];
        }
    }
    cout << endl;

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
