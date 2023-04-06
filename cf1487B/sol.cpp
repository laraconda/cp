#include <bits/stdc++.h>
using namespace std;

int cheeky_module(int i, int m) {
    int x = i % m;
    return (x == 0) ? m : x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
           cout << cheeky_module(k, n) << endl; 
        } else {
           cout << cheeky_module(cheeky_module(k, n) + ((k-1)/(n/2)), n) << endl; 
        }
    }
}
