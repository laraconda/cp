#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        set<int, greater<int>> et;
        cin >> n;

        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            et.insert(ai);
        }
        int res = 0;
        while (!et.empty()) {
            int x = *et.begin();
            et.erase(et.begin());
            if (x % 2 == 0) {
                et.insert(x/2);
                res++;
            }
        }

        cout << res << endl;
    }

}
