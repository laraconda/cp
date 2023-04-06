#include <bits/stdc++.h>
using namespace std;

const int MXN = 33;
long long k[MXN];

void mclean() {
    for (int i=0; i<MXN; i++)
        k[i] = 0;
}

int main() {
    int t;
    cin >> t;

    for (int i=1; i<=t; i++) {
        int d;
        string p;
        cin >> d;
        cin >> p;

        long long td = 0;
        long long po = 1;
        for (int j=0; j<p.size(); j++) {
            k[j] = po;
            if (p[j] == 'C')
                po *= 2;
            else
                td += po;
        }

        bool done = false;
        int moves = 0;
        while (!done) {
            for (int j=p.size()-2; j>=0; j--) {
                if (td <= d) {
                    done = true;
                    break;
                }
                if (p.substr(j, 2) == "CS") {
                    td -= k[j]; moves++;
                    p[j] = 'S';
                    p[j+1] = 'C';
                    k[j+1] = k[j];
                    break;
                }
                if (j == 0) done = true;
            }
        }

        cout << "Case #" << i << ": ";
        if (td <= d)
            cout << moves << endl;
        else
            cout << "IMPOSSIBLE" << endl;
        mclean();
    }

}
