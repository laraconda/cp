#include <bits/stdc++.h>
using namespace std;

struct Po {
    double x;
    double y;
};

typedef struct Po Po;

double dist(Po p1, Po p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {

    double d;
    int n;
    cin >> d;
    cin >> n;
    while (d != 0 && n != 0) {
    vector<Po> ns(n);
    for (int i=0; i<n; i++) {
        double xi, yi;
        cin >> xi >> yi;
        ns[i].x = xi;
        ns[i].y = yi;
    }

    int sour = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            if (dist(ns[i], ns[j]) <= d) {
                sour++;
                break;
            }
        }
    }
    int sweet = n - sour;
    cout << sour << " sour, " << sweet << " sweet" << endl;

    cin >> d;
    cin >> n;
    }
}
