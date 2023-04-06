#include <bits/stdc++.h>
using namespace std;

const int maxs = 1e6 + 1;

int lives[maxs];
int reach[maxs];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int li;
        cin >> li;
        reach[i] = li;
    }
    
    for (int i=0; i<n; i++) {
        int j = max(i - reach[i], 0);
        lives[j] -= 1;
        lives[i] += 1;
    }
    
    int res = 0;
    if (lives[0] == 0)
        res++;
    for (int i=1; i<n; i++) {
        lives[i] += lives[i-1];
        if (lives[i] == 0)
            res++;
    }
    cout << res << endl;
    return 0;
}
