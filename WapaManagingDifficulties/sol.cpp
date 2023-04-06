#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> as(n);
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            as[i] = ai;
        }
        vector<unordered_map<int, int>> ms(n);
        long long res = 0;
        for (int i=n-1; i>=0; i--) {
            for (int j=i+1; j<n; j++) {
               int diff = as[i] - as[j];
               ms[i][diff]++;  
               res += ms[j][diff];
            }
        }
        cout << res << endl;
    }
}
