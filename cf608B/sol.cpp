#include <bits/stdc++.h>
using namespace std;


const int MAXN = 200002;
int howmanyz[MAXN];
int howmanyo[MAXN];
int zhere[MAXN];
int ohere[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string a;
    string b;
    cin >> a >> b;

    int n = b.size();
    for (int i=0; i<n; i++) {
        zhere[i] = abs((b[i] - '0') - 0);
        ohere[i] = abs((b[i] - '0') - 1);
    }

    for (int i=0; i<a.size(); i++) {
        if (a[i] == '0') {
            howmanyz[i]++;
            howmanyz[n-a.size() + i + 1]--;
        } else {
            howmanyo[i]++;
            howmanyo[n-a.size() + i + 1]--;
        }
    }
     
    for (int i=1; i<n; i++) {
        howmanyz[i] += howmanyz[i-1];
        howmanyo[i] += howmanyo[i-1];
    }

    long long su = 0;
    for (int i=0; i<n; i++) {
        su += howmanyz[i] * zhere[i];
        su += howmanyo[i] * ohere[i];
    }

    cout << su << endl;
}
