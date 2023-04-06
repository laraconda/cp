#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> cols(n);
        vector<int> ns(n);

        int z = -1;
        for (int i=0; i<n; i++) {
            int ki;
            cin >> ki;
            ns[i] = ki;
            if (i == 0) {
                cols[i] = 0;
            }
            if (i > 0) {
                if (ki == ns[i-1]) {
                    cols[i] = cols[i-1];
                    z = i;
                } else {
                    if (cols[i-1] == 0) {
                        cols[i] = 1;
                    } else if (cols[i-1] == 1) {
                        cols[i] = 0;
                    }
                }
            }
        }

        if (cols[0] == cols[n-1] && ns[0] != ns[n-1]) {
            if (z != -1) {
                cols[z] = (cols[z] == 0) ? 1 : 0;
                for (int i=z+1; i<n; i++) {
                    if (ns[i] == ns[i-1]) {
                        cols[i] = cols[i-1];
                    } else {
                        if (cols[i-1] == 0) {
                            cols[i] = 1;
                        } else if (cols[i-1] == 1) {
                            cols[i] = 0;
                        }
                    }
                }
            } else {
                cols[n-1] = 2;
            }
        }

        vector<int> count(3);
        for (int i=0; i<n; i++) {
            count[cols[i]]++;
        }

        int c = 0;

        if (count[0]) c++;
        if (count[1]) c++;
        if (count[2]) c++;

        cout << c << endl;

        for (int i=0; i<n-1; i++) {
            cout << cols[i] + 1 << " ";
        }
        cout << cols[n-1] + 1<< endl;
    }
}
