#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {

    vector<int> check(n); 
    int last;
    bool lastb = false;
    for (int i=0; i<n; i++) {
        int ni;
        cin >> ni;
        if (lastb) {
            int j = abs(ni - last);
            if (j < n)
                check[j]++; 
        }
        last = ni;
        lastb = true;
    }
    bool res = true;
    for (int i=1; i<n; i++) {
        if (check[i] != 1)
            res = false;
    }

    if (res)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
    }
}
