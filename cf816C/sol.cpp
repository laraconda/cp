#include <bits/stdc++.h>
using namespace std;


const int N = 102;
const int M = 102;

int mat[N][M];

vector<int> rowmoves;
vector<int> colmoves;

void rows(int n, int m) {
    int minn = -1;
    for (int i=0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (mat[i][j] < minn || minn == -1)
                minn = mat[i][j];
        }
        for (int j = 0; j<m; j++)
            mat[i][j] -= minn;
        for (int z=0; z<minn; z++)
            rowmoves.push_back(i+1);
        minn = -1;
    }
}

void cols(int n, int m) {
    int minn = -1;
    for (int j=0; j<m; j++) {
        for (int i = 0; i<n; i++) {
            if (mat[i][j] < minn || minn == -1)
                minn = mat[i][j];
        }
        for (int i = 0; i<n; i++)
            mat[i][j] -= minn;
        for (int z=0; z<minn; z++)
            colmoves.push_back(j+1);
        minn = -1;
    }
}


bool allzero(int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (mat[i][j] != 0)
               return false;
        }
    }
    return true;
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int gij;
            cin >> gij;
            mat[i][j] = gij; 
        }
    }

    if (n < m) {
        rows(n, m);
        if (!allzero(n, m))
            cols(n, m);
    } else {
        cols(n, m);
        if (!allzero(n, m))
            rows(n, m);
    }
    
    if (!allzero(n, m)) {
        cout << -1 << endl;
    } else {
        cout << colmoves.size() + rowmoves.size() << endl;
        for (int i : rowmoves)
            cout << "row " << i << endl;
        
        for (int i : colmoves)
            cout << "col " << i << endl; 
    }
}
