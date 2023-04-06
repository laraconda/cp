#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int last = -1;
        bool pos = false;
        int clock = 0;
        int aclock = 0;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            a[i] = ai;
            if (last != -1 && ai == last + 1)
                aclock++;
            if (last != -1 && ai == last - 1)
                clock++;
            last = ai;
        }
        if (clock >= n-2 || aclock >= n-2)
            pos = true;

        if (pos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        a.clear();
    }
}
