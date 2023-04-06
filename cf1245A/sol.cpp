#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {

        int a, b;
        cin >> a >> b;

        
        bool finite = false;
        if (__gcd(a, b) == 1)
            finite = true;

        if (finite)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;
    }
}
