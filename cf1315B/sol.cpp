#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, p;
        cin >> a >> b >> p;

        string s;
        cin >> s;

        vector<long long> minc(s.size());
        vector<bool> term(s.size());
        minc[0] = 0;
        term[0] = true;
        long long c = 0;
        char last = '-';
        for (int i=0; i<s.size(); i++) {
            minc[i] = c;
            if (last != s[i]) {
                term[i] = true; 
                c += (s[i] == 'A') ? a : b;
            } else {
                term[i] = false;
            }
            last = s[i]; 
        }

        c = minc[s.size() - 1];
        int res = -1;
        for (int i=0; i<s.size(); i++) {
            if (c - minc[i] <= p && term[i]) {
                res = i;
                break;
            } 
        }

        if (res == -1)
            res = s.size() - 1;

        cout << res + 1 << endl;
    }
}
