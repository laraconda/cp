#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    bool inf = false;
    int c = 0;
    for (int i=0; i<n-1; i++) {
        if ((a[i] == 2 && a[i+1] == 3) || (a[i] == 3 && a[i+1] == 2)) {
            inf = true;
        } else {
            if ((a[i] == 1 && a[i+1] == 3) || (a[i] == 3 && a[i+1] == 1))
                c += 4;
            if ((a[i] == 1 && a[i+1] == 2) || (a[i] == 2 && a[i+1] == 1))
                c+=3;
        }
    }
    for (int i=0; i<n-2; i++) {
                if (a[i] == 3 && a[i+1] == 1 && a[i+2] == 2) c--;
        
    }
    if (inf) {
        cout << "Infinite" << endl;
    } else {
        cout << "Finite" << endl;
        cout << c << endl; 
    }
}
