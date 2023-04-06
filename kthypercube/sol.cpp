#include <bits/stdc++.h>
using namespace std;

long long getpos(int i, string& s) {
    if ((int)s.size() - i == 1) {
        if (s[i] == '0') return 1;
        else return 2;
    } else {
        long long pos;
        if (s[i] == '0') {
            pos = getpos(i + 1, s);
        } else {
            pos = pow(2, (int)s.size() - i);
            long long q = getpos(i + 1, s);
            pos += - q + 1; 
        }
        return pos;
    }
}

int main() {
    int n;
    cin >> n;
    string s1, s2;

    cin >> s1 >> s2;

    long long a = getpos(0, s1);
    long long b = getpos(0, s2);

    cout << b - a - 1 << endl;
}
