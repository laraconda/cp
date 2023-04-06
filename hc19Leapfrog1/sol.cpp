#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        string s;
        cin >> s;

        int e = 0;
        int b = 0;
        for (char ci : s) {
            if (ci == '.')
                e++;
            if (ci == 'B')
                b++;
        }

        cout << "Case #" << i << ": ";
        if (b >= e && e > 0)
            cout << "Y" << endl;
        else 
            cout << "N" << endl;
    }
}
