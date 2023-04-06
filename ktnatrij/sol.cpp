#include <bits/stdc++.h>
using namespace std;

vector<int> at;
vector<int> bt;


int main() {
    string a, b;
    cin >> a >> b;

    string ah = "";
    ah.push_back(a[0]);
    ah.push_back(a[1]);
    at.push_back(stoi(ah));
    
    string bh = "";
    bh.push_back(b[0]);
    bh.push_back(b[1]);
    bt.push_back(stoi(bh));
   

    ah = "";
    ah.push_back(a[3]);
    ah.push_back(a[4]);
    at.push_back(stoi(ah));
    
    bh = "";
    bh.push_back(b[3]);
    bh.push_back(b[4]);
    bt.push_back(stoi(bh));
    
    
    ah = "";
    ah.push_back(a[6]);
    ah.push_back(a[7]);
    at.push_back(stoi(ah));
    
    bh = "";
    bh.push_back(b[6]);
    bh.push_back(b[7]);
    bt.push_back(stoi(bh));
    
    int h = bt[0] - at[0];
    int m = bt[1] - at[1];
    int s = bt[2] - at[2];
    
    if (s < 0) {
        s = 60 + s;
        m--;
    }
    if (h < 0) {
        h = 24 + h;
    }
    if (m < 0) {
        m = 60 + m;
        h--;
    }

    if (h == 0 && m == 0 && s == 0) {
        h = 24;
    }

    string sh = to_string(h);
    string sm = to_string(m);
    string ss = to_string(s);

    if (sh.size() < 2) sh = "0" + sh;
    if (sm.size() < 2) sm = "0" + sm;
    if (ss.size() < 2) ss = "0" + ss;

    cout << sh << ":" << sm << ":" << ss << endl;
}
