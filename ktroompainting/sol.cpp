#include <bits/stdc++.h>
using namespace std;

long long my_lower_bound(int ci, int n, vector<long long>& cans) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long val = cans[mid];
        if (val < ci) {
            low = mid + 1;
        } else if (val > ci) {
            high = mid - 1; 
        } else {
            return val; 
        }
    }
    return cans[low];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> cans(n);
    for (int i=0; i<n; i++) {
        long long ci;
        cin >> ci;
        cans[i] = ci;
    }

    sort(cans.begin(), cans.end());

    long long more = 0;
    while (m--) {
        int ci;
        cin >> ci;
        long long val = my_lower_bound(ci, n, cans);
        more += (val - ci);
    }

    cout << more << endl;
}
