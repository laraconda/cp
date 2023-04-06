#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long res;
    if (n % 2 == 0) {
        res = (long long)pow(2, (n/2));
    } else {
        res = 0;
    }
    cout << res << endl;
}
