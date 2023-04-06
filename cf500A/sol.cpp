#include <bits/stdc++.h>
using namespace std;

const int msize = 3*(10e4);
int arr[msize];

int main() {
    int n, t;
    cin >> n >> t;

    for (int i = 1; i<n+1; i++) {
        int ai;
        cin >> ai;
        arr[i] = ai;
    }

    string res;
    int i=1;
    while(true) {
        if (i == t) {
            res = "YES";
            break;
        }
        if (i == n) {
            res = "NO";
            break;
        }
        i += arr[i];
    }

    cout << res << endl;
}
