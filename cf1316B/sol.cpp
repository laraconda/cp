#include <bits/stdc++.h>
using namespace std;

void tr(string& s, string& ns, int k) {
    int n = s.size();
    int m = n - k + 1;
    int j = 0;
    for (int i=k-1; i<n; i++) {
        ns[j++] = s[i];
    }

    if (m % 2 == 0) {
        for (int i=0; i<k-1; i++) {
            ns[j++] = s[i];
        }
    } else {
        for (int i=k-2; i>=0; i--) {
            ns[j++] = s[i];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string ss(s);
        string ns(s);
        int sk = 1;
        for (int i=2; i<=n; i++) {
            tr(s, ns, i);
            if (ns < ss) {
                ss = ns;
                sk = i;
            }
        }
        cout << ss << endl;
        cout << sk << endl;
    }
}
