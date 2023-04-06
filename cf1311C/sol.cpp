#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> count(30);
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> fs(s.size());
        for (int i=0; i<m; i++) {
            int pi;
            cin >> pi;
            fs[pi-1]++;
        }

        fs[n-1] += 1;
        for (int i=(int)fs.size()-2; i>=0; i--) {
            fs[i] += fs[i+1];
        }

        for (int i=0; i<(int)fs.size(); i++) {
            count[s[i] - 'a'] += fs[i];   
        }

        for (int i=0; i<26; i++) {
            cout << count[i] << " ";
        }
        cout << endl;
    }
}
