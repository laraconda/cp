#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char a;
        cin >> a;
        string s;
        cin >> s;
        int r;
        string seq="";
        
        int ac = 0;
        for (int i=0; i<n; i++) if (s[i] == a) ac++;
        if (ac == n) {
            r = 0;
        } else {
            if (s.back() != a) {
                int last=-1;
                for (int i=0; i<n; i++) {
                    if (s[i] == a)
                        last = i+1; 
                }
                if (last <= n/2) {
                    r = 2;
                    seq += to_string(n);
                    seq += " ";
                    seq += to_string(n-1);
                } else {
                    r = 1;
                    seq += to_string(last);
                }
            } else {
                r = 1; 
                seq += to_string(n);
            }
        }
        cout << r << endl;
        if (seq.size() != 0) {
            cout << seq << endl;
        }
    }
}
