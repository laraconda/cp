#include <bits/stdc++.h>
using namespace std;

const int MXN = 53;
const int INF = 1e9;

int flood[MXN][MXN];
int paint[MXN][MXN];
vector<int> cardsi = {-1, 0, +1, 0};
vector<int> cardsj = {0, +1, 0, -1};

int main() {
    int R, C;
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            flood[i][j] = INF;
            paint[i][j] = INF;
        }
    }
    pair<int, int> den;
    queue<pair<int, int>> q;
    queue<pair<int, int>> qp;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char cij;
            cin >> cij;
            if (cij == 'X' || cij == 'D')
                flood[i][j] = -1;
            if (cij == '*') {
                flood[i][j] = 0;
                q.push({i, j}); 
            }
            if (cij == 'X')
                paint[i][j] = -1;
            if (cij == 'D')
                den = {i, j};
            if (cij == 'S') {
                paint[i][j] = 0;
                qp.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        for (int di=0; di<4; di++) {
            int i = v.first + cardsi[di];
            int j = v.second + cardsj[di];
            if (i < 0 || j < 0 || i >= R || j >= C ) continue;
            if (flood[i][j] == -1) continue;
            if (flood[i][j] == INF)
                q.push({i, j});
            flood[i][j] = min(flood[i][j], flood[v.first][v.second] + 1);
        }
    }

    while (!qp.empty()) {
        pair<int, int> v = qp.front(); qp.pop();
        for (int di=0; di<4; di++) {
            int i = v.first + cardsi[di];
            int j = v.second + cardsj[di];
            if (i < 0 || j < 0 || i >= R || j >= C ) continue;
            if ((flood[i][j] <= paint[v.first][v.second] + 1 &&
                flood[i][j] != -1) || paint[i][j] == -1) continue;
            if (paint[i][j] == INF)
                qp.push({i, j});
            paint[i][j] = min(paint[i][j], paint[v.first][v.second] + 1);
        }
    }
    if (paint[den.first][den.second] == INF) {
        cout << "KAKTUS" << endl;
    } else {
        cout << paint[den.first][den.second] << endl;
    }

}
