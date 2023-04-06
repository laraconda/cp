#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, b2;
    cin >> n >> a >> b;
    b2 = b;
    b*=2;
    int d = 0;
    for (int i=0; i<n; i++) {
        int g;
        cin >> g;
        if (g == 1) {
            if (a > 0) {
                a--;
            } else if (b2 > 0) {
                b2--;
                b--;
            } else if (b > 0){
                b--;
            } else {
                d++;
            }
        } else {
            if (b2 > 0) {
                b2--;
                b--;
                b--;
            } else {
                d++;
                d++;
            } 
        }
    }
    cout << d << endl;
}
