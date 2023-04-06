#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> pins(n);
        for (int i=0; i<n; i++)
            cin >> pins[i];

        vector<int> c(12);
        for (int i=0; i<n; i++)
            c[pins[i][0]-'0']++;

        int res = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (pins[i] == pins[j]) {
                    for (int z=0; z<12; z++) {
                        if (c[z] == 0) {
                            res++;
                            c[pins[j][0]-'0']--;
                            string k = to_string(z);
                            pins[j][0] = k[0];
                            c[z]++;
                            break;
                        }
                    }
                   
                }
            }
        }

        cout << res << endl;
        for (auto s : pins)
            cout << s << endl;

    
    }

}
