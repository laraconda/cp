#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
        cout << -1 << endl;
    } else {
        int x = 0;
        int y = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'U') {
                y++;
            }
            if (s[i] == 'D') {
                y--;
            }
            if (s[i] == 'L') {
                x--;
            }
            if (s[i] == 'R') {
                x++;
            }
        }
        cout << (abs(x)+abs(y))/2 << endl;
    }
}
