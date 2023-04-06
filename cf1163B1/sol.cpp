#include <bits/stdc++.h>
using namespace std;


const int UISN = 10 + 1;
int uis[UISN];

bool streak() {
    vector <int> nonzero;
    bool allone = true;
    for (int i=1; i<=10; i++) {
        if (uis[i] == 0)
            continue;
        if (uis[i] != 1)
            allone = false;
        nonzero.push_back(uis[i]);
    }
    int nzs = nonzero.size();
    if (nzs == 1)
        return true;

    if (allone)
        return true;

    sort(nonzero.begin(), nonzero.end());
    int last = -1;
    int regions = 1;
    for (int i=0; i<nzs; i++) {
        if (last != -1 && nonzero[i] != last) {
            regions++;
        }
        last = nonzero[i];
    }

    if (regions != 2)
        return false;

    if (nonzero[nzs - 1] - 1 == nonzero[nzs - 2])
        return true;

    if (nonzero[0] == 1 && nonzero[1] != 1)
        return true;

    return false;
}

int main() {
    int n;
    cin >> n;

    int maxx = 1;
    int ui;
    for (int i=1; i<=n; i++) {
        cin >> ui;
        uis[ui] += 1;
        if (streak())
            maxx = i;
    }

    cout << maxx << endl;
}
