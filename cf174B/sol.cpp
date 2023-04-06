#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    s.push_back('.');

    vector<int> ps;
    int c = 0;
    for (int i=0; i<s.size(); i++) {
        c++;
        if (s[i] == '.') {
            ps.push_back(--c);
            c = 0;
        }
    }

    vector<string> a;
    string ns;
    int p = 0;
    bool pos = true;
    int eat = 0;
    if (ps[0] > 8 || ps[0] == 0) pos = false;
    if (ps.size() < 2) pos = false;
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == '.') {
            p++;
            if (ps[p] <= 1 && p < (int)ps.size()-1) pos = false;
            if (ps[p] > 11) pos = false;

            if (ps[p] <= 3 && p < (int)ps.size()-1) eat = 1; 
            if (p == (int)ps.size()-1) eat = (int)s.size()-2 - i;
            if (ps[p] > 3) eat = 3;
        }
        ns.push_back(s[i]);
        if (s[i] != '.') {
            eat--;
            if (eat == 0) {
                a.push_back(ns);
                ns = "";
            }
        }
    }
    if (ps.back() > 3 || ps.back() == 0) pos = false;

    if (pos) {
        cout << "YES" << endl;
        for (string sa: a) {
            cout << sa << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}
