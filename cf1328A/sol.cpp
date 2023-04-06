#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        if (a % b != 0) {
            long long k = a/b;
            cout << (k + 1)*b - a << endl;
        } else {
            cout << 0 << endl;
        }
    }

}
