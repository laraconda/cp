#include <bits/stdc++.h>
using namespace std;

int main() {

    int cands[] = {4, 8, 15, 16, 23, 42};
    bitset<6> bs;
    int mat[6][6];

    for (int i=0; i<6; i++)
        for (int j=0; j<6; j++)
            mat[i][j] = cands[i] * cands[j];


    int a1, a2, a3, a4, a5, a6;
    int q1, q2, q3, q4;

    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> q1;

    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> q2;

    int firsti;
    int count = 0;
    for (int i=5; i>=0; i--) {
        count = 0;
        for (int j=0; j<6; j++) {
            if (i == j)
                continue;
            if (mat[i][j] == q1 || mat[i][j] == q2)
                count++;
        }
        if (count == 2) {
            firsti = i;
            break;
        }
    }

    a2 = cands[firsti];
    bs[firsti] = 1;
    a1 = q1/a2;
    bs[find(cands, cands+6, a1) - cands] = 1;
    a3 = q2/a2;
    bs[find(cands, cands+6, a3) - cands] = 1;

    cout << "? 3 4" << endl;
    fflush(stdout);
    cin >> q3;
    
    a4 = q3/a3;
    bs[find(cands, cands+6, a4) - cands] = 1;
    
    cout << "? 4 5" << endl;
    fflush(stdout);
    cin >> q4;

    a5 = q4/a4;
    bs[find(cands, cands+6, a5) - cands] = 1;

    for (int i=0; i<6; i++) {
        if (bs[i] == 0)
            a6 = cands[i];
    }

    cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
    fflush(stdout);
}
