#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, C;
    cin >> N >> C;

    vector<int> fs;
    for (int i=0; i<N; i++) {
        int wi;
        cin >> wi;
        fs.push_back(wi);
    }

    int res = 0;
    for (int i=0; i<N; i++) {
        long long sofar = 0;
        int count = 0;
        for (int j=i; j<N; j++) {
            if (sofar + fs[j] <= C) {
                sofar += fs[j]; 
                count++;
            }
        }
        res = max(res, count);
    }
    cout << res << endl;
}
