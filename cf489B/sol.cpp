#include <bits/stdc++.h>
using namespace std;

vector<int> bs;
vector<int> gs;

bitset<101> bbit;
bitset<101> gbit;

bool matcheable(int i, int j) {
    return (abs(bs[i] - gs[j]) <= 1 && !bbit[i] && !gbit[j]);
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int bi;
        cin >> bi;
        bs.push_back(bi);
    }
    
    int m;
    cin >> m;

    while (m--) {
        int gi;
        cin >> gi;
        gs.push_back(gi);
    }

    sort(gs.begin(), gs.end());
    sort(bs.begin(), bs.end());

    int count = 0;
    for (int i=0; i<bs.size(); i++) {
        for (int j=0; j<gs.size(); j++) {
            if (matcheable(i, j)) {
                count++;
                bbit[i] = 1;
                gbit[j] = 1;
                break;
            }
        }
    }

    cout << count << endl;
}
