#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> mmap;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int y;
        cin >> y;
        mmap[s].push_back(y);
    }

    for (pair<const string, vector<int>>& x : mmap) {
        sort(x.second.begin(), x.second.end()); 
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        string s;
        cin >> s;
        int t;
        cin >> t;
        cout << mmap[s][t-1] << endl;
    }
}
