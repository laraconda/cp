#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;

    int fb = -1;
    int lb = -1;
    int fc = -1;
    int lc = -1;

    bool pos = true;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == '[') {
            fb = i;
            break;
        }
    }

    if (fb == -1)
        pos = false;
        

    if (pos) {
        for (int i=fb; i<s.size(); i++) {
            if (s[i] == ':') {
                fc = i;
                break;
            }
        }
    }

    if (fc == -1)
        pos = false;

    if (pos) {
        for (int i=s.size() - 1; i>fc; i--) {
            if (s[i] == ']') {
                lb = i;
                break;
            }
        }
    }

    if (lb == -1)
        pos = false;
    
    if (pos) {
        for (int i=lb - 1; i>=0; i--) {
            if (s[i] == ':') {
                lc = i;
                break;
            }
        }
    }

    if (lc == -1 || lc == fc)
        pos = false;

    int npipes = 0;
    if (pos) {
        for (int i=fc; i<lc; i++) {
            if (s[i] == '|')
                npipes++;
        }
    }

    int res = -1;
    if (pos) {
        res = npipes + 4;
    }

    cout << res << endl;
}
