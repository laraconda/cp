#include <bits/stdc++.h>
using namespace std;

int main() {
    string as, bs;
    cin >> as >> bs;

    map<char, char> mm;
    int k=0;
    bool pos = true;
    for (int i=0; i<as.size(); i++) {
        char a = as[i];
        char b = bs[i];
        if (mm.count(a) != 0 && mm[a] != b) 
            pos = false;
        if (mm.count(a) == 0) {
            mm[a] = b;
            if (a != b)
                k++;
        }
        if (mm.count(b) != 0 && mm[b] != a) 
            pos = false;
        if (mm.count(b) == 0) {
            mm[b] = a;
        }
    }

    map<char, bool> che;
    if (!pos) cout << -1 << endl;
    else {
        cout << k << endl;
        for (auto fs : mm) {
            if (fs.first == fs.second) continue;
            if (che.count(fs.first) == 0) {
                cout << fs.first << " " << fs.second << endl;
                che[fs.first] = true;
                che[fs.second] = true;
            } 
        }
    }
}
