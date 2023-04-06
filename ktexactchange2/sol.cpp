#include <bits/stdc++.h>
using namespace std;

const int MXN = (1e4 + 2) * 2;
int a[MXN];
int b[MXN];
unordered_map<int, int> totalc; 

void clearab() {
    for (int i=0; i<MXN; i++) {
        a[i] = MXN;
        b[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<int> cs;

    while(t--) {
        int n, m;
        cin >> n >> m;

        clearab();
        int ci;
        for (int i=0; i<m; i++) {
            cin >> ci;
            totalc[ci]++;
        }

        for (pair<int, int> e : totalc)
            cs.push_back(e.first);
        sort(cs.begin(), cs.end(), greater<int>());

        a[0] = 0;
        for (int c : cs) {
            int lastj = MXN;
            for(int j=c; j<MXN; j++) {
                if (b[j-c] >= totalc[c])
                    continue;
                if (a[j] > a[j-c] + 1) {
                    a[j] = a[j-c] + 1;
                    b[j] = b[j-c] + 1;
                }

                if (a[j] != MXN && j>= n) {
                    lastj = j;
                    break;
                }   
            }

            for (int i=0; i<=lastj; i++)
                b[i] = 0;
        }

        int am;
        int coins;
        for (int i=n; i<MXN; i++) {
            if (a[i] != MXN) {
                am = i;
                coins = a[i];
                break;
            }
        }

        cout << am << " " << coins << endl;
        totalc.clear();
        cs.clear();
    }
}
