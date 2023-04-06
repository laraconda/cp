#include <bits/stdc++.h>
using namespace std;

const int MXN = 105;
bool G[MXN][MXN];
int A[MXN];
vector<int> al[MXN];
bool finished = false;


void backtrack(int i, int N) {
    if (i == N + 1) {
        if (!finished) {
            finished = true;
            for (int i=1; i<=N; i++) {
                cout << i << " " << A[i] << endl; 
            }
        }
        return;
    } else {
        for (int z=1; z<=4; z++) {
            if (finished)
                return;
            bool pos = true;
            for (int j : al[i]) {
                if (A[j] == z) 
                    pos = false;
            }
            if (pos) {
                A[i] = z;
                backtrack(i + 1, N);
                A[i] = 0;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string s;
    while (getline(cin, s)) {
        int a, b;
        for (int j=0; j<(int)s.size(); j++) {
            if (s[j] == '-')
                s[j] = ' ';
        }
        stringstream ss(s);
        ss >> a >> b;
        G[a][b] = true;
        G[b][a] = true;
    }
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=N; j++) {
            if (G[i][j])
                al[i].push_back(j);
        }
    }
    backtrack(1, N);
}
