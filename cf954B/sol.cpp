#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string largest = "";
    int b = 0, e = 0;
    for (int i=0; i<n; i++) {
        bool p = true;
        string ns = "";
        for (int ii=0; ii<=i; ii++) {
            int j = i + ii + 1;
            if (s[ii] != s[j])
                p = false;
            ns.push_back(s[ii]);
        }
        if (p) {
            if (ns.size() > largest.size()) {
                b = i + 1;
                e = 2*i + 1;
            }
        }
    }

    cout << b + 1 + (n - 1 - e) << endl;
}
