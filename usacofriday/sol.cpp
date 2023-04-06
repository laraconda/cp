/*
ID: larachi1
TASK: friday
LANG: C++
*/


#include <bits/stdc++.h>
using namespace std;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int wds[7];

int getdays(int m, int y) {
    if (m == 1 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        return 29;
    return months[m];
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;
    fin >> N;

    long long td = 0;
    for (int y=1900; y<1900 + N; y++) {
        for (int m=0; m<12; m++) {
            for (int d=0; d<getdays(m, y); d++) {
                if (d == 12) wds[td % 7]++;
                td++;
            }
        }
    }
    
    for (int i=0; i<6; i++) {
        fout << wds[(i+5)%7] << " ";
    }
    fout << wds[11%7] << endl;
}
