#include <bits/stdc++.h>
using namespace std;

int main() {
    int s1, s2, r1, r2;
    cin >> s1 >> s2 >> r1 >> r2;
    int s, r, ma, mi;
    while (s1 != 0) {
        if ((s1 == 1 && s2 == 2) || (s1 == 2 && s2 == 1))
            s = 1000;
        else if (s1 == s2)
            s = 10*s1 + s1 + 60;
        else {
            ma = max(s1, s2);
            mi = min(s1, s2);

            s = 10*ma + mi;
        }
        
        if ((r1 == 1 && r2 == 2) || (r1 == 2 && r2 == 1))
            r = 1000;
        else if (r1 == r2)
            r = 10*r1 + r1 + 60;
        else {
            ma = max(r1, r2);
            mi = min(r1, r2);

            r = 10*ma + mi;
        }

        if (s > r)
            cout << "Player 1 wins." << endl;
        else if (r > s)
            cout << "Player 2 wins." << endl;
        else
            cout << "Tie." << endl;
        
        cin >> s1 >> s2 >> r1 >> r2;
    }
}
