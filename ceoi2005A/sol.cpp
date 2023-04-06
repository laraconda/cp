#include <bits/stdc++.h>
using namespace std;

const int MXN = 405;
int mcount[MXN][MXN];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            int id;
            cin >> id;
            mcount[i][id]++;
        }
    }
    
    double moves = 0;
    for (int i=1; i<=N; i++) {
        int over = 0;
        for (int j=1; j<=M; j++) {
            int k = mcount[i][j] - 1;
            if (k > 0) {
                moves += k * (1.5);  
                over += k;
            }
        }
        if (over > 1)
            moves -= (over - 1);
    }
    cout << (long long)moves << endl;
}
