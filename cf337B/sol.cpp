#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

void sim(int p, int q) {
    int g = __gcd(p, q);
    while (g != 1) {
        p/=g; q/=g;
        g = __gcd(p, q);
    }
    cout << p << "/" << q << endl;
}

void solveW() {
    sim(b*c - d*a, b*c);
}

void solveY() {
    sim(a*d - c*b, a*d);
}

int main() {
    cin >> a >> b >> c >> d;

    if (a != b) {
        double a_c = (double)a/c; 
        double b_d = (double)b/d;
        if (a_c > b_d) {
            solveY();
        } else {
            solveW();
        }
    } else {
        if (c > d) {
            solveW(); 
        } else if (c < d) {
            solveY();
        } else {
            cout << 0 << "/" << 1 << endl;
        }
    }
}
