#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int minop = 1e3;

bool valid(string x) {
    if (x.size() == 0) return false;
    if (x[0] == '0') return false;
    ll xn = stoll(x);
    ll y = sqrt(xn);
    return (y * y == xn);
}

void r(string& x, int i, int rem) {
    if (x.empty()) return;
    if (i == -1) {
        if (valid(x)) minop = min(rem, minop);
    } else {
        r(x, i - 1, rem);
        char b = x[i];
        x.erase(x.begin() + i);
        r(x, i - 1, rem + 1);
        x.insert(x.begin() + i, b);
    }
}

int main() {
    string n;
    cin >> n;
    r(n, (int)n.size() - 1, 0);
    if (minop == 1e3) minop = -1;
    cout << minop << endl;
}
