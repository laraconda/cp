#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int fut(string& s, int ii, char c) {
    int j = ii;
    for (int i=ii+1; i<s.size(); i++) 
    {
        if (s[i] != c) break;
        j = i;
    }
    return j;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        ll n, a, b;
        cin >> n>> a >> b;
        string s;
        cin >> s;

        ll c = n * a + (n+1)*b;
        int l = 0;
        int j = -1;
        for (int i=0; i<n; i++) {
            if (i <= j) continue;
            if (s[i] == '0') {
                j = fut(s, i, '0');
                if (l == 0) {
                    if (j == n-1) {
                        continue;
                    } else {
                        c +=b;
                        c +=a;
                    }
                } else {
                    if (j == n-1) {
                        l = 0;
                        c += a;
                    } else {
                    c += b;
                    if (a*2 <= b*(j-i)) {
                        l = 0;
                        c += a*2;
                    } else {
                        c+=b*(j-i);                    
                    }
                    }
                }     
            } else {
                j = fut(s, i, '1');
                c += b*(j - i + 1);
                if (l == 0)
                    l = 1;
            }
        }
        cout << c << endl;
    }
}
