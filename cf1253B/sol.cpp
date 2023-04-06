#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6+4;

int main() {
    int n;
    cin >> n;

    multiset<int> ms;
    vector<int> is = {0};
    vector<int> count(MXN);
    vector<int> sect(MXN);
    int res = 0;
    bool pos = true;
    int sec = 0;
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        if (ai > 0) {
            ms.insert(ai);
            if (sect[ai] == sec) {
                count[ai]++;
                if (count[ai] > 1) pos=false;
            } else {
                count[ai] = 1;
                sect[ai] = sec;
            }
        } else
            if (ms.count(abs(ai)))
                ms.erase(abs(ai));
            else pos = false;
        if (ms.empty()) {
           res++;
           sec++;
           is.push_back(i+1);
        }
    }
    if (!ms.empty()) pos = false;
    if (is.back() != n) is.push_back(n);
    if (res == 0) pos = false;
    if (!pos) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
        for (int i=1; i<is.size(); i++)
            cout << is[i]-is[i-1] << " ";
        cout << endl;
    }
    

}
