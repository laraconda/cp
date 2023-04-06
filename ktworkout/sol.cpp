#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int INF = 1e9;
vector<long long> start(N);
vector<pair<long long, long long>> ms(N);
vector<long long> off(N);

priority_queue<long long, vector<long long>, greater<long long>> q;

bool freem(int m, long long t) {
    long long a = ms[m].first + ms[m].second;
    long long moff = start[m] + off[m];
    t -= moff;
    if (t < 0) return true;
    long long b = t/a;
    if (b * a <= t && t < b * a + ms[m].first)
        return false;
    return true;
}

long long getnextb(int m, long long t) {
    long long a = ms[m].first + ms[m].second;
    long long moff = start[m] + off[m];
    t -= moff;
    if (t < 0) return moff;
    long long b = t/a;
    return (b + 1) * a + moff;
}

long long getnextf(int m, long long t) {
    long long a = ms[m].first + ms[m].second;
    long long moff = start[m] + off[m];
    t -= moff;
    if (t < 0) return moff + ms[m].first;
    long long b = t/a;
    long long c1 = (b * a) + ms[m].first;
    long long c2 = ((b + 1) * a) + ms[m].first;
    if (c1 <= t) return c2 + moff;
    else return c1 + moff;
}

int main() {
    vector<pair<long long, long long>> jim;

    for (int i=0; i<N; i++) {
        long long u, r;
        cin >> u >> r;
        jim.push_back({u, r});
    }

    for (int i=0; i < N; i++) {
        long long u, r, t;
        cin >> u >> r >> t;
        ms[i] = {u, r};
        start[i] = t;
    }

    long long ans = -1;
    int m = 0;
    long long endw = -1; // end of the current excercise jim is doing
    long long readyt = -1;  // time when jim is going to be ready
    int lap = 1;
    int state = 0; // jim's state 0: ready, 1: workingout, 2: resting
    long long nextb = getnextb(0, 0);
    cout << "first nextb: " << nextb << endl;
    long long nextf = getnextf(0, 0);
    cout << "start nextf: " << nextf << endl;
    bool free_ = freem(0, 0);
    cout << "first nextb fake: " << start[0] << endl;
    cout << "start nextf fake: " << start[0] + ms[0].first << endl;

    q.push(0);
    q.push(nextb);
    q.push(nextf);

    long long lastt = -1;

    long long moff = 0;
    int off_m = 0;
    while (!q.empty()) {
        long long t = q.top(); q.pop();
        if (t == lastt) continue;  // all t's are unique
        lastt = t;
        // finish
        if (t == endw && lap == 3 && m == 9) {
            ans = t;
            break;
        }
        
        // jim is no longer using machine
        if (t == endw && state == 1) {
            state = 2;
            readyt = t + jim[m].second;
            q.push(readyt);
        }
        
        // jim is using machine and someone is supposed to start using that
        // machine now
        if (t == nextb && state == 1) {
            moff = endw - t;
            off_m = m;
        }

        // jim completed his training on the machine m (this lap)
        // and is ready for the next machine
        if (t == readyt && state == 2) {
            state = 0;
            m++;
            if (m == N) {
                m = 0;
                lap++;
            }

            nextb = getnextb(m, t);
            nextf = getnextf(m, t);

            q.push(nextb);
            q.push(nextf);

            endw = -1;
            readyt = -1;
        }

        free_ = freem(m, t); // checking if the machine m is free at t
        
        // applying offset to the person using machine off_m
        if (moff) {
            off[off_m] += moff;
            moff = 0;
            // cout << "t: " << t << " off[" << off_m << "]: " << off[off_m] << " endw: " << endw << endl;
        }

        // jim starts workingout
        if (state == 0 && free_) {
            state = 1;
            
            endw = t + jim[m].first;
            q.push(endw);
        }
        // cout << "t: " << t << " m: " << m << " free: " << free_ << " endw: " << endw << " readyt: " << readyt << endl;
    }

    cout << ans << endl;
}
