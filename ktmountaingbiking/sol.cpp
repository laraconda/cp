#include <bits/stdc++.h>
using namespace std;

double acc(double g, double d) {
    d = (d*M_PI)/180;
    return g*cos(d);
}

int main() {
    int N;
    cin >> N;
    double g;
    cin >> g;

    vector<pair<double, double>> ps(N);
    for (int i=0; i<N; i++) {
        double D, d;
        cin >> D >> d;
        ps[i] = {D, d};
    }
    for (int i=0; i<N; i++) {
        double v0 = 0;
        for (int j=i; j<N; j++) {
            double a = acc(g, ps[j].second);
            double v = sqrt(pow(v0, 2) + a * ps[j].first * 2);
            v0 = v;
        }
        cout.precision(12);
        cout << v0 << endl;
    }
}
