#include <bits/stdc++.h>
using namespace std;

bool grid[4][4];

void clean() {
    vector<int> rows;
    for (int i=0; i<4; i++) {
        bool em = false;
        for (int j=0; j<4; j++) {
            if (grid[i][j] == false) em = true; 
        }
        if (!em) {
            rows.push_back(i);
        }
    }

    for (int j=0; j<4; j++) {
        bool em = false;
        for (int i=0; i<4; i++) {
            if (grid[i][j] == false) em = true;
        }
        if (!em) {
            for (int i=0; i<4; i++)
                grid[i][j] = false;
        }
    }

    for (int i: rows) {
        for (int j=0; j<4; j++)
            grid[i][j] = false;
    }
}

void placeV() {
    bool done = false;
    int ii=1, jj=1;
    for (int i=0; i<3; i++) {
        if (done) break;
        for (int j=0; j<4; j++) {
            if (grid[i][j] == false && grid[i+1][j] == false) {
                ii = i+1;
                jj = j+1;

                bool exp = (i == 1 && grid[i-1][j] == true  &&
                    grid[i+2][j] == true) || 
                    (i == 0 && grid[i+2][j] == true && grid[i+3][j] == true) ||                  (i == 2 && (grid[i-1][j] == true && grid[i-2][j] == true))|| (i == 3 && grid[i-2][j] == true && grid[i-3][j] == true);
                    
                if (exp) {
                    ii = i+1;
                    jj = j+1;

                    done = true;
                    break;
                }

            }
        }
    }
    cout << ii << " " << jj << endl;
    grid[ii-1][jj-1] = true;
    grid[ii][jj-1] = true;
    clean();
}

void placeH() {
    bool done = false;
    int ii=1, jj=1;
    for (int i=0; i<4; i++) {
        if (done) break;
        for (int j=0; j<3; j++) {
            if (grid[i][j] == false && grid[i][j+1] == false) {
                ii = i+1;
                jj = j+1;
                bool exp = (j == 1 && grid[i][j-1] == true  &&
                    grid[i][j+2] == true) || 
                    (j == 0 && grid[i][j+2] == true && grid[i][j+2] == true) ||                  (j == 2 && (grid[i][j-1] == true && grid[i][j-2] == true))|| (j == 3 && grid[i][j-2] == true && grid[i][j-3] == true);

                    
                if (exp) {
                    ii = i+1;
                    jj = j+1;
                    done = true;
                    break;
                }
            }            
        }
    }
    cout << ii << " " << jj << endl;
    grid[ii-1][jj-1] = true;
    grid[ii-1][jj] = true;
    clean();
}

int main() {
    string s;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == '0')
            placeV();
        else placeH();
    }
}
