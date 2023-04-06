#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll X;
    cin >> X;

    ll a, b;
    for (ll i=(ll)sqrt(X); i>=1; i--) {
        if (X % i == 0) {
            b = X/i;

            if (i * (b/__gcd(i, b)) == X) {
                a = i;
                break;
            }
        }
    }

    cout << a << " " << b << endl;
}

