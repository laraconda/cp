#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int A[3][3];
int B[N][N][N][N][N][N][N][N][N];


bool allz(vector<int>& v) {
    for (int i=0; i<9; i++) {
        if (v[i] != 0) return false;
    }
    return true;
}

void reg(vector<int>& v) {
    B[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]][v[8]] = 1; 
}

int check(vector<int>& v) {
    return B[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]][v[8]];
}


int bfs(vector<int> s) {
    queue<pair<vector<int>, int>> q;
    q.push({s, 0});
    reg(s);
    while(!q.empty()) {
        auto vv = q.front(); q.pop();
        vector<int> v = vv.first;
        if (allz(v)) return vv.second;
        for (int x = 0; x<9; x++) {
            vector<int> u(v);
            for (int i=0; i<9; i++) {
                if (x % 3 == i % 3 && i != x)
                    u[i] = (u[i] + 1) % N;
            }

            u[(x/3)*3] = (u[(x/3)*3] + 1) % N;
            u[(x/3)*3 + 1] = (u[(x/3)*3 + 1] + 1) % N;
            u[(x/3)*3 + 2] = (u[(x/3)*3 + 2] + 1) % N;

            if (check(u)) continue;
            q.push({u, vv.second + 1});
            reg(u);
        }
    }
    return -1;
}


int main() {
    vector<int> s(9);
    for (int i=0; i<9; i++) {
        int aij;
        cin >> aij;
        s[i] = aij;
    }
    cout << bfs(s) << endl;
}
