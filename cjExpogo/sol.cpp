#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool step(ll X, ll Y, ll lastx, ll lasty, string& res) {
   ll x = abs(X);
   ll y = abs(Y);
   if (x == 0 && y == 0) return true;
   if (X == lastx && Y == lasty) return false;
   if (x % 2 == 0 && y % 2 == 0) return false;
   if (x % 2 != 0 && y % 2 != 0) return false;
   if (x % 2 != 0) {
    res.push_back('E');
    bool pos = step((X-1)/2, Y/2, X, Y, res);
    if (pos) return true;
    res.pop_back();
    res.push_back('W');
    pos = step((X+1)/2, Y/2, X, Y, res); 
    if (!pos) res.pop_back();
    return pos;
   }
    return true;
   } else {
    res.push_back('N');
    bool pos = step(X/2, (Y-1)/2, X, Y, res);
    if (!pos) {
        res.pop_back();
        res.push_back('S');
        pos = step(X/2, (Y+1)/2, X, Y, res); 
        if (!pos) res.pop_back();
        return pos;
    }
    return true;
   }

}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        ll X, Y;
        cin >> X >> Y;
        string res;
        bool pos = step(X, Y, 0, 0, res);

        if (pos)
            cout << "Case #" << t << ": " << res << endl;
        else
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    }
}
