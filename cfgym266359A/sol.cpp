#include <bits/stdc++.h>
using namespace std;

vector<int> ebne = {11, 13, 15, 17, 19};

void gen() {
    int mul = 1;
    while (true) {
        for (int i=0; i<5; i++) {
            int nebne = ebne[i] + (mul*20);
            if (nebne > 100)
                return;
            ebne.push_back(nebne);
        }
        mul++;

    }
}

int main() {
    int t;
    cin >> t;
    gen();
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool pos = false;
        int res;
        for (int nebne : ebne) {
            string sn = to_string(nebne);
            int j = 0;
            for (int i=0; i<(int)s.size(); i++) {
                if (s[i] == sn[j])
                    j++;
                if (j >= sn.size()) {
                    pos = true;
                    res = nebne;
                    break;
                }
            }
        }
        if (pos)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
}
