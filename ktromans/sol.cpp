#include <bits/stdc++.h>
using namespace std;

int main() {
    float x;
    cin >> x;

    double con = (double)880/809;
    double res = (double)x * con * 1000;
    printf("%lld\n", (long long)round(res));

}
