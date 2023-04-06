#include <bits/stdc++.h>
using namespace std;


int main() {
    int l;
    string n;

    cin >> l;
    cin >> n;

    int m = ceil((double)l/2);
    int mi = m;
    
    if (l % 2 != 0) {
        mi = m-1;
        for (int i=0; i<m; i++) {
            if (n[i] > n[i+mi]) {
                break;
            } else if (n[i] < n[i+mi]) {
                mi = mi + 1;
                break;
            }
        }
    }
    
    if (n[mi] == '0') {
        int next;
        int prev;
        int ii = mi;
        while(n[ii] == '0' && ii < l)
            ii++;
        next = ii;

        ii = mi;
        while(n[ii] == '0' && ii > 0)
            ii--;
        prev = ii;
    
        if (next > l - prev) {
            mi = prev;
            if (prev == 0)
                mi = next; 
        } else if (next < l - prev){
            mi = next;
            if (n[next] == '0')
                mi = prev;
        } else {
            mi = next;
            for (int i=0; i<next; i++) {
                if (n[prev + i] < n[i]) {
                    mi = prev;
                    break;
                } else if (n[prev + i] > n[i]) {
                    mi = next;
                    break;
                }
            }
        }
    }

    vector<int> a;
    vector<int> b;
    vector<int> res;

    for (int i=mi-1; i>= 0; i--)
        a.push_back(n[i] - '0');
    
    for (int i=l-1; i>= mi; i--)
        b.push_back(n[i] - '0');

    for (int i=0; i<max(a.size(), b.size()); i++) {
        res.push_back(0);
        if (i >= a.size())
            a.push_back(0);
        
        if (i >= b.size())
            b.push_back(0);
    }

    int rem = 0;
    for (int i=0; i<max(a.size(), b.size()); i++) {
        int su = a[i] + b[i] + rem;
        res[i] = su % 10;
        rem = su / 10;
    }

    if (rem != 0) {
        string srem = to_string(rem);

        for (int i=srem.size() - 1; i>=0; i--) {
            res.push_back(srem[i] - '0');
        }
    }
    
    for (int i=res.size() - 1; i>0; i--) {
        cout << res[i];
    }
    cout << res[0] << endl;
}
