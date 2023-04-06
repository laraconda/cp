#include <bits/stdc++.h>
using namespace std;

const long long MXN = 50000;
bitset<MXN> bs;
vector<int> primes;


void sieve(long long k) {
    bs.set();
    bs[0] = 0; bs[1] = 0; bs[2] = 1;
    primes.push_back(2);
    for (long long i=3; i<MXN; i+=2) {
        if (!bs[i]) continue;
        primes.push_back(i);
        for (long long j=i*i; j<MXN; j += i) bs[j] = 0;
    }
}


deque<pair<int, int>> factors(int m) {
    deque<pair<int, int>> dq;
    for (int p : primes) {
        if (p > sqrt(m)) break;
        int count = 0;
        while(m % p == 0) {
            count++;
            m /= p;
        }
        if (count != 0)
            dq.push_back({p, count});
    }
    if (m > 1) dq.push_back({m, 1});
    return dq; 
}


int main() {
    sieve(MXN);

    int n, m;
    while (cin >> n >> m) {
        deque<pair<int, int>> factsm = factors(m);

        bool divides = true;
        for (pair<int, int> fm : factsm) {
            int i = 1;
            int tmp = fm.first;
            while (tmp <= n && fm.second > 0) {
                while (tmp % fm.first == 0 && fm.second > 0) {
                    tmp /= fm.first;
                    fm.second--;
                }
                tmp = fm.first * ++i;
            }
            if (fm.second) {
                divides = false;
                break;
            }
        }
        
        if (mtrue)
            divides = true;  // false on kattis

        if (divides)
            cout << m << " divides " << n << "!" << endl;
        else
            cout << m << " does not divide " << n << "!" << endl;
    }
} 
