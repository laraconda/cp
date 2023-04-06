#include <bits/stdc++.h>
using namespace std;

int A[9][9];
bitset<10> B[9][9];

bool err = false;


void put(int i, int j, int e) {
    A[i][j] = e;
    for (int ii = 0; ii<9; ii++)
        B[ii][j][e] = 1;
    for (int jj = 0; jj<9; jj++)
        B[i][jj][e] = 1;
}

void check_sqs() {
    for (int i=0; i<9; i+=3) {
        for (int j=0; j<9; j+=3) {
            for (int x = 1; x<10; x++) {
                int count = 0;
                for (int ii=i; ii<i+3; ii++) {
                    for (int jj=j; jj<j+3; jj++) {
                        if (A[ii][jj] == x) count++;        
                    }
                }
                if (count > 1) err = true;
            }
        }
    }
}

bool complete_sq(int i, int j) {
    bool a = false;

    for (int x = 1; x<10; x++) {
        int count = 0;
        for (int ii=i; ii<i+3; ii++) {
            for (int jj=j; jj<j+3; jj++) {
                if (A[ii][jj] == x) count++;        
            }
        }

        if (count == 0) {
            int av = 0;
            int ave = 0;
            int empty = 0;
            int iii, jjj;
            for (int ii=i; ii<i+3; ii++) {
                for (int jj=j; jj<j+3; jj++) {
                    if (A[ii][jj] == 0) empty++;
                    if (!B[ii][jj][x]) {
                        av++;
                        if (A[ii][jj] == 0) {
                            ave++;
                            iii = ii;
                            jjj = jj;
                        }
                    }
                }
            }
            if (ave == 0 && av >= 1) {
                err = true;
            }
            if (ave == 1) {
                put(iii, jjj, x);
                a = true;
            }
        }
    }
    return a;
}

void check_lines() {
    for (int x=1; x<10; x++) {
        for (int i=0; i<9; i++) {
            int count = 0;
            for (int j=0; j<9; j++) {
                if (A[i][j] == x) count++;
            }
            if (count > 1) err = true;
        }
    }
    
    for (int x=1; x<10; x++) {
        for (int j=0; j<9; j++) {
            int count = 0;
            for (int i=0; i<9; i++) {
                if (A[i][j] == x) count++;
            }
            if (count > 1) err = true;
        }
    }
}

void check_all() {
    check_lines();
    check_sqs();
}


bool complete_all() {
    bool a = false;
    for (int i=0; i<9; i+=3) {
        for (int j=0; j<9; j+=3) {
            a = a || complete_sq(i, j);
        }
    }
    return a;
}


int main() {
    for (int i=0; i<9; i++) {
        string s;
        cin >> s;

        for (int j=0; j<9; j++) {
            if (s[j] != '.') put(i, j, s[j] - '0');
            else A[i][j] = 0;
        }
    }
    check_all();

    while (complete_all());
    
    if (!err) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (A[i][j]) cout << A[i][j];
                else cout << ".";
            }
            cout << endl;
        }
    } else
        cout << "ERROR" << endl;
}
