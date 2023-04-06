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

        int ans = 1e9;
        for (char c='a'; c<='z'; c++) {
            int i =0;
            int j = n-1;
            bool pal = true;
            while (i < j) {
                while (i < n && s[i] == c) i++;
                while (j >= 0 && s[j] == c) j--;
                if (i < j && i < n && j >= 0 && s[i] != s[j]) {
                    pal = false;
                    break;
                } else {
                    i++;
                    j--;
                }
            }

            if (pal) {
                int del = 0;
                int i=0;
                int j = n-1;
                while (i < j) {
                    if (s[i] == c && s[j] != c) {
                        del++;
                        i++;
                    } else if (s[i] != c && s[j] == c) {
                        del++;
                        j--;
                    } else {
                        i++;
                        j--;
                    }
                }
                ans = min(ans, del);
            }
        }
        if (ans == 1e9) ans = -1;
        cout << ans << endl;
    }
}
