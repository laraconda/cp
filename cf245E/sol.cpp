#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int c=0;
    vector<int> a;
    bool p = (s[0] == '+');
    for (int i=0; i<s.size(); i++) {
        if (p && s[i] == '+') c++;
        else if (p && s[i] == '-') {
            a.push_back(c);
            c = 1;
            p = false;
        }
        else if (!p && s[i] == '-') c++;
        else if (!p && s[i] == '+') {
            a.push_back(c);
            c = 1;
            p = true;
        }
    }
    a.push_back(c);


    int ii = 0;
    int oo = 0;
    int res = 0;
    for (int i=0; i<a.size(); i++) {
        if (i % 2 == 0) {
            ii += a[i];
            oo = max(oo - a[i], 0);
        } else {
            ii = max(ii - a[i], 0);
            oo += a[i];
        } 
        res = max(res, max(ii, oo));
    }
    cout << res << endl;
    
}
