#include <bits/stdc++.h>
using namespace std;


pair<int,int> fmin(int j, int n, vector<int>& a) {
    int m = a[j];
    int p = j;
    for (int i=j; i<n; i++) {
        if (a[i] < m) {
            m = a[i];
            p = i;
        }
    }
    return {m,p};
}

void movtpos(int to, int from, vector<int>& a) {
    for (int i=from; i>to; i--) swap(a[i], a[i-1]);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int pos = 0;
        while (pos < n) {
            pair<int,int> x = fmin(pos, n, a); 
            movtpos(pos, x.second, a);
            if (pos == x.second) pos++;
            else pos = x.second;
        }

        for (int x : a)
            cout << x << " ";
        cout << endl;
    }
}
