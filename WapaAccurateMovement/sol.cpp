#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
   ll a, b, n;
   cin >> a >> b >> n;
   ll x = ceil((double)(n-b)/(b - a));
   cout << 2*x + 1 << endl;
}
