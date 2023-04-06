#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        int k = 0;
        for (int i=0; i<S.size()/2; i++) {
            int j = S.size() - i - 1;
            if (S[i] != S[j])
                k++;
        }
        cout << "Case #" << t << ": " << max(K, k) - min(K, k) << endl;
    }
    
}
