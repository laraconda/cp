#include <bits/stdc++.h>
using namespace std;

const int MOD = 131071;
const int MXN = 10006;
int a[MXN];

void prec() {
    for (int i=0; i<MXN; i++) {
        if (i < 60) {
            a[i] = ((long long)pow(2, i)) % MOD;
        } else {
            int j = ceil((double)i/2);
            int k = i/2;
            a[i] = ((long long)a[j] * a[k]) % MOD;
        }
    }
}

int main() {
    prec();
    
    string s;
    while(cin >> s) {
        string s1 = "";
        while (s[s.size() - 1] != '#') {
            cin >> s1;
            s.append(s1);
        }
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '#') break;
            if (s[i] == '1') {
                res = (res + a[s.size() - i - 2]) % MOD;
            } 
        }
        if (res == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
