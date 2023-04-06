#include <bits/stdc++.h>
using namespace std;

int x, y;
bool pos() {
    if (y > 0 && x == 1) return false;
    if (x == 0) return false;
    if (y < x - 1) return false;
    if ((x % 2) == (y % 2)) return false;
    return true;
}

int main() {
    cin >> y >> x;
    if (pos()) cout << "Yes" << endl; else cout << "No" << endl;
}
