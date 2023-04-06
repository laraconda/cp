#include <bits/stdc++.h>
using namespace std;

const int MOD = 3;
const int LARGE = 15*8;

char a[5][LARGE];

int main() {
    string s;
    cin >> s;

    int sz = s.size();

    for (int i=0; i<5; i++) {
        for (int j=0; j<sz * 5 - (sz - 1); j++)
            a[i][j] = '.';
    }

    for (int i=0; i<5; i++) {
        int topc = 0;
        if (i == 0 || i == 4) {
            topc = 0;
            for (int j=0; j<sz * 5 - (sz - 1); j++) {
            if (((j%4)%2) == 0 && j != 0 && j%4 != 0) {
                topc++;
                if (topc % 3 == 0) {
                    a[i][j] = '*';
                } else {
                    a[i][j] = '#';
                }
            }
            }
        }
        if (i == 1 || i == 3) {
            topc = 0;
            for (int j=0; j<sz * 5 - (sz - 1); j++) {
            if (((j%4)%2) == 0 && j != 0 && j%4 != 0) {
                topc++;
                if (topc % 3 == 0) {
                    a[i][j-1] = '*';
                    a[i][j+1] = '*';
                } else {
                    a[i][j-1] = '#';
                    a[i][j+1] = '#';
                }
            }
            }
        }
        if (i == 2) {
            topc = 0; 
            for (int j=0; j<sz * 5 - (sz - 1); j++) {
            if (((j%4)%2) == 0 && j != 0 && j%4 != 0) {
                a[i][j] = s[topc++];
                if (topc % 3 == 0) {
                    a[i][j-2] = '*';
                    a[i][j+2] = '*';
                } else {
                    if (a[i][j-2] == '.')
                        a[i][j-2] = '#';
                    a[i][j+2] = '#';
                }
            }
            }
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<sz * 5 - (sz - 1); j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
