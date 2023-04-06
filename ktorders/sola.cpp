#include <bits/stdc++.h>
using namespace std;

const int MAXV = (3 * 1e4) + 5;

int v[MAXV];  // Maneras de hacer la cantidad
int vs[MAXV]; // Cuando v[i] = 1, vs[i] dice que moneda se uso para llegar a i y asi poder reconstruir el camino
string ss[MAXV]; // string que guarda el resultado cuando v[i] = 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    vector<int> cs;

    int n;
    cin >> n;
    int ci;
    for (int i=0; i<n; i++) {
        cin >> ci;
        cs.push_back(ci);
    }

    v[0] = 1;
    int ii = 1;
    for (int c : cs) {
        for (int j=c; j<MAXV; j++) {
            v[j] += v[j-c];
            v[j] = min(v[j], 2);
            if (v[j-c] == 1 && v[j] == 1)
                vs[j] = ii;
        }
        ii++;
    }

    // Procesamiento que creo podria mejorarse
    // Reconstruyo los caminos de los v[i] = 1
    for (int i=1; i<MAXV; i++) {
        if (v[i] != 1)
            continue;

        int c = cs[vs[i] - 1];
        if (i-c > 0)
            ss[i] += ss[i-c] + " " + to_string(vs[i]);
        else
            ss[i] += to_string(vs[i]);
    }

    int m;
    cin >> m;

    int mi;
    while (m--) {
        cin >> mi;
        
        string res = "";
        if (v[mi] == 0)
            res = "Impossible";
        else if (v[mi] >= 2)
            res = "Ambiguous";
        else
            res = ss[mi];
        cout << res << endl;        
    }
}
