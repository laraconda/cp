#include <bits/stdc++.h>
using namespace std;

struct P {
    int x;
    int y;

    P(int x, int y): x(x), y(y) {}
};

typedef struct P P;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 1;
    int d=0;
    P last = P(0, 0);
    P curr = P(0, 0);
    P prev = P(0, 0);
    for (int i=0; i<n; i++) {
        d++;
        if (s[i] == 'L') {
            curr.x--;
        }
        if (s[i] == 'R') {
            curr.x++;
        }
        if (s[i] == 'U') {
            curr.y++;
        }
        if (s[i] == 'D') {
            curr.y--;
        }
        if (abs(curr.x - last.x) + abs(curr.y - last.y) < d) {
            c++;
            d = 1;
            last = prev;
        }
        prev = curr;
    }
    cout << c << endl;
}
