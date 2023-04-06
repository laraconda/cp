#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c = -1;
    for (int i=0; i<n; i++) {
        int m = n - i*4;
        if (m < 0) break;
        if ((m % 7) == 0) {
            c = i;
            break;
        }
    }
    if (c == -1)
        cout << c;
    else {
        for (int i=0; i<c; i++) {
            cout << 4;
        }
        int m = n - c*4;
        for (int i=0; i<m/7; i++)
            cout << 7;
    }
    cout << endl;
}
