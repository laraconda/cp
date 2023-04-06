#include <bits/stdc++.h>
using namespace std;

const int MK = 39;
const long long MXN = 1008;

vector<long long> mgoods;
long long mpowers[MK];

void mcpowers() {
    mpowers[0] = 1;
    for (int i=1; i<MK; i++)
        mpowers[i] = mpowers[i - 1] * 3;
}


void mprecomp() {
    mcpowers();
    bool out = false;
    for (int i=0; i < MK && !out; i++) {
        mgoods.push_back(mpowers[i]);
        int size = (int)mgoods.size();
        for (int j=0; j < size - 1; j++) {
            long long newg = mgoods[j] + mpowers[i];
            if (newg >= MXN) {
                out = true;
                break;
            }
            mgoods.push_back(newg);
        }
    }
}

int main() {
    mprecomp();

    int q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        auto it = lower_bound(mgoods.begin(), mgoods.end(), n);
        cout << *it << endl;
    }
    return 0;
}
