#include <bits/stdc++.h>
using namespace std;


long long binpow(long long a, long long b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else {
        if (b % 2 == 0) {
            long long res = binpow(a, b / 2);
            return res * res;
        } else {
            return binpow(a, b - 1) * a; 
        }
    }
}


int bs(long long P, long long R, long long F) {
    int low = 0;
    int high = 33;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long res = P * binpow(R, mid);
        if (res <= 0) {
            high = mid - 1; 
        } else if (res <= F) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        long long P, R, F;
        cin >> P >> R >> F;
        cout << bs(P, R, F) << endl;
    }
} 
