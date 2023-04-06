#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int a, b;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '*') {
                a = i;
                break;
            }
        }
        
        for (int i=s.size()-1; i >= 0; i--) {
            if (s[i] == '*') {
                b = i;
                break;
            }
        }
        if (a == b) {
            cout << 1 << endl;
        } else {
            int c = 2;
            int i = a;
            while (i < b) {
                for (int j=i+k; j >= i; j--) {
                    if (s[j] == '*') {
                        i = j;
                        break;
                    }
                }
                if (i < b) c++;
            }
            cout << c << endl;
        }
    }
}
