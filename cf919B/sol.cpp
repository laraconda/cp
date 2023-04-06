#include<bits/stdc++.h>
using namespace std;


bool ten(int x) {
    int su = 0;
    while (x) {
        su += x % 10;
        x /= 10; 
    }
    return (su == 10);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    cin >> k;

    int ks = 0;
    int i=19;
    while (ks < k) {
        if (ten(i))
            ks++;
        i += 9;
    }
    i -= 9;
    cout << i << endl;
}
