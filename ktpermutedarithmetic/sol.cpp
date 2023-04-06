#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;
        vector<int> seq;
        for (int i=0; i<m; i++) {
            int sei;
            cin >> sei;
            seq.push_back(sei);
        }

        int dist = abs(seq[0] - seq[1]);
        bool ari = true;
        for (int i=0; i < m - 1; i++) {
            int disti = abs(seq[i] - seq[i + 1]);
            if (disti != dist)
                ari = false;
        }
        
        sort(seq.begin(), seq.end());
        
        dist = abs(seq[0] - seq[1]);
        bool perari = true;
        for (int i=0; i < m - 1; i++) {
            int disti = abs(seq[i] - seq[i + 1]);
            if (disti != dist)
                perari = false;
        }

        if (ari) {
            cout << "arithmetic" << endl; 
        } else if (perari) {
            cout << "permuted arithmetic" << endl;
        } else {
            cout << "non-arithmetic" << endl; 
        }
    
    }
}
