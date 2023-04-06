#include <bits/stdc++.h>
using namespace std;

bool eqq(string& a, string& b, int s, int e) {
    bool eq = true;
    for (int i=s; i<=e; i++) {
        if (a[i] != b[i]) eq = false;
    }
    return eq;
}


bool eof(string& a, string& b, int s, int e) {
    bool eq = true;
    for (int i=s; i<=e; i++) {
        if (a[i] != b[i]) eq = false;
    }
    bool f = true;
    for (int i=s; i<=e; i++) {
        if (a[i] == b[i]) f = false;
    }
    return eq || f;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        int c = 0;
        vector<int> v(n, 0);
        for (int i=0; i<n; i++) {
            if (a[i] == '1') c++;
            if (c == (i+1)/2 && (i+1) % 2 == 0) {
                v[i] = 1;
            }
        }

        bool pos = true;
        int i=0;
        for (int j=0; j<n; j++) {
            if (v[j] == 1) {
                if (!eof(a, b, i, j)) {
                    pos = false;
                }
                i = j+1;
            } 
        }
        if (!eqq(a, b, i, n-1)) pos = false;
        if (pos) cout << "YES"; else cout << "NO";
        cout << endl;
    }
}
