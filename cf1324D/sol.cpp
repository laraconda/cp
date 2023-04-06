#include <bits/stdc++.h>
using namespace std;

bool msort(pair<long long, long long> a, pair<long long, long long> b) {
    long long diffa = a.first - a.second;
    long long diffb = b.first - b.second;
    return (diffa < diffb);
}

int bsearch(int l, int h, int i, vector<pair<long long, long long>>& vs) {
    while (l <= h) {
        int mid = l + (h - l)/2;
        long long diff = vs[i].first + vs[mid].first - vs[i].second - vs[mid].second; 
        if (diff <= 0) {
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> vs(n);
    for (int i=0; i<n; i++) {
        long long ai; 
        cin >> ai;
        vs[i].first = ai;
    }
    
    for (int i=0; i<n; i++) {
        long long bi; 
        cin >> bi;
        vs[i].second = bi;
    }

    sort(vs.begin(), vs.end(), msort);

    long long res = 0;
    for (int i=0; i<n; i++) {
        int j = bsearch(i+1, n-1, i, vs);
        res += n - j;
    }

    cout << res << endl;
}
