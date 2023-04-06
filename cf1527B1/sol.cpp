#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '0') c++;
        }
        string a, w;
        if (c == 0) a = "DRAW";
        else if (c == 1) {
            a = "BOB"; 
        } else if (c % 2 == 0) {
            a = "BOB";
        } else {
            a = "ALICE";
        }
        cout << a << endl;
    }
}
