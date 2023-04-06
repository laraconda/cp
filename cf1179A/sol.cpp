#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int q;
    cin >> n >> q;

    deque<int> dq;
    vector<pair <int, int> > ab;
    ab.push_back(make_pair(-1, -1));

    int ai;
    for (int i=0; i<n; i++) {
        cin >> ai;
        dq.push_back(ai);
    }

    int A;
    int B;
    for (int i=0; i<n; i++) { 
        A = dq[0];
        B = dq[1];
        
        ab.push_back(make_pair(A, B));

        dq.pop_front();
        dq.pop_front();
        if (A > B) {
            dq.push_back(B);
            dq.push_front(A);
        } else {
            dq.push_back(A);
            dq.push_front(B);
        }
    }

    vector<int> wheel;
    for (int i=1; i<n; i++)
        wheel.push_back(dq[i]);
    
    long long mj;
    int ii;
    while(q--) {
        cin >> mj;
        if (mj <= n) {
            A = ab[mj].first;
            B = ab[mj].second;
        } else {
            mj -= n;
            ii = (mj - 1) % (n-1);
            A = dq[0];
            B = wheel[ii];
        }

        cout << A << " " << B << endl;
    }
}
