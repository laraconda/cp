#include <bits/stdc++.h>
using namespace std;

void A(vector<int>& v) {
    for (int i=0; i<v.size()-1; i+=2) {
        int t = v[i];
        v[i] = v[i+1];
        v[i+1] = t;
    }
}

void B(vector<int>& v) {
    int n = v.size()/2;
    for (int i=0; i<n; i++) {
        int t = v[i];
        v[i] = v[i + n];
        v[i + n] = t; 
    }
}

bool check(vector<int>& v) {
    for (int i=0; i<v.size()-1; i++) {
        if (v[i] > v[i+1]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> ns;
    for (int i=0; i<2*n; i++) {
        int ni;
        cin >> ni;
        ns.push_back(ni);
    }

    int r = 1e9;
    for (int i=0; i<max(4, 2*n); i++) {
        if (check(ns))
            r = min(r, i);
        
        if (i % 2 == 0) A(ns);
        else B(ns);
    }
    for (int i=0; i<max(4, 2*n); i++) {
        if (check(ns))
            r = min(r, i);
        
        if (i % 2 == 0) B(ns);
        else A(ns);
    }
    r = (r == 1e9) ? -1 : r;
    cout << r << endl;
}
