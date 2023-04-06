#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    string res = "";

    int depth = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(')
            depth += 1;
        if (depth % 2 == 0)
            res += "0";
        else
            res += "1";
        if (s[i] == ')')
            depth -= 1;
    }

    cout << res << endl;
}
