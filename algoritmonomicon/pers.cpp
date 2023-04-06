#include <bits/stdc++.h>
using namespace std;

const int MXN = 10;
vector<int> perm;
bool chosen[MXN];

void pers(int n) {
    if (perm.size() == n) {
        // procesar la permutacion
    } else {
        for (int i=0; i<n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            perm.push_back(i);
            pers(n);
            chosen[i] = false;
            perm.pop_back();
        }
    }
}

int main() {
    pers(5);
}
