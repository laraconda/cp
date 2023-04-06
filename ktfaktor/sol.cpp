#include <bits/stdc++.h>
using namespace std;


int main() {
    int A, I;
    cin >> A >> I;

    int x = A*I;
    int res;
    for (int i=x; i>0; i--)
        if ((ceil((double)i/A)) == I)
            res = i;

    cout << res << endl;
}
