#include <bits/stdc++.h>
using namespace std;

const int MXN = 1005;
int a[MXN];

void mreset() {
    for (int i=0; i<MXN; i++) {
        a[i] = 0;
    }
}


int main() {
    int t;
    cin >> t;

    for (int z=1; z<=t; z++) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        
        int moves = 0;
        for (int i=0; i<s.size() - k + 1; i++) {
            if (s[i] == '+' && (a[i] % 2) != 0) {
                for (int j=i; j<i+k; j++) {
                    a[j]++;
                }   
                moves++;
            }
            if (s[i] == '-' && (a[i] % 2) == 0){
                for (int j=i; j<i+k; j++) {
                    a[j]++;                    
                }   
                moves++;
            }
        }

        bool pos = true;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '+' && (a[i] % 2) != 0) pos = false;
            if (s[i] == '-' && (a[i] % 2) == 0) pos = false;
        }

        cout << "Case #" << z << ": ";
        if (pos)
            cout << moves << endl;
        else
            cout << "IMPOSSIBLE" << endl;

        mreset(); 
    }
}
