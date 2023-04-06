#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        k[a[i]]++;
    }

    int s = 0;
    int ns = 0;
    for (auto e_c : k) {
        if (e_c.second == 1) s++;
        if (e_c.second > 2) ns++;
    }
    if (s % 2 == 0) {
        cout << "YES" << endl;
        int c = 0;
        for (int i=0; i<n; i++) {
            if (k[a[i]] == 1) {
                if (c < s/2) {
                    cout << "A";
                    c++;
                }
                else cout << "B";
            } else {
                cout << "B";
            }
        }
        cout << endl;
    } else {
        if (ns > 0) {
            cout << "YES" << endl;
            int c = 0;
            int e = -1;
            for (int i=0; i<n; i++) {
                if (k[a[i]] == 1) {
                    if (c < s/2) {
                        cout << "A";
                        c++;
                    }
                    else cout << "B";
                } else if (k[a[i]] > 2) {
                    if (e == a[i]) {
                        cout << "B";
                    } else if (e == -1) {
                        cout << "A";
                        e = a[i];
                    } else {
                        cout << "B"; 
                    }
                } else {
                    cout << "B";
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
