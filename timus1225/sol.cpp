#include <bits/stdc++.h>
using namespace std;

int a[50];
long long fact[50];

long long cb(int n, int m) {
    long long res = 1;
    for (int i=m+1; i<=n; i++)
        res *= i;
    res /= fact[n-m];
    return res;
}

int main() {
    int n;
    cin >> n;

    fact[0] = 1;
    for (int i=1; i<=n; i++)
        fact[i] = i*fact[i-1];

    long long res = 1;
    if (n >= 3) {
        int m = 1;
        for (int i=n-2; i>= n/2; i--)
            res += cb(i, m++); 
    } 
     
    cout << res * 2 << endl;

}
