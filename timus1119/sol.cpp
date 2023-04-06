#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1003;
double dp[MAXN][MAXN];
int cross[MAXN][MAXN];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int x, y;
    while(K--) {
        cin >> x >> y;
        cross[y][x] = 1;
    }

    double diag = (double)sqrt(pow(100, 2) * 2);

    for (int i=M; i>=0; i--) {
        for (int j=N; j>=0; j--) {
            if (j == N && i == M)
                continue;
            double newd;
            if (i == M)
                newd = (double)100 + dp[i][j+1];
            else if (j == N)
                newd = (double)100 + dp[i+1][j];
            else {
                newd = (double)100 + min(dp[i][j+1], dp[i+1][j]);
                if (cross[i+1][j+1])
                    newd = min(diag + dp[i+1][j+1], newd); 
            }
            dp[i][j] = newd;
        }
    }

    cout << round(dp[0][0]) << endl;
}
