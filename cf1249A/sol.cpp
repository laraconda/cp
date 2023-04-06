#include <bits/stdc++.h>
using namespace std;


int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        vector<int> ss(n);
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            ss[i] = ai;
        }

        sort(ss.begin(), ss.end());
        bool two = false;
        for (int i=0; i<n-1; i++) {
            if (abs(ss[i] - ss[i+1]) == 1)
                two = true;
        }

        if (two)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
}
