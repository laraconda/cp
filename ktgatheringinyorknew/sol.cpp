#include <bits/stdc++.h>
using namespace std;


int bs(int i, vector<long long>& pos) {
    int low = 0;
    int high = i;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long dist = pos[mid];
        if (dist <= abs(pos[i] - dist)) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }    
    }
    return high;
}

long long findbest(vector<long long>& dispos, vector<long long>& disback, vector<long long>& pos, long long totalneg) {
    long long best = 1e18;
    int n = pos.size();
    for (int i=n-1; i>=0; i--) {
        long long current = dispos[i] + totalneg;
        int j = bs(i, pos); // last index closer to 0
        long long subs = (long long)(abs((long long)pos[0] - pos[j])) * (n - 1 - j);
        current += dispos[0] - dispos[j] - subs;  // closer to 0
        j++;
        if (j <= i)
            current += disback[i] - disback[j] - (long long)(abs((long long) pos[i] - pos[j])) * j; // closer to i
        if (current < best) best = current;
    }
    return best;
}

int main() {
    int h;
    cin >> h;

    vector<long long> pos;
    vector<long long> neg;
    for (int i=0; i<h; i++) {
        long long xi;
        cin >> xi;
        if (xi < 0) {
            neg.push_back(abs(xi));
        } else if (xi > 0)
            pos.push_back(xi);
    }

    pos.push_back(0);
    neg.push_back(0);

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    vector<long long> dispos(pos.size());
    dispos[(int)pos.size() - 1] = 0;
    for (int i=(int)pos.size() - 2; i >= 0; i--) {
        long long bef = (int)pos.size() - 1 - i;
        dispos[i] = dispos[i + 1] + abs((long long)pos[i] - pos[i+1]) * bef; 
    }
    vector<long long> disback(pos.size());
    disback[0] = 0;
    for (int i=1; i<(int)pos.size(); i++) {
        disback[i] = disback[i-1] + abs((long long)pos[i] - pos[i-1]) * i; 
    }

    vector<long long> disneg(neg.size());
    disneg[(int)neg.size() - 1] = 0;
    for (int i=(int)neg.size() - 2; i >= 0; i--) {
        long long bef = (int)neg.size() - 1 - i;
        disneg[i] = disneg[i + 1] + abs((long long)neg[i] - neg[i+1]) * bef; 
    }
    
    
    long long totalpos = dispos[0];
    long long totalneg = disneg[0];
    long long posbest = findbest(dispos, disback, pos, totalneg);
    
    disback.clear();
    disback.resize(neg.size());
    disback[0] = 0;
    for (int i=1; i<(int)neg.size(); i++) {
        disback[i] = disback[i-1] + abs((long long)neg[i] - neg[i-1]) * i; 
    }

    long long negbest = findbest(disneg, disback, neg, totalpos);

    if (posbest < negbest) {
        cout << posbest << endl;
    } else {
        cout << negbest << endl;
    }
}
