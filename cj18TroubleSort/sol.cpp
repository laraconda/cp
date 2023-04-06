#include <bits/stdc++.h>
using namespace std;

vector<int> es;
vector<int> os;

int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        int n;
        cin >> n;
        int ai;
        for (int j=0; j<n; j++) {
            cin >> ai;
            if (j & 1)
                os.push_back(ai);
            else
                es.push_back(ai);
        }
        sort(os.begin(), os.end());
        sort(es.begin(), es.end());

        int k = -1;
        for (int j=0; j<os.size(); j++) {
            if (es[j] > os[j]) {
                k = j*2;
                break;
            }
            if (j+1 >= es.size()) continue;
            if (os[j] > es[j+1]) {
                k = j*2 + 1;
                break;
            }    
        }

        cout << "Case #" << i << ": ";
        if (k == -1)
            cout << "OK" << endl;
        else
            cout << k << endl;

        es.clear();
        os.clear();
    }
}
