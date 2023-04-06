#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        string s, ns;
        cin >> s;

        int de = 0;
        for (int i=0;i<s.size(); i++) {
            int d = s[i] - '0';
            if (d > de) {
                int lim = d - de;
                for (int j=0; j < lim; j++) {
                    ns.push_back('(');
                    de++;
                }
                ns.push_back(s[i]);
            } else {
                int lim = de - d;
                for (int j=0; j < lim; j++) {
                    ns.push_back(')');
                    de--;
                }
                ns.push_back(s[i]);
            }
        }

        while (de > 0) {
            ns.push_back(')');
            de--;
        }
    
        cout << "Case #" << t << ": " << ns << endl;
    }
}
