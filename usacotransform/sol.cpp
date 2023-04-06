/*
ID: larachi1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;


bool meq(vector<vector<char>>& grida, vector<vector<char>>& gridb) {
    int n = grida.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (grida[i][j] != gridb[i][j]) {
                return false;
            }
        }
    }
    return true;
}


vector<vector<char>> rotate(vector<vector<char>>& grid, int n) {
    vector<vector<char>> ngrid(n);
    for (int i=0; i<n; i++) {
        vector<char> row(n);
        for (int z=0; z<n; z++) {
            row[z] = grid[i][z];
        }
        ngrid[i] = row;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int ii = j;
            int jj = n - 1 - i;
            ngrid[ii][jj] = grid[i][j];
        }
    }

    return ngrid;
}


vector<vector<char>> reflect(vector<vector<char>>& grid, int n) {
    vector<vector<char>> ngrid(n);
    for (int i=0; i<n; i++) {
        vector<char> row(n);
        for (int z=0; z<n; z++) {
            row[z] = grid[i][z];
        }
        ngrid[i] = row;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int ii = i;
            int jj = n - 1 - j;
            ngrid[ii][jj] = grid[i][j];
        }
    }
    return ngrid;
}


int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int n;
    fin >> n;
    
    vector<vector<char>> grida(n);
    for (int i=0; i<n; i++) {
        vector<char> row(n);
        string s;
        fin >> s;
        for (int z=0; z<n; z++) {
            row[z] = s[z];
        }
        grida[i] = row;
    }
    
    vector<vector<char>> gridb(n);
    for (int i=0; i<n; i++) {
        vector<char> row(n);
        string s;
        fin >> s;
        for (int z=0; z<n; z++) {
            row[z] = s[z];
        }
        gridb[i] = row;
    }


    vector<vector<char>> n90 = rotate(grida, n);
    vector<vector<char>> n180 = rotate(n90, n);
    vector<vector<char>> n270 = rotate(n180, n);

    vector<vector<char>> reflected = reflect(grida, n);

    vector<vector<char>> nr90 = rotate(reflected, n);
    vector<vector<char>> nr180 = rotate(nr90, n);
    vector<vector<char>> nr270 = rotate(nr180, n);
    if (meq(n90, gridb)) {
        fout << 1 << endl; 
    } else if (meq(n180, gridb)) {
        fout << 2 << endl; 
    } else if (meq(n270, gridb)) {
        fout << 3 << endl;
    } else if (meq(reflected, gridb)) {
        fout << 4 << endl; 
    } else if (meq(nr90, gridb) || meq(nr180, gridb) || meq(nr270, gridb)) {
        fout << 5 << endl;
    } else if (meq(grida, gridb)) {
        fout << 6 << endl; 
    } else {
        fout << 7 << endl;
    }
}
