#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {0, 1, 2, 3, 4};
    int i = lower_bound(v.begin(), v.end(), 8) - v.begin();
    cout << i << endl;
}
