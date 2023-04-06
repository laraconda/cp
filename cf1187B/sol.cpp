#include <bits/stdc++.h>
using namespace std;


map<char, vector<int> > ls;
map<char, int> pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    string s;
    cin >> n >> s >> m;

    for (int i=0; i<n; i++)
        ls[s[i]].push_back(i+1);

    string ti;
    while(m--) {
        cin >> ti;
        int mx = 0;
        for (int i=0; i<ti.size(); i++) {
            int l = ti[i];
            int p = pos[l];
            if (ls[l][p] > mx)
                mx = ls[l][p];
            pos[l]++;
        }
       
        cout << mx << endl;
        
        pos.clear();
    }
}
