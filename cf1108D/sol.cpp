#include <bits/stdc++.h>
using namespace std;

string c = "RGB";
int fi(char cc) {
    for (int i=0; i<3; i++) {
        if (cc == c[i]) return i;
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int cha = 0;
    for (int i=1; i<n-1; i++) {
        char b = s[i-1];
        char m = s[i];
        char f = s[i+1];
        if (b == m && m == f) {
            s[i] = c[(fi(m) + 1) % 3];
            cha++;
        }
    }

    for (int i=0; i<n-1; i++) {
        if (s[i] == s[i+1]) {
            cha++;
            char tempt = c[(fi(s[i+1]) + 1) % 3];
            if (i > 0) {
                int f = fi(s[i+1]);
                int b = fi(s[i-1]);
                for (int j=0; j<3; j++) {
                    if (j != f && j != b) {
                        tempt = c[j];
                        break;
                    }
                }
            }
            s[i] = tempt;
        }
    }

    cout << cha << endl;
    cout << s << endl;
}
