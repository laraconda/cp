#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, B;
    cin >> R >> B;

    double q = (double)(R + 4) / 4;
    double p = sqrt(-B - R + pow((double)(R + 4)/4, 2));
    long long L = abs(p - q);
    long long W = (B + R) / L;

    cout << max(L, W) << endl;
    cout << min(L, W) << endl;
}
