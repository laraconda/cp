#include <bits/stdc++.h>
using namespace std;

bool valid(string& s) {
    int c = 0;
    for (int i=0; i<s.size(); i++) {
       if (s[i] == '(') {
        c++; 
       } else c--;
    }
    return (c == 0);
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    if (valid(s)) {
        int res = 0;
        int lastw = -1;
        int w = 0;
        int c = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                c++;
            } else c--;
            if (s[i] == ')' && c < 0) {
                if (lastw == -1)
                    lastw = i; 
                w++;
            } 
            if (w && c == 0) {
                res += i - lastw + 1; 
                w = 0;
                lastw = -1;
            }
        }
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
}
