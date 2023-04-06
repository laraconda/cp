#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4+6;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b(MXN);
        for (int i=0; i<4*n; i++) {
            int ai;
            cin >> ai;
            a.push_back(ai);
            b[ai]++;
        }
        sort(a.begin(), a.end());
        int lastarea = -1;
        bool pos = true;
        for (int i=0; i<2*n; i++) {
            int j = 4*n - 1 - i;
            int area = a[i]*a[j];
            if (area != lastarea && lastarea != -1)
                pos = false;
            lastarea = area;
        }

        for (int i=0; i<MXN; i++) {
            if (b[i] % 2 != 0)
                pos = false;
        }
        if (pos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        a.clear();
    }
}
