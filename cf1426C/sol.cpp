#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m = 1e9;
        for (int i=1; i<=(int)sqrt(n) + 1; i++) {
            int y = ceil((double)n/i);
            int mm = i-1 + y-1;
            m = min(m, mm);
        }
        cout << m << endl;
    }
}
