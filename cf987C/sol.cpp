#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int costs[n];
    int sizes[n];

    int middle[n];

    for (int i=0; i<n; i++) {
        int si;
        cin >> si;
        sizes[i] = si;

        middle[i] = 0;
    }
    for (int i=0; i<n; i++) {
        int ci;
        cin >> ci;
        costs[i] = ci;
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (sizes[i] < sizes[j]) {
                if (middle[j] == 0 || middle[j] > costs[i] + costs[j]) {
                    middle[j] = costs[i] + costs[j];
                }
            }
        }
    }

    int minc = -1;
    int cc;
    for (int i=0; i<n; i++) {
        if (middle[i] == 0)
            continue;
        for (int j=i+1; j<n; j++) {
            if (sizes[i] < sizes[j]) {
                cc = middle[i] + costs[j];
                if (minc == -1 || minc > cc)
                    minc = cc;
            }
        }
    }

    cout << minc << endl;
}
