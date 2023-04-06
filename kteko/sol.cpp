#include <bits/stdc++.h>
using namespace std;


vector<long long> hs;
vector<long long> chs;


long long wood(long long h) {
    auto it = upper_bound(hs.begin(), hs.end(), h);
    int i = distance(hs.begin(), it);
    long long amount = ((int)hs.size() - i);
    return (chs.back() - chs[i] + hs[i]) - h * amount;
}

long long bs(long long M, long long H) {
    long long low = 0;
    long long high = H;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long w = wood(mid);
        if (w < M) {
            high = mid - 1; 
        } else if (w > M) {
            low = mid + 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int main() {
    int N;
    cin >> N;
    long long M;
    cin >> M;
    long long H = -1; 
    for (int i=0;i<N;i++) {
        long long hi;
        cin >> hi;
        hs.push_back(hi);
        H = max(H, hi); 
    }

    sort(hs.begin(), hs.end());

    chs.push_back(hs[0]);
    for (int i=1; i<(int)hs.size(); i++) {
        chs.push_back(hs[i] + chs.back());
    }

    long long res = bs(M, H);
    cout << res << endl;
}
