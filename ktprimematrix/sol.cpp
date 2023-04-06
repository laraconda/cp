#include <bits/stdc++.h>
using namespace std;

const int MXP = 1e5;
const int MXN = 53;
vector<int> primes;
int A[MXN][MXN];
bitset<MXP> ps;

void sieve() {
    ps.set();
    ps[0] = 0; ps[1] = 0;
    for (long long i=2; i<MXP; i++) {
        if (!ps[i]) continue; 
        primes.push_back(i); 
        for (long long j=i*i; j<MXP; j+=i) ps[j] = 0;
    }
}

int main() {
    int n, b;
    cin >> n >> b;

    sieve();

    if (b < n) {
        cout << "impossible" << endl;
        return 0; 
    }
    vector<int> ns(n);
    long long s = 0;
    for (int i=1; i<=n; i++) {
        ns[i-1] = i;
        s+= i;
    }

    long long upper = 0;
    for (int i=0; i<n; i++) {
        upper += b-i;
    }
    auto p = lower_bound(primes.begin(), primes.end(), s); 
    if (*p > upper || p == primes.end()) {
        cout << "impossible" << endl;
        return 0; 
    }

    int diff = *p - s;
    int aug = diff / n;
    for (int i=0; i<n; i++) {
        ns[i] += aug;    
    }
    diff -= aug*n;
    for (int i=1; i<=diff; i++) {
        int j = ns.size() - i;
        ns[j] += 1;
    }

    int off = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int jj = j;
            jj += off;
            jj %= n;
            A[i][jj] = ns[j];
        }
        off++;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j != n-1)
                cout << A[i][j] << " ";
            else
                cout << A[i][j];
        }
        cout << endl;
    }
}
