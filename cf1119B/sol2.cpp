#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool pos(int m, vector<ll> a, int h) {
    sort(a.begin(), a.begin() + m + 1);
    ll s1 = 0;
    for (int i=0; i<=m; i+=2) {
        int x = a[i];
        int y = (i+1 <= m)? a[i+1] : 0;
        s1 += max(x, y);
    }

    ll s2 = 0;
    for (int i=m; i>=0; i-=2) {
        int x = a[i];
        int y = (i-1>=0)?a[i-1]: 0;
        s2+=max(x,y);
    }

    return (s1 <= h || s2 <= h);
}

int bs(vector<ll>& a, int h) {
    int l = 0;
    int hi = a.size() - 1;
    while (l <= hi) {
        int mid = l + (hi - l)/2;
        if (pos(mid, a, h)) {
            l = mid + 1;
        } else {
            hi = mid - 1; 
        }
    }
    return hi;

}

int main() {
    int n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (int i=0; i<n;i++) {
        cin >> a[i];
    }

    int res = bs(a, h);
    cout << res + 1<< endl;
}
