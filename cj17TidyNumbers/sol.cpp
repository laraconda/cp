#include <bits/stdc++.h>
using namespace std;

const long long MXN = 1e7 + 3;
long long *a = new long long[MXN];

int main() {
    int t;
    cin >> t;

    for (int i=1; i<10; i++)
        a[i-1] = i;
    
    int b = 1;
    long long bb = 0;
    long long nbb = 0;
    long long be = 8;
    long long appi = 9;

    while(b < 18) {
        for (int i=bb; i<=be; i++) {
            string s = to_string(a[i]);
            if (i == bb)
                nbb = appi;
            for (int j=s[s.size()-1] - '0'; j<= 9; j++) {
                a[appi++] = stoll(s + to_string(j));
            }
        }
        be = appi - 1;
        bb = nbb;
        b++;
    } 

    for (int z=1; z<=t; z++) {
        long long n;
        cin >> n;
        auto it = upper_bound(a, a+appi, n);
        cout << "Case #" << z << ": " << *(it-1) << endl;;
    }
    delete [] a;
}
