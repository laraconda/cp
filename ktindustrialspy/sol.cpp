#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e7;
string s;
string sets;
bitset<MXN> bs;
long long res = 0;

bool ispri(int n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i=3; i<= sqrt(n); i+=2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void all_sets(int i) {
    if (i == s.size()) {
        if (sets == "") return;
        string lsets = sets;

        sort(lsets.begin(), lsets.end());
        do {
            int n = stoi(lsets);
            if (!bs[n]) {
                if (ispri(n)) {
                    res++;
                }
            }
            bs[n] = 1;
        } while (next_permutation(lsets.begin(), lsets.end())); 
    } else {
        all_sets(i+1);
        sets.push_back(s[i]);
        all_sets(i+1);
        sets.pop_back();
    }
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        cin >> s;
        res = 0;
        sets = "";
        bs.reset();
        all_sets(0);
        cout << res << endl;
    }
}
