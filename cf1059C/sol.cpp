#include <bits/stdc++.h>
using namespace std;

vector<int> pows;
vector<int> counts;


void gen(int n) {
    int p = 1;
    int c = 0;
    while (p <= n) {
        c++;
        pows.push_back(p);
        p <<= 1;
    }
    counts.resize(c);
}


int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }


    gen(n);

    vector<int> maxd(n + 1);

    for (int i=1; i<=n; i++) {
       for (int j=pows.size() - 1; j>=0; j--) {
        if (i % pows[j] == 0) {
            counts[j]++;
            maxd[i] = j;
            break;
        }
       }     
    }

    vector<int> res(n);
    vector<int> elim(counts.size());
    int z = 0;
    for (int i=0; i<counts.size(); i++) {
        int lim = counts[i];
        for (int j=0; j<lim; j++) {
            if (z == n - 2) break; 
            res[z++] = pows[i];
            elim[i]++;
        }
        if (z == n - 2) break; 
    }
    vector<int> left(n + 1);
    fill(left.begin(), left.end(), 1);
    for (int i=1; i<=n; i++) {
       int j = maxd[i];
       if (elim[j] > 0) {
           left[i] = 0;
           elim[j]--;
       }
    }

    int a = -1;
    int b = -1;
    for (int i=1; i<=n; i++) {
        if (left[i] == 0) continue;
        if (a == -1) {
            a = i;
            continue;
        }
        if (b == -1) {
            b = i;
            continue;
        }
    }

    
    res[n-2] = __gcd(a, b);
    res[n-1] = max(a, b);

    for (int i=0; i<n-1; i++) {
        cout << res[i] << " ";
    }
    cout << res[n-1] << endl;
}
