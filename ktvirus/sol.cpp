#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int i = -1;
    for (int z=0; z<min(a.size(), b.size()); z++) {
        if (a[z] != b[z]) {
            i = z;
            break;
        }
    }
    
    int j = -1;
    int ai = a.size() - 1;
    int bi = b.size() - 1;
    for (int z=0; z<min(a.size(), b.size()); z++) {
        if (a[ai] != b[bi]) {
            j = ai;
            break;
        }
        ai--;
        bi--;
    }

    int off = j - i + 1;
    int res = (int)b.size() - ((int)a.size() - off);
    if (i == -1 || j == -1) {
        res = (int)b.size() - (int)a.size();
    }
    if (res >= 0)
        cout << res << endl; 
    else
        cout << 0 << endl;

}
