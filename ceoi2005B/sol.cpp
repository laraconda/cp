#include <bits/stdc++.h>
using namespace std;

const int MXL = 205;
long long C[MXL][MXL];
long long K[][][];


void floyd(int L) {
    for (int k=1; k<=L; k++)
        for (int i=1; i<=L; i++)
            for (int j=1; j<=L; j++)
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
}

long long k()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int L, N;
    cin >> L >> N;

    for (int i=1; i<=L; i++) {
        for (int j=1; j<=L; j++) {
            int dis;
            cin >> dis;
            C[i][j] = dis;
        }
    }
}
