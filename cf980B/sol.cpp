#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k % 2 == 0) {
        cout << "YES" << endl;
        int K;
        for (int i=0; i<4; i++) {
            if (i == 1 || i == 2)
                K = 0;
            for(int j=0; j<n; j++) {
                if (i == 0 || i == 3) {
                    cout << ".";
                } else if (j > 0 && j < n-1){
                    if (K < k/2) {
                        cout << "#";
                        K++;
                    } else {
                        cout << ".";
                    }
                } else {
                    cout << ".";
                }
                if (j == n-1)
                    cout << endl;
            }
        }
    } else if (k <= n-2 && k % 2 != 0){
        cout << "YES" << endl;
        int K;
        for (int i=0; i<4; i++) {
            if (i == 1 || i == 2)
                K = 0;
            for(int j=0; j<n; j++) {
                if (i == 0 || i == 3 || i == 2) {
                    cout << ".";
                } else if (j > 0 && j < n-1){
                    if (j >= n/2 - k/2 && j <= n/2 + k/2) {
                        cout << "#"; 
                    } else 
                        cout << ".";
                
                } else {
                    cout << ".";
                }
                if (j == n-1)
                    cout << endl;
            }
        }

    } else {
        cout << "YES" << endl;
        for (int i=0; i<4; i++) {
            for(int j=0; j<n; j++) {
                if (i == 0 || i == 3) {
                    cout << ".";
                } else if (j > 0 && j < n-1 && i == 2) {
                    if (j <= (k - (n-2))/2 || j >= (n-1) - (k - (n-2))/2) {
                        cout << "#"; 
                    } else {
                        cout << ".";
                    }
                
                } else if (j > 0 && j<n-1 && i == 1) { 
                    cout << "#";
                } else {
                    cout << ".";
                }
                if (j == n-1)
                    cout << endl;
            }
        }
    }
}
