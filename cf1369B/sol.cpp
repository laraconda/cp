#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int j=-1;
        for (int idx=n-1; idx>0; idx--) if (s[idx] == '0'){j = idx; break;}
        int i=n;
        for (int idx=0; idx<n; idx++) if (s[idx] == '1') {i = idx;break;}
        string ans;
        for (int idx=0; idx<n; idx++)
            if (!(idx >= i && idx < j)) ans.push_back(s[idx]);
        cout << ans << endl;
    }
}
