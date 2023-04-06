#include <bits/stdc++.h>
using namespace std;


vector<long long> pows;

void mfill() {
    pows.push_back(1);
    for (int i=1; i<31; i++) {
        pows.push_back(pow((long long)2, i)); 
    }
}

int main() {
    int t;
    cin >> t;
    mfill();
    while (t--) {
        int n;
        cin >> n;

        long long a = 0;
        long long b = 0;

        a += pows[n];
        for (int i=1; i<n; i++) {
            if (i < n/2) {
                a += pows[i];
            } else {
                b += pows[i];
            }
        }
        cout << abs(a - b) << endl;
    }

}
