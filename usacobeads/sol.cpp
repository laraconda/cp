/*
ID: larachi1
TASK: beads
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n;
    string s;
    fin >> n;
    fin >> s;


    int mx = 0;
    for (int j=0; j<n; j++) {
        int c = 0;
        int i = j;
        char color = s[i];
        while (color == 'w' || s[i] == color || s[i] == 'w') {
            if (color == 'w') {
                if (s[i] != 'w') {
                    color = s[i];
                } 
            }
            c++;
            i--;
            i = i == -1 ? n - 1 : i;

            if (i == j) {
                break;
            }
        }
        int limit = (i + 1) % n;
        
        i = (j + 1) % n; 
        color = s[i];
        while ((color == 'w' || s[i] == color || s[i] == 'w') && (i != limit)) {
            if (color == 'w') {
                if (s[i] != 'w') {
                    color = s[i];
                }
            }
            c++;
            i++;
            i = i % n;
            if (i == (j + 1) % n || i == limit) {
                break;
            }
        }
        mx = max(mx, c);
    }
    fout << mx << endl;
}
