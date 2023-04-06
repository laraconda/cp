#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;

    string res;
    if (N % 2 == 0)
        res = "Bob";
    else
        res = "Alice";

    cout << res << endl;
}
