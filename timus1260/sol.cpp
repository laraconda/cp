#include <bits/stdc++.h>
using namespace std;


int c[56];
int ctermina[56];
int cterminan1[56];
int cbet[56];


int CTN1(int);

int CT(int i) {
    if (ctermina[i] == 0)
        ctermina[i] = CT(i-1) + CTN1(i-1);
    return ctermina[i];
}

int CTN1(int i) {
    if (i == 1 || i == 2)
        return 0;
    if (cterminan1[i] == 0)
        cterminan1[i] = CT(i-2);
    return cterminan1[i];
}

int CB(int i) {
    if (i == 1)
        return 0;
    if (cbet[i] == 0)
        cbet[i] = CT(i-1) + CB(i-1);
    return cbet[i];
}

int C(int i) {
    if (c[i] == 0)
        c[i] = CT(i) + CB(i-1);
    return c[i];
}


int main() {
    c[1] = 1;
    ctermina[1] = 1;
    cterminan1[1] = 0;
    cbet[1] = 0;
    
    c[2] = 1;
    ctermina[2] = 1;
    cterminan1[2] = 0;
    cbet[2] = 1;
    
    c[3] = 2;
    ctermina[3] = 1;
    cterminan1[3] = 1;
    cbet[3] = 2;

    int n;
    cin >> n;

    for (int i=4; i<=n; i++)
        C(i);        
    


    cout << C(n) << endl;
}
