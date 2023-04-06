#include <bits/stdc++.h>
using namespace std;

const int MXN = 60000;
bitset<MXN> bs;
vector<int> primes;


bool isprime(int n) {
    if (n < MXN) return bs[n];
    for (int p : primes) {
        if (p > sqrt(n)) break;
        if (n % p == 0) return false;
    }
    return true;
}

void sieve() {
    bs.set();
    bs[0] = 0; bs[1] = 0;
    for (int i=2; i<MXN; i++) {
        if (bs[i] == 0) continue;
        for (long long j=(long long)i*i; j<MXN; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    sieve();
    
    int L, U;
    while (cin >> L >> U) {
        long long mi1;
        long long mi2;
        long long ma1;
        long long ma2;
        long long mi = INT_MAX;
        long long ma = 0;
        long long count = 0;
        long long lp = 0;
        for (long long i=L; i<=U; i++) {
            if (isprime(i)) {
                if (lp != 0) {
                    int dist = i - lp;
                    if (dist < mi) {
                        mi = dist;
                        mi1 = lp;
                        mi2 = i;
                    }

                    if (dist > ma) {
                        ma = dist;
                        ma1 = lp;
                        ma2 = i;
                    }
                }
                lp = i;
                count++;
            }
        }
        
        if (count <= 1) {
            cout << "There are no adjacent primes." << endl;
        } else {
            cout << mi1 << "," << mi2 << " are closest, " <<
                ma1 << "," << ma2 << " are most distant." << endl;
        }
    }
}
