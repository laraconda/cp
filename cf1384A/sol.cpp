#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        for (int i=0; i<51; i++) a.push_back('a');
        cout << a << endl;
        string b;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            if (i % 2 == 0) {
                b.clear();
                for (int j=0; j<ai; j++)
                    b.push_back(a[j]);
                for (int j=ai; j<51; j++) {
                    char c = (a[j] == 'a') ? 'b' : 'a';
                    b.push_back(c);
                }
                cout << b << endl;
            } else {
                a.clear();
                for (int j=0; j<ai; j++)
                    a.push_back(b[j]);
                for (int j=ai; j<51; j++) {
                    char c = (b[j] == 'a') ? 'b' : 'a';
                    a.push_back(c);
                }
                cout << a << endl;
            }
        }
    }
}
