#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        set<int> ns;
        ns.insert(0);
        for (int i=1; i<=sqrt(n); i++) {
           ns.insert(i);
           ns.insert(n/i);
        }

        cout << ns.size() << endl;
        for (auto x : ns) {
            cout << x << " "; 
        }
        cout << endl;
    }

}
