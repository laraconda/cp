#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int abc[3];
    for (int i=0; i<3; i++)
        abc[i] = 0;

    int defaultv = 100001*3;

    int mina = defaultv;
    int minb = defaultv;
    int minc = defaultv;

    int minab = defaultv;
    int minac = defaultv;
    int minbc = defaultv;

    int minabc = defaultv;

    while(n--) {
        int pi;
        string vits;
        cin >> pi;
        cin >> vits;

        if (vits.size() == 1) {
            if (vits == "A") {
                abc[0] = 1;
                if (mina > pi || mina == defaultv)
                    mina = pi;
            } else if (vits == "B") {
                abc[1] = 1;
                if (minb > pi || minb == defaultv)
                    minb = pi;
            } else {
                abc[2] = 1;
                if (minc > pi || minc == defaultv)
                    minc = pi;
            }
        } else if (vits.size() == 2) {
            if (vits == "AB" || vits == "BA") {
                abc[0] = 1;
                abc[1] = 1;
                if (minab > pi || minab == defaultv)
                    minab = pi;
            } else if (vits == "AC" || vits == "CA") {
                abc[0] = 1;
                abc[2] = 1;
                if (minac > pi || minac == defaultv)
                    minac = pi;
            } else {
                abc[1] = 1;
                abc[2] = 1;
                if (minbc > pi || minbc == defaultv)
                    minbc = pi;
            }
        } else {
            abc[0] = 1;
            abc[1] = 1;
            abc[2] = 1;
            if (minabc > pi || minabc == defaultv)
                minabc = pi;
        }
    }

    int abmin = min(mina + minb, minab);
    int acmin = min(mina + minc, minac);
    int bcmin = min(minb + minc, minbc);

    int res = min(min(minc + abmin, minabc), min(acmin + minb, bcmin + mina));
    int kk = min(min(abmin + acmin, acmin + bcmin), abmin + bcmin);
    res = min(res, kk);

    for (int i=0; i<3; i++) {
        if (abc[i] == 0)
            res = -1;
    }
    
    cout << res << endl;
}
