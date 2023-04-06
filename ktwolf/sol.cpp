#include <bits/stdc++.h>
using namespace std;

vector<pair<int, char>> vall;


void allc() {
    for (int i=1; i<=13; i++) {
        for (char c : {'C', 'D', 'H', 'S'}) {
            vall.push_back({i, c});
        }
    }
}

int main() {
    allc();

    int n;
    cin >> n;

    vector<pair<int, char>> mine;
    vector<pair<int, char>> his;
    for (int i=0; i<n; i++) {
        int k;
        char t;
        cin >> k;
        cin >> t;
        mine.push_back({k, t});
    }

    for (auto card: vall) {
        bool inmine = false;
        for (auto cardm : mine) {
            if (cardm.first == card.first && cardm.second == card.second) {
                inmine = true;
                break;
            }
        }
        if (!inmine)
            his.push_back(card); 
    }

    sort(mine.begin(), mine.end(), greater<pair<int, char>>());
    vector<int> hs(4);
    for (int i=0; i<4; i++) {
        hs[i] = -1;
    }
    for (int i=n - 1; i>=0; i--) {
        if (mine[i].second == 'C')
            hs[0] = i;
        if (mine[i].second == 'D')
            hs[1] = i;
        if (mine[i].second == 'H')
            hs[2] = i;
        if (mine[i].second == 'S')
            hs[3] = i;
    }

    bool pos = false;
    for (int hi : hs) {
        if (hi == -1)
            continue;
        vector<pair<int, char>> cmine(mine); 
        vector<pair<int, char>> chis(his); 
        auto high = cmine[hi];
        bool found = false;
        int ifound = -1;
        for (int j=0; j < (int)chis.size(); j++) {
            auto hisc = chis[j];
            if (high.second == hisc.second && high.first > hisc.first) {
                found = true;
                ifound = j;
                break;
            }
        }
        if (found) {
            cmine.erase(cmine.begin() + hi);
            chis.erase(chis.begin() + ifound);
        }
   
        int blocks = 0;
        int mdel = -1;
        for (auto minec : cmine) {
            mdel = -1;
            for (int j=0; j<(int)chis.size(); j++) {
                if (minec.second != chis[j].second) {
                    blocks++; 
                    mdel = j;
                    break;
                }
            } 
            if (mdel != -1) {
                chis.erase(chis.begin() + mdel); 
            }
        }

        if ((int)his.size() == n) {
            if (found && (blocks >= (int)his.size() - 1))
                pos = true;
        } else if ((int)his.size() < n) {
            if ((found && (blocks >= (int)his.size() - 1)) ||
                (!found && (blocks >= (int)his.size()))
            )
                pos = true; 
        }

    }
    if ((int)his.size() > n)
        pos = false;

    if (pos)
        cout << "possible" << endl;
    else
        cout << "impossible" << endl;
}
