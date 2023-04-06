#include <bits/stdc++.h>
using namespace std;

const int MXN = 103;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, R, P, S;
        cin >> n >> R >> P >> S;

        string bs;
        cin >> bs;

        int Rb = 0; 
        int Pb = 0;
        int Sb = 0;

        for (int i=0; i<bs.size(); i++) {
            if (bs[i] == 'R')
                Rb++;
            if (bs[i] == 'P')
                Pb++;
            if (bs[i] == 'S')
                Sb++;
        }

        int points = 0;
        points += min(R, Sb);
        points += min(P, Rb);
        points += min(S, Pb);

        if (points >= (int)ceil((double)n/2)) {
            cout << "YES" << endl;
            string as(bs);

            bitset<MXN> vis;
            for (int i=0; i<bs.size(); i++) {
                if (bs[i] == 'R' && P > 0) {
                    as[i] = 'P';
                    P--;
                    vis[i] = 1;
                }
            }
            
            for (int i=0; i<bs.size(); i++) {
                if (bs[i] == 'P' && S > 0) {
                    as[i] = 'S';
                    S--;
                    vis[i] = 1;
                }
            }
            
            for (int i=0; i<bs.size(); i++) {
                if (bs[i] == 'S' && R > 0) {
                    as[i] = 'R';
                    R--;
                    vis[i] = 1;
                }
            }

            for (int i=0; i<n; i++) {
                if (vis[i] == 0) {
                    if (R > 0) {
                        as[i] = 'R';
                        R--;
                    } else if (P > 0) {
                        as[i] = 'P';
                        P--; 
                    } else {  // S
                        as[i] = 'S';
                        S--;
                    }
                }
            }

            cout << as << endl;
        } else {
            cout << "NO" << endl;
        }



    }
}
