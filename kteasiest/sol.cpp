#include <bits/stdc++.h>
using namespace std;

int MAXN = 1e5 + 3;

int sumd(int n) {
    int s = 0;
    while(n > 0) {
        s += n%10;
        n /= 10;
    }
    return s;
}

int main() {
    
    int n;
    cin >> n;
    while (n > 0) {
        int sd = sumd(n);
        for (int i=11; i<=100; i++) {
            if (sumd(i*n) == sd) {
                cout << i << endl;
                break;
            }
        }
        cin >> n;
    }

}
