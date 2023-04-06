#include <bits/stdc++.h>
using namespace std;

const int MAXF = 5;
const int MAXS = 10;

double dp[MAXF][MAXF][MAXF][MAXF][MAXS];


void mfill() {
    for (int a=0; a<MAXF; a++)
        for (int b=0; b<MAXF; b++)
            for (int c=0; c<MAXF; c++)
                for (int d=0; d<MAXF; d++)
                    for (int e=0; e<MAXS; e++)
                        dp[a][b][c][d][e] = -1; 
}


double search(int r, int g, int b, int y, int s) {
    if (dp[r][g][b][y][s] != -1) return dp[r][g][b][y][s];
    double prob = 0;
    if (!(r || g || b || y)) {
        prob = 1;
    } else if (!s) {
        prob = 0;
    } else {
        int n = 6;
        if (r) prob += search(r - 1, g, b, y, s); else n--;
        if (g) prob += search(r, g - 1, b, y, s); else n--;
        if (b) prob += search(r, g, b - 1, y, s); else n--;
        if (y) prob += search(r, g, b, y - 1, s); else n--;
        if (s) prob += search(r, g, b, y, s - 1); else n--;
        
        if (r >= g && r >= b && r >= y) {
            prob += search(r - 1, g, b, y, s);
        } else if (g >= r && g >= b && g >= y) {
            prob += search(r, g - 1, b, y, s);
        } else if (b >= r && b >= g && b >= y) {
            prob += search(r, g, b - 1, y, s); 
        } else if (y >= r && y >= g && y >= b) {
            prob += search(r, g, b, y - 1, s);
        } 
        prob /= n;
    }
    return dp[r][g][b][y][s] = prob;
}



int main() {
    int R, G, B, Y, S;
    cin >> R >> G >> B >> Y >> S;
   
    mfill();
    double res = search(R, G, B, Y, S);
    printf("%2.15f\n", res);
}

