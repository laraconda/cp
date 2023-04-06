#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MXN = 2e5 + 3;

int lt[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;

    int l=-1;
    int r=-1;
    for (int i=0; i<q; i++) {
        char s;
        cin >> s;
        int id;
        cin >> id;
        if (s == 'L') {
            if (l == -1) {
                lt[id] = MXN;
                l = id;
                r = id;
            } else {
                int pos = lt[l]-1;
                lt[id] = pos;
                l = id;
            }  
        } else if (s == 'R') {
            if (r == -1) {
                lt[id] = MXN;
                l = id;
                r = id;
            } else {
                int pos = lt[r]+1;
                lt[id] = pos;
                r = id;
            }  
        } else {
            cout << min(abs(lt[l] - lt[id]), abs(lt[r] - lt[id])) << endl; 
        }
    }
}
