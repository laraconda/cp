#include <bits/stdc++.h>
using namespace std;

map <string, int> kk;

int get(string s) {
    if (!kk.count(s))
        return 100001*3;
    return kk[s];
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int pi;
        string vits;
        cin >> pi >> vits;

        sort(vits.begin(), vits.end());
        if (!kk.count(vits))
            kk[vits] = pi;
        else if (kk[vits] > pi) {
            kk[vits] = pi;
        }
    }

    int res = get("A") + get("B") + get("C");
    res = min(res, get("ABC"));
    res = min(res, get("A") + get("BC"));
    res = min(res, get("B") + get("AC"));
    res = min(res, get("C") + get("AB"));

    res = min(res, get("AB") + get("AC"));
    res = min(res, get("BC") + get("AC"));
    res = min(res, get("AB") + get("BC"));

    if (res > 300000)
        res = -1;

    cout << res << endl;
}
