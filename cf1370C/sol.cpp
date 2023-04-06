#include <bits/stdc++.h>
using namespace std;

bool power(int x) {
    int c = 0;
    for (int i=0; i<=32; i++) {
        c += (x >> i) & 1;
    }
    return (c == 1);
}

bool prime(int x) {
    if (x < 3) return false;
    for (int i=2; i<=sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 0;
        while (n > 1) {
            s++;
            if (n % 2 == 0) {
                if (power(n))  
                    n -= 1;
                else if (prime(n/2))
                    n = 2;
                else
                    n = 1;
            } else {
                n = 1;
            }
        }
        if (s % 2 == 0) {
            cout << "FastestFinger" << endl;
        } else {
            cout << "Ashishgup" << endl;
        }
    }
} 
