#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> mm;

bool issu(string& a, string& b) {
    if (a.size() > b.size()) return false;
    int n = a.size()-1;
    int m = b.size()-1;
    for (int i=0; i<a.size(); i++) {
        if (a[n-i] != b[m-i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string name;
        cin >> name;
        int k;
        cin >> k;
        while (k--) {
            string nu;
            cin >> nu;
            mm[name].insert(nu);
        }
    }
    cout << mm.size() << endl;
    for (auto& name_v : mm) {
        vector<string> v;
        for (auto x : name_v.second) {
            v.push_back(x);
        }
        set<int> del;
        for (int i=0; i<v.size(); i++) {
            string x = v[i];
            for (int j=0; j<v.size(); j++) {
                if (i == j) continue;
                string y = v[j];
                if (issu(x, y)) {
                    del.insert(i);
                }
            }
        }
        int k = v.size() - del.size();
        cout << name_v.first << " " << k << " ";
        for (int i=0; i<v.size() ; i++) {
            if (del.count(i) == 0) {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }
}
