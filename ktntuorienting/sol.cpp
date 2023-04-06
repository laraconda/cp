#include <bits/stdc++.h>
using namespace std;

const int MAXC = 204;
const int MAXL = 1004;

struct Lec {
    int ci;
    int si;
    int ei;

    Lec(int ci, int si, int ei): ci(ci), si(si), ei(ei) {}
};

typedef struct Lec Lec;

long long dis[MAXC][MAXC];
int dp[MAXC][MAXL][2];


bool msort(Lec& a, Lec& b) {
    if (a.si < b.si) {
        return true;
    } else if (a.si == b.si) {
        return (a.ei < b.ei); 
    } else {
        return false;
    }
}


void mclean() {
    for (int i=0; i<MAXC; i++)
        for (int j=0; j<MAXL; j++)
            for (int z=0; z<2; z++)
                dp[i][j][z] = -1;
}


long long getdis(int a, int b) {
    if (a == -1) return 0;
    return dis[a][b];
}


int maxlecs(int c, int l, long long t, vector<Lec>& lecs, int& L) {
    if (l == L) return 0;
    if (lecs[l].si >= t + getdis(c, lecs[l].ci)) {
        if (c > -1 && dp[c][l][0] != -1) return dp[c][l][0];
        else {
            int attend = maxlecs(lecs[l].ci, l + 1, lecs[l].ei, lecs, L) + 1;
            int res = max(maxlecs(c, l + 1, t, lecs, L), attend); 
            if (c != -1) return dp[c][l][0] = res; 
            return res;
        } 
    } else {
        if (c > -1 && dp[c][l][1] != -1) return dp[c][l][1];
        int res = maxlecs(c, l + 1, t, lecs, L); 
        if (c != -1)
            return dp[c][l][1] = res; 
        return res;
    }
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        mclean();

        int C, L;
        cin >> C >> L;
        int lim = (C*(C-1))/2;
        for (int i=0; i<lim; i++) {
            int ii, jj, tij;
            cin >> ii >> jj >> tij;
            dis[ii][jj] = tij;
            dis[jj][ii] = tij;
        }

        for (int k=0; k<C; k++)
            for (int i=0; i<C; i++)
                for (int j=0; j<C; j++)
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
        
        vector<Lec> lecs;
        for (int i=0; i<L; i++) {
            int ci, si, ei;
            cin >> ci >> si >> ei;
            lecs.emplace_back(ci, si, ei);
        }

        sort(lecs.begin(), lecs.end(), msort);
        cout << maxlecs(-1, 0, 0, lecs, L) << endl;
        lecs.clear();
    }
}
