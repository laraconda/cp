#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {30, 112, 453, 235};
    vector<int> v2(v);
    sort(v.begin(), v.end());
    map<int, int> zip;
    int i = 0;
    for (auto x : v)
        zip[x] = i++;

    for (int i=0; i<v2.size(); i++) {
        cout << v2[i] << ": " << zip[v2[i]] << endl;
    }
}
