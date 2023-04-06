#include <bits/stdc++.h>
using namespace std;

double f(int a, int b, int c, double R) {
    return (-1) * a * (double)pow(R, 2) + b * R + c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        double mx = 0;
        int imx = 0;
        for (int i=1; i<=n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            double R = (double)b/(2*a);
            double val = f(a, b, c, R);
            if (val > mx) {
                mx = val;
                imx = i;
            }
        }

        cout << imx << endl;
    
    }
}
