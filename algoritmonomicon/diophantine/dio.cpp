#include <bits/stdc++.h>
using namespace std;


int extgcd (int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = extgcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool diophantine (int a, int b, int c, int& x0, int& y0, int& g) {
    g = extgcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

int main() {
    // ax + by = c;
    int a, b, c;
    cin >> a >> b >> c;

    int x0, y0, g;
    bool res = diophantine(a, b, c, x0, y0, g);
    if (res) {
        int x, y;
        for (int k=-29; k<30; k++) {
            x = x0 + k * (b/g);
            y = y0 - k * (a/g);
            cout << a << "("<< x << "), " << b <<  "("
                << y << ")" << endl;
            cout << a*x << " + " << b*y << " = " << c << endl;  
        }
        /*cout << "----" << endl;
        for (int k=0; k<30; k++) {
            x = x0 - k * (b/g);
            y = y0 + k * (a/g);
            cout << a << "("<< x << "), " << b <<  "("
                << y << ")" << endl;
            cout << a*x << " + " << b*y << " = " << c << endl;  
        }*/
    } else
        cout << "No answer" << endl;

}
