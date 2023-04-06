#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll wa, ha, wb, hb;
    cin >> wa >> ha >> wb >> hb;
    ll r = 4;
    r+= (ha + hb)*2;
    r+= max(wa, wb)*2;
    cout << r << endl;
}
