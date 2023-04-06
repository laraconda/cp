#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int ith=1; ith<=t; ith++) {
        int n, k;
        cin >> n >> k;
        bool on = (k + 1) % ((int)pow((int)2, n)) == 0;
        if (on)
            cout << "case #" << ith << ": ON" << endl;
        else
            cout << "case #" << ith << ": OFF" << endl;

    }
}
