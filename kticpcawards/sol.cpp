#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string u;
    string t;

    map<string, int> m;

    int count = 0;
    while(n--) {
        cin >> u >> t;
        if (m[u] == 0 && count < 12) {
            cout << u << " " << t << endl;
            count++;
            m[u] = 1;
            }
    }
}
