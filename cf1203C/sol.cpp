#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e14;
const int MXN = 1e6+1000;

vector<int> primes;
bitset<MXN> bs;

void sieve() {
    bs.set();
    bs[0] = 0; bs[1] = 0;
    for (int i=2; i<MXN; i++) {
        if (bs[i]) primes.push_back(i);
        for (long long j=(long long)i*i; j<MXN; j += i) bs[j] = 0;
    }
}

vector<pair<long long, int>> factors(long long k) {
    vector<pair<long long, int>> facs;
    for (int p : primes) {
        if (p > sqrt(k)) break;
        int exp = 0;
        while (k % p == 0) {
            k = k/p;
            exp++;
        }
        if (exp) facs.push_back({p, exp});
    }
    if (k > 1) facs.push_back({k, 1});
    return facs;
}

int main() {
    int n;
    cin >> n;

    sieve(); 
    vector<long long> a(n);
    long long mn = INF;
    for (int i=0; i<n; i++) {
        long long ai;
        cin >> ai;
        a[i] = ai;
        mn = min(mn, ai);
    }
    vector<pair<long long, int>> facs = factors(mn);
    for (int i=0; i<facs.size(); i++) {
        pair <long long, int> f = facs[i];
        bool pos = true;
        for (long long ai : a) {
            int exp = 0;
            while (ai % f.first == 0 && exp <= f.second) {
                exp++;
                ai /= f.first;
            }
            facs[i].second = min(facs[i].second, exp);
        }
    }

    long long c = 1;
    for (int i=0; i<facs.size(); i++) {
        if (facs[i].second == 0) continue;
            c *= facs[i].second + 1;
    }

    cout << c << endl;
}
