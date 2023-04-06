#include <bits/stdc++.h>
using namespace std;


set<string> pals(string s) {
    set<string> subpals;
    if (s.size() == 1)
        return subpals; 

    vector<pair<int, int>> is;
    for (int i=0; i<(int)s.size() - 1; i++) {
        int ii = i;
        int jj = i+1;

        while (ii >= 0 && jj < (int)s.size() && s[ii] == s[jj]) { 
            is.push_back({ii, jj});
            ii--;
            jj++;
        }
    }
    for (int i=0; i<(int)s.size(); i++) {
        int ii = i - 1;
        int jj = i + 1;

        while (ii >= 0 && jj < (int)s.size() && s[ii] == s[jj]) {
            is.push_back({ii, jj});
            ii--;
            jj++;
        }
    }

    for (auto& i_j : is) {
        string ns = "";
        for (int i=i_j.first; i<=i_j.second; i++)
            ns.push_back(s[i]);
        subpals.insert(ns);
    }

    return subpals;
}


int main() {
    string s;
    while (cin >> s) {
        for (const string& pal : pals(s))
            cout << pal << endl;
        cout << endl;
    }
}
