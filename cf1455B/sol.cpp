#include <bits/stdc++.h>
using namespace std;

int gauss(int i) {
    return (i*(i+1))/2;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        for (int i=0; true; i++) {
            int g = gauss(i);
            if (g > x) {
                int diff = g - x;
                if (diff > 1) {
                    cout << i << endl;
                    break;
                }
                else {
                    cout << i + 1 << endl;
                    break;
                }
            } else if (g == x) {
                cout << i << endl;
                break;
            } 
        }
    }
}
