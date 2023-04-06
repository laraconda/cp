#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        vector<int> ns;
        string c;
        int ci;
        for (int i=0; i<s.size(); i++) {
             if (s[i] == ' ') {
                ci = stoi(c);
                ns.push_back(ci);
                c = "";
             } else {
                c.push_back(s[i]);
             }
        }
        ci = stoi(c);
        ns.push_back(ci);

        long long su = 0;
        bool off = false;
        for (int i=0; i<ns.size(); i++) {
            if (off) break;
            for (int j=0; j<ns.size(); j++) {
                if (j == i) continue;
                su += ns[j];
            }
            if (ns[i] == su) {
                cout << su << endl;
                off = true;
                break;
            }
            su = 0;
        }
    }
}
