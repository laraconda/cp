#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e7;
bitset<MXN> bs;
bitset<MXN> bs2;

void sieve() {
    bs.set();
    bs[0] = 0; bs[1] = 0;
    for (long long j=4; j < MXN; j+=2) bs[j] = 0;
    for (long long i=3; i < sqrt(MXN); i += 2) {
        if (!bs[i]) continue;
        for (long long j=i * i; j < MXN; j+=i) bs[j] = 0;
    }

}
void sieve2() {
    bs2.set();
    bs2[0] = 0; bs2[1] = 0;
    for (long long i=2; i < MXN; i++) {
        if (!bs2[i]) continue;
        for (long long j=i * i; j < MXN; j+=i) bs2[j] = 0;
    }
}

int main() {

    sieve();
    sieve2();

    for (int i=0; i<MXN; i++) {
        if (bs[i] != bs2[i]) {
            cout << "BAD: " << i << endl;
            break;
        }
    }
    
}
