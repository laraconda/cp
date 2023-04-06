#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int m = -1;
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        arr[i] = ai;
        if (m == -1 || m < ai)
            m = ai;
    }

    int ml = 0;
    int l = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == m)
            l++;
        else
            l = 0;
        if (l > ml)
            ml = l;
    }

    cout << ml << endl;
}
