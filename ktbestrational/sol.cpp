#include <bits/stdc++.h>
using namespace std;

struct Frac {
    int p;
    int q;
    double val;
    Frac(int p, int q): p(p), q(q) {
        val = (double)p/q;
    }

    void cVal() {
        val = (double)p/q;
    }

    void Print() {
        cout << p << "/" << q << endl;
    }
};

typedef struct Frac Frac;

void approx(Frac*& f, int M, double x) {
    Frac* low = new Frac(0, 1);
    Frac* high = new Frac(1, 1);
    Frac* med = new Frac(1, 1);

    while (low->q <= M && high->q <= M) {
        med->p = low->p + high->p;
        med->q = low->q + high->q;
        if (med->q > M)
            break;
        med->cVal();

        if (med->val < x) {
            low->p = med->p;
            low->q = med->q;
            low->cVal();
        } else if (med->val > x) {
            high->p = med->p;
            high->q = med->q;
            high->cVal(); 
        } else {
            f->p = med->p; 
            f->q = med->q; 
            f->cVal();
            return;
        }
    }

    if (fabs(low->val - x) < fabs(high->val - x)) {
        f->p = low->p; 
        f->q = low->q; 
        f->cVal();
        return;
    } else {
        f->p = high->p; 
        f->q = high->q; 
        f->cVal();
        return;
    }
} 


int main () {
    int P;
    cin >> P;
    while (P--) {
        int K, M;
        cin >> K >> M;
        double x;
        cin >> x;
        Frac* res = new Frac(1, 1);
        approx(res, M, x);

        cout << K << " ";
        res->Print();
    }
}
