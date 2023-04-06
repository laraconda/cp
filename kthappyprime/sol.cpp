#include <bits/stdc++.h>
using namespace std;


const int MXN = 1e4 + 4;

bool prime(int K) {
    if (K == 1)
        return false;
    if (K == 2)
        return true;
    if (K % 2 == 0)
        return false;
    for (int i=3; i<=(int)sqrt(K); i+=2) {
        if (K % i == 0)
            return false;
    }
    return true;
}

bool hp(int K) {
    if (!prime(K)) return false; 
    bitset<MXN> bs;
    long long a = K;
    long long b = 0;
    while (a != 1) {
        while (a > 0) {
            b += pow(a % 10, 2);
            a /= 10;
        }
        if (b == 1)
            return true;
        if (bs[b])
            return false;
        bs[b] = 1;
        while (b > 0) {
            a += pow(b % 10, 2);
            b /= 10;
        }
        if (a == 1)
            return true;
        if (bs[a])
            return false;
        bs[a] = 1;

        if (a > MXN || b > MXN)
            return false;
    }
    return true;

}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int id, K;
        cin >> id >> K;
        if (hp(K)) {
            cout << id << " " << K << " YES" << endl;
        } else
            cout << id << " " << K << " NO" << endl;
    }
}
