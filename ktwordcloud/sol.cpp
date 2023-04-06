#include <bits/stdc++.h>
using namespace std;

int getw(int P, string s) {
    return ceil((double)9/16 * s.size() * P);
}

int getp(int c, int mxc) {
    return 8 + ceil(((double)40 * (c - 4))/(mxc - 4));
}

int main() {
    int W, N;
    int ii = 1;
    while (cin >> W >> N) {
        if (W == 0 && N == 0) break;
        vector<pair<string, int>> ws;
        int mxc = 0;
        for (int i=0; i<N; i++) {
            string s;
            int c;
            cin >> s;
            cin >> c;
            ws.push_back({s, c});
            if (mxc < c) {
                mxc = c;
            }
        }

        int hsofar = 0;
        int wsofar = 0;
        int maxp = 0;
        int wcount = 0;
        for (auto sc : ws) {
            int P = getp(sc.second, mxc);
            int w = getw(P, sc.first);
            int extra = (wcount) ? 10 : 0;
            if (wsofar + w + extra > W) {
                hsofar += maxp;
                maxp = P;
                wsofar = w;
                wcount = 1;
            } else {
                maxp = max(P, maxp);
                wsofar += w + extra;
                wcount++;
            }
        }
        hsofar += maxp;
        cout << "CLOUD " << ii++ << ": " << hsofar << endl;
    }

}
