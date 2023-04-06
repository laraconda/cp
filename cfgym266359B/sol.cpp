#include <bits/stdc++.h>
using namespace std;

bool ispos(vector<int>& v) {
    if ((int)v.size() % 2 == 0) {
        bool pos = true;
        int mid = (int)v.size()/2;
        for (int i=0; i<=mid; i++) {
            if (v[i] < i)
                pos = false;
        }
        for (int i=v.size() - 1; i >= mid; i--) {
            int j = (int)v.size() - 1 - i;
            if (v[i] < j)
                pos = false;
        }
        if (pos) return true;
        pos = true;
        mid = (int)v.size()/2;
        mid--;
        for (int i=0; i<=mid; i++) {
            if (v[i] < i)
                pos = false;
        }
        for (int i=v.size() - 1; i >= mid; i--) {
            int j = (int)v.size() - 1 - i;
            if (v[i] < j)
                pos = false;
        }
        return pos;

    } else {
        bool pos = true;
        int mid = (int)v.size()/2;
        for (int i=0; i<=mid; i++) {
            if (v[i] < i)
                pos = false;
        }
        for (int i=v.size() - 1; i >= mid; i--) {
            int j = (int)v.size() - 1 - i;
            if (v[i] < j)
                pos = false;
        }
        return pos;
    }


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ns(n);
        for (int i=0; i<n; i++) {
            int ni;
            cin >> ni;
            ns[i] = ni;
        }

        if (ispos(ns)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
