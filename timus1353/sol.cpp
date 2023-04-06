#include <bits/stdc++.h>
using namespace std;


vector<vector<array<int, 10> > > a;
int facts[10];


long long getsum(array<int, 10> k) {
    long long res = facts[9];
    int su = 0;
    for (int i=1; i<10; i++) {
        su += k[i];
        res /= facts[k[i]];
    }
    res /= facts[9 - su];
    return res;
}


void init() {
    for (int i=0; i<82; i++) {
        vector<array<int, 10> > v;
        a.push_back(v);
    }

    array<int, 10> k;
    for (int i=0; i<10; i++)
        k[i] = 0;
    a[0].push_back(k);
    
    facts[0] = 1;
    for (int i=1; i<10; i++)
        facts[i] = i * facts[i-1];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int s;
    cin >> s;

    init();
    
    for (int i=1; i<10; i++) {
        for (int j=i; j<=81; j++) {
            for (auto x: a[j - i]) {
                array<int, 10> k;
                int su = 0;
                bool valid = true;
                for (int ii=0; ii<10; ii++) {
                    su += x[ii];
                    k[ii] = x[ii];
                }
                
                if (su >= 9)
                    valid = false;
                
                if (valid) {
                    k[i]++;
                    a[j].push_back(k);
                }
            }
        }
    }

    long long res = 0;
    for (int i=0; i<a[s].size(); i++)
        res += getsum(a[s][i]);
    
    int plus = 0;
    if (s == 1)
       plus++;

    cout << res + plus << endl;
}
