#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    
    int n, s, t;
    while (T--) {
        cin >> n >> s >> t;
        cout << n - min(s, t) + 1 << endl;
    }

}
