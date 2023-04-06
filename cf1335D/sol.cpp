#include <bits/stdc++.h>
using namespace std;

int getp(int i, int j) {
    if (j % 3 == 0) {
        return j + 1;
    } else if (j % 3 == 1) {
        return j + 1; 
    } else {
        return j-2;
    }
}

int main() {
    int t;
    cin >> t;

    cin.ignore();
    while(t--) {

        vector<string> ss;
        for (int i=0; i<9; i++) {
            string s;
            getline(cin, s); 
            ss.push_back(s);
        }

        vector<pair<int, int>> ones;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (ss[i][j] == '1') {
                    int jj = getp(i, j);    
                    ones.push_back({i, jj});
                }
            }
        }

        for (auto x : ones) {
            int i = x.first;
            int j = x.second;
            ss[i][j] = '1';
        }
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << ss[i][j];
            }
            cout << endl;
        }
    }
}
