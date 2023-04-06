#include <bits/stdc++.h>
using namespace std;

vector<string> x;

void g(string& s, int d) {
    if (s != "") x.push_back(s); 
    if (s.size() == d) return;
    int c = 'a';
    while (c <= 'z') {
        s.push_back(c);
        g(s, d);
        s.pop_back();
        c++;
    }
}

bool lt(string& a, string& b) {
    if (a.size() < b.size()) return true;
    if (a.size() > b.size()) return false;
    for (int i=0; i<a.size(); i++) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    return false;
}

int main() {
    string ss;
    g(ss, 4);
    sort(x.begin(), x.end(), lt);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> m;
        for (int i=0; i<n; i++) {
            for (int j=i; j<min(n, i+5); j++) {
                m.insert(s.substr(i, j-i+1));
            }
        }
        for (string& a : x) {
            if (!m.count(a)) {
                cout << a << endl;
                break;
            }
        }
    }
}
