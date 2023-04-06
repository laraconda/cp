#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a = n/2 * m;
        if (n % 2 != 0) a+= ceil((double)m/2);
        cout << a << endl;
    }
}
