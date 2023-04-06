#include <bits/stdc++.h>
using namespace std;

const string al = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        vector<int> ps(N+1);
        for (int i=0; i<=N; i++) {
            ps[i] = 0;
        }

        long long total = 0;
        for (int i=1; i<=N; i++) {
            int pi;
            cin >> pi;
            ps[i] = pi;
            total += pi;
        }

        vector<string> cos;
        while (total > 0) {
            if (total == 3) {
                string co;
                int pmax = -1;
                int imax;
                for (int i=1; i<=N; i++) {
                    if (pmax < ps[i]) {
                        pmax = ps[i];
                        imax = i;
                    }
                }
                total--;
                ps[imax]--;
                co += al[imax];
                cos.push_back(co);
            }
            int pmax = -1;
            int imax = -1;
            int jmax = -1;
            for (int i=1; i<=N; i++) {
                if (pmax < ps[i]) {
                    pmax = ps[i];
                    imax = i;
                } else if (pmax == ps[i]) {
                    jmax = i;
                }
            }
            ps[imax]--;
            total--;
            string co;
            co += al[imax];
            if (jmax != -1 && pmax == ps[jmax]) {
                ps[jmax]--;
                total--;
                co += al[jmax];
            }
            cos.push_back(co);
        }
        cout << "Case #" << t << ": ";
        for (int i=0; i < (int)cos.size() - 1; i++) {
            cout << cos[i] << " ";
        }
        if (cos.size() > 0)
            cout << cos[(int)cos.size() - 1] << endl;
        cos.clear();
    }
}
