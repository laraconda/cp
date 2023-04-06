#include <bits/stdc++.h>
using namespace std;


int main () {
    int t;
    cin >> t;

    for (int i=1; i<=t; i++) {
        int n;
        cin >> n;
        string p;
        cin >> p;
        string k(p);
        

        for (int j=0; j<p.size(); j++) {
            if (p[j] == 'E')
                k[j] = 'S';
            else
                k[j] = 'E';
        }

        cout << "Case #" << i << ": " << k << endl;
    }
}
